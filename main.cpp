#include<random>
#include<stdio.h>
#include<windows.h>

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


typedef void (*PFunc)(int);

void CallBack(int number)
{
	if (number == num(engine)) printf("������I\n");
	else                       printf("�͂���c\n");
}

void Gambling(PFunc p, int number, int second)
{
	second *= 1000;

	Sleep(second);

	p(number);
}

int main()
{
	printf("\n�u�������Łv�@0�L�[:���� 1�L�[:�\n");

	//�֐��|�C���^
	PFunc p = &CallBack;

	//����
	int number = 0;
	scanf_s("%d", &number);

	const int waitTime = 3;
	//�֐�
	Gambling(p, number, waitTime);


	return 0;
}