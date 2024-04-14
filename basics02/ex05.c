#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ex05.h"

// struct point
// {
// 	int x;
// 	int y;
// };

typedef struct circle
{
	point p;
	double radius;
} circle;

// void point_test()
// {
// 	struct point p1, p2;
	
// 	p1.x = 10;
// 	p1.y = 20;

// 	p2.x = 100;
// 	p2.y = 200;
// }

double circle_area(circle c)
{
	return  M_PI * c.radius * c.radius;
}

void circle_test()
{
    circle c1 = { 10, 10, 5 };
    circle c2 = { { 20, 20 }, 5 };
    
    printf("원 c1(x : %d, y: %d, radius: %f, %f)\n", c1.p.x, c1.p.y, c1.radius, circle_area( c1 ) );
    printf("원 c2(x : %d, y: %d, radius %f )\n", c2.p.x, c2.p.y, c2.radius);
}

int main()
{
//	point_test();
	circle_test();
	return 0;
}
