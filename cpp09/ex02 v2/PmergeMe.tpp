/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodde <jodde@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:34:47 by jodde             #+#    #+#             */
/*   Updated: 2026/06/27 14:31:04 by jodde            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"
#include <limits> 
#include <algorithm>

////////////// out of class function
void	logError(std::string message)
{
	std::string msg = "ERROR -" + message;
	std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}

//////////////// PmergeMe class
template <template<class, class> class Container>
PmergeMe<Container>::PmergeMe(std::string& arg){ initSort(arg); }

template <template<class, class> class Container>
PmergeMe<Container>::PmergeMe(PmergeMe const& src){*this = src;}

template <template<class, class> class Container>
PmergeMe<Container>::~PmergeMe(){}

template <template<class, class> class Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& src){ this->_cont = src._cont; this-> _execTime = src._execTime; return (*this);}

//member functions
template <template<class, class> class Container>
void	PmergeMe<Container>::initSort(std::string& arg) 
{
	std::istringstream iss(arg);
	long nb;

	while(iss >> nb)
	{
		if (nb < 0 || nb > std::numeric_limits<unsigned int>::max())
			throw (std::logic_error("invalid arg format : only unsigned int authorized"));
		_cont.push_back(static_cast<unsigned int>(nb));
	}
	if (!(iss.eof()))
		throw (std::logic_error("invalid arg format"));
	_execTime = clock();
	sortNum(_cont);
	_execTime = clock() - _execTime;
}

template <template<class, class> class Container>
std::vector<unsigned int> PmergeMe<Container>::generateJacob(size_t pend_size)
{
	std::vector<unsigned int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < static_cast<unsigned int>(pend_size))
   		jacob.push_back(jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2]);
	return jacob;
}

template <template<class, class> class Container>
bool	PmergeMe<Container>::isSorted(container_type& cont)
{
	if (cont.size() < 2)
   		return (true);
	typename container_type::iterator it = cont.begin();
	typename container_type::iterator next = it;
	++next;
	while(next != cont.end())
	{
		if (*it > *next)
		{
			std::cout << false <<std::endl;
			return (false);
		}
		++it;
		++next;
	}
	std::cout << true <<std::endl;
	return (true);
}

template <template<class, class> class Container>
int PmergeMe<Container>::binarySearch(container_type &arr, int low, int high, unsigned int x) 
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[static_cast<size_t>(mid)] < x)
            low = mid + 1;
		else
			high = mid -1;
   }
  return low;
}

template <template<class, class> class Container>
void	PmergeMe<Container>::insert(container_type &pend, container_type &main, std::vector<std::pair<unsigned int, unsigned int> >& pairs)
{
	std::vector<unsigned int> jacob = generateJacob(pend.size());

    int k = 1;
	{
		int bound = binarySearch(main, 0, static_cast<int>(main.size()) - 1, pairs[0].second);
		int pos = binarySearch(main, 0, bound, pend[0]);
		main.insert(main.begin() + pos, pend[0]);
	}
    while (k < static_cast<int>(jacob.size()) - 1)
    {
        size_t sk = static_cast<size_t>(k);
        int group_end   = static_cast<int>(std::min(jacob[sk + 1], static_cast<unsigned int>(pend.size()))) - 1;
        int group_start = static_cast<int>(jacob[sk]); // exclus, on part de group_end vers group_start+1
        for (int i = group_end; i >= group_start; i--)
        {
			int	pos;
			size_t si = static_cast<size_t>(i);
            if (i >= static_cast<int>(pend.size()))
                continue;
			if (i >= static_cast<int>(pairs.size()))
				pos = binarySearch(main, 0, static_cast<int>(main.size()) - 1, pend[si]);
			else
			{
				int bound = binarySearch(main, 0, static_cast<int>(main.size()) - 1, pairs[si].second);
				pos = binarySearch(main, 0, bound, pend[si]);
			}
            main.insert(main.begin() + pos, pend[si]);
        }
        k++;
    }
}

template <template<class, class> class Container>
void	PmergeMe<Container>::sortNum(container_type& data)
{
	if (data.size()	<= 1)
		return;
	size_t 	i = 0;
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	container_type pend;
	container_type main;
	bool	is_odd = ((data.size() % 2));
	while (i < data.size())
	{
		if (is_odd && i == (data.size() - 1))
		{
			pend.push_back(data[i]);
			break;
		}
		if (data[i] > data [i + 1])
			std::swap(data[i], data[i + 1]);
		pairs.push_back(std::make_pair (data[i], data[i + 1]));
		pend.push_back(data[i]);
		main.push_back(data[i + 1]);
		i += 2;
	}
	sortNum(main);
	insert(pend, main, pairs);
	data = main;
}
template <template<class, class> class Container>
void	PmergeMe<Container>::displayNum()
{
	std::cout <<"vector content : [ ";
	for (typename container_type::iterator it = _cont.begin(); it != _cont.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << "time to sort the vector : " << static_cast<float>(_execTime)/CLOCKS_PER_SEC << "seconds" << std::endl;	
}

template <template<class, class> class Container>
void	PmergeMe<Container>::displayNum(container_type& vec)
{
	std::cout <<"[ ";
	for (typename container_type::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
}

template <template<class, class> class Container>
void	PmergeMe<Container>::displayPairs(std::vector<std::pair<unsigned int, unsigned int> > const& vec)
{
	std::cout <<"[ ";
	for (std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << "< " << it->first << ", " << it->second << " >";
	std::cout << "]" << std::endl;
}
