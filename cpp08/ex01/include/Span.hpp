#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <climits>

class Span
{
private:
	size_t				_size;
	size_t				_quant;
	std::vector<int>	_vec;
	Span(void);

public:
	Span(size_t const &size);
	Span(Span const &span);
	~Span(void);
	Span operator = (Span const &span);

	size_t				size(void) const;
	size_t				getSize(void) const;
	std::vector<int>	getVector(void) const;
	void				addNumber(int number);
	long				shortestSpan(void) const;
	int					longestSpan(void) const;
	template < typename T > void	addNumbers(typename T::iterator begin,
												typename T::iterator end);

	class TooMuchNumbers : public std::exception
	{
	public:
		virtual char const	*what(void) const throw() {
			return ("Error! Too much numbers!");
		}
	};
	class TooFewNumbers : public std::exception
	{
	public:
		virtual char const	*what(void) const throw() {
			return ("Error! Too few numbers!");
		}
	};
};
template < typename T >
void    Span::addNumbers(typename T::iterator begin, typename T::iterator end)
{
    typename T::iterator    cp = begin;

    while (cp != end)
	{
		try
		{
			addNumber(*(cp++));
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
#endif
