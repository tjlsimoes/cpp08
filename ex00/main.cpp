#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <list>

int	main(void)
{
	std::vector<int> v(3, 3);
	std::cout << easyfind(v, 3) << std::endl;

	// std::list<int> l(2, 3);
	// std::cout << easyfind(l, 3) << std::endl;

	// try
	// {
	// 	easyfind(v, 4);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	return (0);
}