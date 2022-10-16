#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template < class T > class Array
{
private:
	int				_size;
	T				*_array;

public:
	Array(void) : _size(0), _array(NULL) {}
	Array(unsigned int n) : _size(n), _array(new T[_size]) {}
	Array(Array const &array) {
		*this = array;
	}
	~Array(void) {
		if (_array)
			delete[] _array;
	}
	Array const		&operator = (Array const &array){
		if (this == &array)
    	    return (*this);
    	delete [] _array;
    	_array = array.getArray();
    	_size = array.size();
    	return (*this);
	}
	T				&operator [] (int index) const {
		if (_array && index >= 0 && index < _size)
			return (_array[index]);
		throw (Sega());
	}

	int				size(void) const {
		return (_size);
	}
	T				*getArray(void) const {
		T   *array = new T[_size];

		for (int i=0; i < _size; ++i)
    	    array[i] = _array[i];
    	return (array);
	}

	class Sega : public std::exception
	{
	public:
		virtual char const	*what(void) const throw() {
			return ("\n\nmy segfault\n");
		}
	};
};

#endif
