#include<random>
#include<stdio.h>
#include<windows.h>
#include<functional>

enum NUMBER
{
	EVEN_NUMBER,
	ODD_NUMBER
};

//乱数シード生成器
static std::random_device seed_gen;
//メルセンヌツイスター
static std::mt19937_64 engine(seed_gen());
//乱数範囲
static std::uniform_int_distribution<int> num(EVEN_NUMBER, ODD_NUMBER);

int main()
{
	printf("\n「丁半博打」0キー:偶数 1キー:奇数\n");

	//ラムダ式
	std::function<void(int)> ShowResult = [](int number)
	{
		if (number == num(engine)) printf("当たり！\n");
		else                       printf("はずれ…\n");
	};

	std::function<void(std::function<void(int)>, int, int)> Gambling
		= [](std::function<void(int)> fx, int number, int second)
	{
		second *= 1000;

		Sleep(second);

		fx(number);
	};


	//入力
	int number = 0;
	scanf_s("%d", &number);

	const int waitTime = 3;
	//関数
	Gambling(ShowResult, number, waitTime);


	return 0;
}