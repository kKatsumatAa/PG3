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

	//入力
	int number = 0;
	scanf_s("%d", &number);

	//ラムダ式
	std::function<void()> ShowResult = [=]() { number == num(engine) ? printf("当たり！\n") : printf("はずれ…\n"); };

	std::function<void(std::function<void()>, int)> SetTimeOut
		= [](std::function<void()> fx, int second) { second *= 1000; Sleep(second); fx(); };

	const int waitTime = 3;
	//関数
	SetTimeOut(ShowResult, waitTime);


	return 0;
}