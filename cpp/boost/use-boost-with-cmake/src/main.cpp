#include <iostream>
#include "boost/polygon/polygon.hpp"

int main()
{
	typedef boost::polygon::point_data<int> Point;
	Point pt(10, 20);
	printf("%d %d\n", pt.x(), pt.y());
}
