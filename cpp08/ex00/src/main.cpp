#include "easyfind.hpp"
#include <vector>

int main( void ) {
	 std::vector<int> v(3,3);
    int n1 = 3;
    int n2 = 22;
 
    std::vector<int>::iterator result1 = easyfind(v, n1);
	std::vector<int>::iterator result2 = easyfind(v, 22);
 

	if (result1 != v.end())
		std::cout << "v contains " << n1 << '\n';
	else
        std::cout << "v does not contain " << n1 << '\n';
 
    if (result2 != v.end())
        std::cout << "v contains " << n2 << '\n';
	else
		std::cout << "v does not contain " << n2 << '\n';
 
}
