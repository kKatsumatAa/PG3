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

	//����
	int number = 0;
	scanf_s("%d", &number);

	//�����_��
	std::function<void()> ShowResult = [=]() { number == num(engine) ? printf("������I\n") : printf("�͂���c\n"); };

	std::function<void(std::function<void()>, int)> SetTimeOut
		= [](std::function<void()> fx, int second) { second *= 1000; Sleep(second); fx(); };

	const int waitTime = 3;
	//�֐�
	SetTimeOut(ShowResult, waitTime);


	return 0;
}