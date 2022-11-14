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

public:
	CellManager();
	~CellManager();

	void Update();
	void Draw();

	CELL* GetCell() { return cell; }

	void ChangeState(CellState* cellState);
};



//--------------------------------------------------
//‰Šú‰æ–Ê
class InitialState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//---------------------------------------------------
//—v‘f‚Ì•\¦
class DisplayState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//----------------------------------------------------
//—v‘f‚Ì•ÒW
class EditState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//-----------------------------------------------------
//—v‘f‚Ì‘}“ü
class InsertState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//------------------------------------------------------
//—v‘f‚Ìíœ
class DeleteState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};