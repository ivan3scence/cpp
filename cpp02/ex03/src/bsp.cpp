#include "Point.hpp"

float sign (Point p1, Point p2, Point p3)
{
	Fixed	sign;

	sign = (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX()
			- p3.getX()) * (p1.getY() - p3.getY());
	return (sign.toFloat());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
    float d1, d2, d3;

    d1 = sign(point, a, b);
    d2 = sign(point, b, c);
    d3 = sign(point, c, a);
    return ((d1 < 0 && d2 < 0 && d3 < 0) || (d1 > 0 && d2 > 0 && d3 > 0));
}

