#pragma once
#include "Cell.h"

class CellManager;

class CellState
{
protected:
	CellManager* cellManager = nullptr;

public:
	void SetCellManager(CellManager* cellManager);
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

class CellManager
{
private:
	CellState* cellState = nullptr;
	CELL* cell = nullptr;

	//�}���p
	int num = 0;
	int insertNum = 0;

public:
	CellManager();
	~CellManager();

	void Update();
	void Draw();

	CELL* GetCell() { return cell; }
	int* GetNum() { return &num; }
	int* GetInsertNum() { return &insertNum; }

	void SetNum(int num) { this->num = num; }
	void SetInsertNum(int num) { this->insertNum = num; }

	void ChangeState(CellState* cellState);
};



//--------------------------------------------------
//�������
class InitialState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//---------------------------------------------------
//�v�f�̕\��
class DisplayState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//----------------------------------------------------
//�v�f�̕ҏW
class EditState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//-----------------------------------------------------
//�v�f�̑}��
class InsertState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//------------------------------------------------------
//�v�f�̍폜
class DeleteState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};