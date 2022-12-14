#include<stdio.h>

template<typename Type>
Type Min(Type a, Type b)
{
	if (a <= b) { return a };

	return b;
}

//char型の時
template<>
char Min(char a, char b)
{
	printf("数字以外は代入できません\n");

	return 0;
}


int main()
{
	int a = 1, b = 2;

	float af = 3.0f, bf = 1.0f;

	double ad = -1.0, bd = -10.0;

	char ac = 'a', bc = 'b';

	//処理
	printf("%d\n", Min<int>(a, b));

	printf("%f\n", Min<float>(af, bf));

	printf("%lf\n", Min<double>(ad, bd));

	Min<char>(ac, bc);
	

	return 0;
}