#include "Span.hpp"

Span::Span(void) : _size(0), _quant(0) {}

Span::Span(size_t const &size) : _size(size), _quant(0) {}

Span::~Span(void) {}

Span::Span(Span const &span)
{
	*this = span;
}

Span	Span::operator = (Span const &span)
{
	if (this == &span)
		return (*this);
	_size = span.getSize();
	_quant = span.size();
	_vec.clear();
	_vec = span.getVector();
	return (*this);
}

size_t	Span::getSize(void) const
{
	return (_quant);
}

size_t	Span::size(void) const
{
	return (_quant);
}

std::vector<int>	Span::getVector(void) const
{
	return (_vec);
}

void	Span::addNumber(int number)
{
	if (_quant >= _size)
		throw (TooMuchNumbers());
	_vec.push_back(number);
	++_quant;
}

long	Span::shortestSpan(void) const
{
	if (_quant < 2)
		throw (TooFewNumbers());
	long				span = LONG_MAX;
	std::vector<int>	cp = _vec;

	sort(cp.begin(), cp.end());
	for (size_t i=0; i + 1 < cp.size(); ++i)
		span = std::min(span, static_cast<long>(cp[i + 1] - cp[i]));
	return (span);
}

int		Span::longestSpan(void) const
{
	if (_quant < 2)
		throw (Span::TooFewNumbers());
	return (*std::max_element(_vec.begin(), _vec.end())
			- *std::min_element(_vec.begin(), _vec.end()));
}
