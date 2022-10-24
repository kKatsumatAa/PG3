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
	//時給
	const int recursiveWage = 100;
	const int wage = 1072;

	int recursiveTortal = 0;
	int normalTortal = 0;

	//時間
	int hour = 0;


	while (true)
	{
		hour++;

		//比較して、再帰的な方が儲かったら抜ける
		if (RecursiveWage(hour, recursiveWage) > wage * hour)
		{
			recursiveTortal = RecursiveWage(hour, recursiveWage);
			normalTortal = wage * hour;

			//抜ける
			break;
		}
	}

	printf("%d時間働いたら再帰的な時給が儲かる\n再帰的な時給の合計:%d\n普通の時給の合計:%d\n", hour, recursiveTortal, normalTortal);

	return 0;
}