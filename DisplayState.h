#pragma once
#include"CellManager.h"

//�ꗗ�\��
class AllDisplay : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//���Ԃ��w��
class OrderDisplay : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};