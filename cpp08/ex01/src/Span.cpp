#include "Span.hpp"

Span::Span(void) : _size(0) {}

Span::Span(unsigned int size)
{
	if (size < 0)
		throw (TooMuchNumbers());
	_size = size;
}
Span::~Span(void) {}

Span::Span(Span const &span)
{
	*this = span;
}

Span	Span::operator = (Span const &span)
{
	if (this == &span)
		return (*this);
	_size = span.size();
	_vec = span.getVector();
	return (*this);
}

unsigned int	Span::size(void) const
{
	return (_size);
}

std::vector<int>	Span::getVector(void) const
{
	return (_vec);
}

void	Span::addNumber(int number)
{
	if (_vec.size() >= _size)
		throw (TooMuchNumbers());
	_vec.push_back(number);
	++_size;
}

int		Span::shortestSpan(void) const
{
	return (9);
}

int		Span::longestSpan(void) const
{
	return (*std::max_element(_vec.begin(), _vec.end())
			- *std::min_element(_vec.begin(), _vec.end()));
}
