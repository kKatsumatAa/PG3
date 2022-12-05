#include "Enemy.h"
#include <stdio.h>
#include <Windows.h>
#include <iostream>


void Enemy::Update()
{
	(this->*spFuncTable[static_cast<size_t>(phase_)])();
}

void Enemy::Draw()
{
}

//-------------------------------------------------------------
void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::MeleeAttack,
	&Enemy::Shot,
	&Enemy::Secession
};

void Enemy::MeleeAttack()
{
	std::system("cls");
	printf("�ߐ�");

	Sleep(3 * 1000);

	phase_ = Enemy::Phase::Shot;
}

void Enemy::Shot()
{
	std::system("cls");
	printf("�ˌ�");

	Sleep(3 * 1000);

	phase_ = Enemy::Phase::Secession;
}

void Enemy::Secession()
{
	std::system("cls");
	printf("���E");

	Sleep(3 * 1000);

	phase_ = Enemy::Phase::MeleeAttack;
}


