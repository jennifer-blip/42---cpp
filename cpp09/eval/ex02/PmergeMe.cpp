#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& other): _vec(other._vec), _deq(other._deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	if (this != &other){
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}
PmergeMe::~PmergeMe(){}

// This is the merge-insert sorting. 
//F(n), or the JacobsthalSequence is the number of comparisons required to sort n elements by merge-insertion.
//J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2*J(n-2)
//the indices 1, 3, 5, 11, 21 ... up to n
std::vector<int>	PmergeMe::jacobsthalSequence(int n){
	std::vector<int> seq;
	if (n <= 0) return seq;
	seq.push_back(1);
	int	a = 1; //J(1)
	int b = 3; //J(3) 
	int	tmp;
	while (b <= n){
		seq.push_back(b);
		tmp = b + 2 * a;
		a = b;
		b = tmp;
	}
	return seq;
}

void	PmergeMe::parseInput(int argc, char** argv){
	for (int i = 1; i < argc; i++){
		std::istringstream	iss(argv[i]);
		long	n;
		char	leftover;
		if (!(iss >> n) || (iss >> leftover))
			throw std::runtime_error("invalid input: " + std::string(argv[i]));
		if (n <= 0)
			throw std::runtime_error("only positive integers allowed");
		_vec.push_back(static_cast<int>(n));
		_deq.push_back(static_cast<int>(n));
	}
}

void	PmergeMe::mergeInsertVector(std::vector<int>& v){
	if (v.size() <= 1) return;
	std::vector<int>	main_chain, pending;
	bool	hasOdd = (v.size() % 2 != 0);
	int	odd = hasOdd ? v.back() : 0;
//pairwise comparisons, larger ones go to the main chain and smaller ones go to the pending
	for (size_t	i = 0; i + 1 < v.size(); i += 2){
		if (v[i] > v[i+1]){
			main_chain.push_back(v[i]);
			pending.push_back(v[i+1]);
		} else {
			main_chain.push_back(v[i+1]);
			pending.push_back(v[i]);
		}
	}
//call the function itself, recursive sorting for the main_chain
	mergeInsertVector(main_chain);
//deal with the pending vectors, first of all, we know pending[0] < main_chain[0]
// the lower bound function returns the position of the first element >= pending[0];
	main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), pending[0]), pending[0]);
//vector jacobsthal tells us which element to insert first from the pending sequence.
	if (pending.size() > 1)
	{
		std::vector<int> jac = jacobsthalSequence(static_cast<int>(pending.size()) - 1);
		std::vector<bool> inserted(pending.size(), false);
		inserted[0] = true;

		for (size_t ji = 0; ji < jac.size(); ji++){
			int	idx = jac[ji];
			if (idx < (int)pending.size() && !inserted[idx]){
				main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), pending[idx]), pending[idx]);
				inserted[idx] = true;
			}
		}
		for (size_t i = 0; i < pending.size(); i++){
			if (!inserted[i]){
				main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), pending[i]), pending[i]);
				inserted[i] = true;
			}
		}
	}
	if (hasOdd){
		main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), odd), odd);
	}
	v = main_chain;
}

void	PmergeMe::mergeInsertDeque(std::deque<int>& d)
{
	if (d.size() <= 1) return;
	std::deque<int>	main_chain, pending;
	bool	hasOdd = (d.size() % 2 != 0);
	int	odd = hasOdd ? d.back() : 0;
	size_t	idx;

	for (size_t i = 0; i + 1 < d.size(); i += 2){
		if (d[i] >= d[i+1]){
			main_chain.push_back(d[i]);
			pending.push_back(d[i+1]);
		}
		else{
			main_chain.push_back(d[i+1]);
			pending.push_back(d[i]);
		}
	}
	mergeInsertDeque(main_chain); //main_chain is now sorted
	main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), pending[0]), pending[0]);
	if (pending.size() > 1)
	{
		std::vector<int>	jac = jacobsthalSequence(pending.size() - 1);
		std::vector<bool>	inserted(pending.size(), false);
		inserted[0] = true;

		for (size_t ji = 0; ji < jac.size(); ji++){
			idx = jac[ji];
			if (idx < pending.size() && !inserted[idx]){
				main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), pending[idx]), pending[idx]);
				inserted[idx] = true;
			}
		}
		for (size_t i = 1; i < pending.size(); i++){
			if (!inserted[i])
				main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), pending[i]), pending[i]);
		}
	}
	if (hasOdd){
			main_chain.insert(std::lower_bound(main_chain.begin(), main_chain.end(), odd), odd);
	}
	d = main_chain;
} 

void	PmergeMe::run(int ac, char **av){
	parseInput(ac, av);
	printContainer("Before: ", _vec);

	std::vector<int> vecCopy(_vec);
	clock_t	startVec = clock();
	mergeInsertVector(vecCopy);
	clock_t	endVec = clock();
	double	timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	std::deque<int>	deqCopy(_deq);
	clock_t	startDeq = clock();
	mergeInsertDeque(deqCopy);
	clock_t	endDeq = clock();
	double	timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;
	printContainer("After: ", vecCopy);
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << timeVec << "us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << timeDeq << "us" << std::endl;

	bool	match = true;
	if (vecCopy.size() != deqCopy.size())
		match = false;
	else{
		for (size_t i = 0; i < vecCopy.size(); i++){
			if (vecCopy[i] != (int)deqCopy[i]){
				match = false;
				break;
			}
		}
	}
	if (!match)
		std::cerr << "Warning: vector and deque results differ!" << std::endl;
}