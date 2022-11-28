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

	//�}���p�v�f�ԍ�
	int num = 0;
	//�}���p
	char insertStr[128];
	//���Ԏw��p
	int order[100];

public:
	CellManager();
	~CellManager();

	void Update();
	void Draw();

	CELL* GetCell() { return cell; }
	int* GetNum() { return &num; }
	int* GetOrder() { return order; }
	const char* GetInsertStr() { return insertStr; }

	void SetNum(int num) { this->num = num; }
	void SetInsertStr(const char* str) { strcpy_s(insertStr, str); }

	//�I�[�_�[���N���A
	void ClearOrder();

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