#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
private:
	std::vector<int>	_vec;
	unsigned int		_size;

public:
	Span(void);
	Span(unsigned int size);
	Span(Span const &span);
	~Span(void);
	Span operator = (Span const &span);

	unsigned int	size(void) const;
	std::vector<int>	getVector(void) const;
	void				addNumber(int number);
	int					shortestSpan(void) const;
	int					longestSpan(void) const;

	class TooMuchNumbers : std::exception
	{
	public:
		virtual char const	*what(void) const throw() {
			return ("Error! Too much numbers!");
		}
	};
	class TooFewNumbers : std::exception
	{
	public:
		virtual char const	*what(void) const throw() {
			return ("Error! Too much numbers!");
		}
	};
};

#endif
