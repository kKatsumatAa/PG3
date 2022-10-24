#include <stdio.h>
#include<iostream>
#include<list>

int RecursiveWage(int n, int recursiveWage)
{
	if (n <= 0) return 0;

	return recursiveWage + RecursiveWage(n - 1, recursiveWage * 2 - 50);
}

int main()
{
	//����
	const int recursiveWage = 100;
	const int wage = 1072;

	int recursiveTortal = 0;
	int normalTortal = 0;

	//����
	int hour = 0;


	while (true)
	{
		hour++;

		//��r���āA�ċA�I�ȕ����ׂ������甲����
		if (RecursiveWage(hour, recursiveWage) > wage * hour)
		{
			recursiveTortal = RecursiveWage(hour, recursiveWage);
			normalTortal = wage * hour;

			//������
			break;
		}
	}

	printf("%d���ԓ�������ċA�I�Ȏ������ׂ���\n�ċA�I�Ȏ����̍��v:%d\n���ʂ̎����̍��v:%d\n", hour, recursiveTortal, normalTortal);

	return 0;
}