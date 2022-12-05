#pragma once

class Enemy
{
private:
	//�����o�֐��|�C���^�e�[�u��
	static void (Enemy::* spFuncTable[])();

	//�s���t�F�[�Y
	static enum class Phase
	{
		MeleeAttack,
		Shot,
		Secession
	};
	//�t�F�[�Y
	Phase phase_ = Phase::MeleeAttack;

	void MeleeAttack();
	void Shot();
	void Secession();

public:
	void Update();
	void Draw();
};

