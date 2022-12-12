#include "Rectangle.h"

Rectangle::Rectangle(float width, float height) :
	width(width), height(height) {};

float Rectangle::size()
{
	return width * height;
}

void Rectangle::Draw()
{
	printf("��`:�ʐ� %f \n", size());
}
