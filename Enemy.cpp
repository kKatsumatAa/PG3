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
		printf("%d番生きてます,", num);
	}
	else
	{
		printf("%d番死んでます,", num);
	}
}