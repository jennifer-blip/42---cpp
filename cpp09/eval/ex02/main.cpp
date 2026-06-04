#include "PmergeMe.hpp"



int	main(int ac, char** av){
	if (ac < 2){
		std::cerr << "Usage: ./PmergeMe <num1> <num2> ..."  << std::endl;
		return 1;
	}
	try {
		PmergeMe	sorter;
		sorter.run(ac, av);
	} catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}