#include "Enemy.h"
#include <stdio.h>

bool Enemy::isAlive = true;

void Enemy::Initialize(const int num)
{
	this->num = num;
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	if (isAlive)
	{
		printf("%d�Ԑ����Ă܂�,", num);
	}
	else
	{
		printf("%d�Ԏ���ł܂�,", num);
	}
}