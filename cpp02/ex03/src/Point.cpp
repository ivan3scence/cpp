#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	return ;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	return ;
}

Point::Point(const Point &point)
{
	_x = point.getX();
	_y = point.getY();
}

Point::~Point(void)
{
	return ;
}

Fixed	Point::getY(void) const
{
	return (_y);
}

Fixed	Point::getX(void) const
{
	return (_x);
}

Point	&Point::operator = (const Point &point)
{
	if (this == &point)
		return (*this);
	_x = point.getX();
	_y = point.getY();
	return (*this);
}

