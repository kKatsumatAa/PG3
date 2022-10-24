#include<random>
#include<stdio.h>
#include<windows.h>

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


typedef void (*PFunc)(int);

void CallBack(int number)
{
	if (number == num(engine)) printf("当たり！\n");
	else                       printf("はずれ…\n");
}

void Gambling(PFunc p, int number, int second)
{
	second *= 1000;

	Sleep(second);

	p(number);
}

int main()
{
	printf("\n「丁半博打」　0キー:偶数 1キー:奇数\n");

	//関数ポインタ
	PFunc p = &CallBack;

	//入力
	int number = 0;
	scanf_s("%d", &number);

	const int waitTime = 3;
	//関数
	Gambling(p, number, waitTime);


	return 0;
}