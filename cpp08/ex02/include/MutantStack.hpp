#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <algorithm>
# include <stack>
# include <iostream>

template < typename T >
class MutantStack: public std::stack<T>
{
public:
	MutantStack(void) : std::stack<T>() {}
	MutantStack(MutantStack const &m) : std::stack<T>(m) {*this = m;}
	MutantStack(std::stack<T> const &m) : std::stack<T>(m) {*this = m;}
	~MutantStack(void) {}
	MutantStack		&operator = (MutantStack const &mstack);

	typedef typename MutantStack<T>::stack::container_type::iterator
		iterator;
	iterator	begin(void);
	iterator	end(void);

	typedef typename MutantStack<T>::stack::container_type::const_iterator
		const_iterator;
	const_iterator	begin(void) const;
	const_iterator	end(void) const;

	typedef typename MutantStack<T>::stack::container_type::reverse_iterator
		reverse_iterator;
	reverse_iterator	rbegin(void);
	reverse_iterator	rend(void);

	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator
		const_reverse_iterator;
	const_reverse_iterator	rbegin(void) const;
	const_reverse_iterator	rend(void) const;

};

template<typename T>
MutantStack<T>      &MutantStack<T>::operator = (MutantStack const &mstack)
{
    if (this == &mstack)
        return (*this);
    this->c = mstack.c;
    return (*this);
}

template<typename T>
typename MutantStack<T>::stack::container_type::iterator
											MutantStack<T>::begin(void)
{
    return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::stack::container_type::iterator
											MutantStack<T>::end(void)
{
    return (this->c.end());
}

template<typename T>
typename MutantStack<T>::stack::container_type::const_iterator
											MutantStack<T>::begin(void) const
{
    return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::stack::container_type::const_iterator
											MutantStack<T>::end(void) const
{
    return (this->c.end());
}

template<typename T>
typename MutantStack<T>::stack::container_type::reverse_iterator
											MutantStack<T>::rbegin(void)
{
    return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::stack::container_type::reverse_iterator
											MutantStack<T>::rend(void)
{
    return (this->c.rend());
}

template<typename T>
typename MutantStack<T>::stack::container_type::const_reverse_iterator
											MutantStack<T>::rbegin(void) const
{
    return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::stack::container_type::const_reverse_iterator
											MutantStack<T>::rend(void) const
{
    return (this->c.rend());
}

#endif

