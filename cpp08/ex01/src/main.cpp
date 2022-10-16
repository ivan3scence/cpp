#include "Span.hpp"
#include <vector>

int main()
{
	//Span sp = Span(5);
	//sp.addNumber(6);
	//sp.addNumber(3);
	//sp.addNumber(17);
	//sp.addNumber(9);
	//sp.addNumber(11);
	//std::cout << sp.shortestSpan() << std::endl;
	//std::cout << sp.longestSpan() << std::endl;

#define SIZE 10

	{
		Span b(SIZE);
		std::vector<int>	vec;

		for (int i=0; i < SIZE; ++i)
			vec.push_back(i);
		b.addNumbers< std::vector<int> >(vec.begin(), vec.end());
		vec = b.getVector();
		for (size_t i = 0; i < b.getQuantity(); ++i)
			std::cout << vec[i] << std::endl;
		std::cout << "\nshortest span: " << b.shortestSpan()
					<< "\nlongest span: " << b.longestSpan() << std::endl;
	}

	{
		Span b(SIZE);
		std::vector<int>	vec;
	
		for (int i=0; i < SIZE + 1; ++i)
			vec.push_back(i);
		std::cout << "dfd\n";
		b.addNumbers< std::vector<int> >(vec.begin(), vec.end());
		vec = b.getVector();
		for (size_t i = 0; i < b.getQuantity(); ++i)
			std::cout << vec[i] << std::endl;
	}
}
