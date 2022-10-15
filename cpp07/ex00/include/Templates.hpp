#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>

template < typename T >
void	swap(T &x, T &y)
{
	T	tmp(y);

	y = x;
	x = tmp;
}

template < typename T >
T	&min(T &x, T &y)
{
	if (x < y)
		return (x);
	return (y);
}

template < typename T >
T	&max(T &x, T &y)
{
	if (x > y)
		return (x);
	return (y);
}

#endif
