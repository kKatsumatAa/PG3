#include<random>
#include<stdio.h>
#include<windows.h>
#include<functional>

enum NUMBER
{
	EVEN_NUMBER,
	ODD_NUMBER
};

//�����V�[�h������
static std::random_device seed_gen;
//�����Z���k�c�C�X�^�[
static std::mt19937_64 engine(seed_gen());
//�����͈�
static std::uniform_int_distribution<int> num(EVEN_NUMBER, ODD_NUMBER);

int main()
{
	printf("\n�u�������Łv0�L�[:���� 1�L�[:�\n");

	//�����_��
	std::function<void(int)> ShowResult = [](int number)
	{
		if (number == num(engine)) printf("������I\n");
		else                       printf("�͂���c\n");
	};

	std::function<void(std::function<void(int)>, int, int)> Gambling
		= [](std::function<void(int)> fx, int number, int second)
	{
		second *= 1000;

		Sleep(second);

		fx(number);
	};


	//����
	int number = 0;
	scanf_s("%d", &number);

	const int waitTime = 3;
	//�֐�
	Gambling(ShowResult, number, waitTime);


	return 0;
}