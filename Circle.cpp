#include "Circle.h"

Circle::Circle(float r) :
	r(r) {};

float Circle::size()
{
	return r * r * pi;
}

void Circle::Draw()
{
	printf("�~:�ʐ� %f \n", size());
}
