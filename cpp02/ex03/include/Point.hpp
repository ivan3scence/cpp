#ifndef __POINT_H__
#define __POINT_H__

# include <iostream>
# include <cmath>

# include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(const Point &point);
	~Point(void);
	Point(const float x, const float y);

	Point	&operator = (const Point &fix);

	Fixed		getX(void) const;
	Fixed		getY(void) const;
private:
	Fixed		_x;
	Fixed		_y;
};

std::ostream	&operator << (std::ostream &os, const Point &fix);
bool	bsp( Point const a, Point const b, Point const c, Point const point);
#endif
