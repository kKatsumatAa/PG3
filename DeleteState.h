#pragma once
#include"CellManager.h"

//要素があるとき1
class DeleteState2 : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//要素がないとき
class DeleteState3 : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};