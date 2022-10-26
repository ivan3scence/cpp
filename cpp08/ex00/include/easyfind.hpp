#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <algorithm>
# include <iostream>

template < typename T >
typename T::iterator		easyfind(T &elem, int n)
{
	return (std::find(elem.begin(), elem.end(), n));
}

#endif
