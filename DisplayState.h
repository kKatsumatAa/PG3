#pragma once
#include"CellManager.h"

//一覧表示
class AllDisplay : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//順番を指定
class OrderDisplay : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};