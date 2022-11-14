#pragma once
#include<stdio.h>
#include<stdlib.h>


typedef struct cell
{
	int val = 0;
	struct cell* prev = nullptr;
	struct cell* next = nullptr;//é©å»éQè∆ç\ë¢ëÃ

}CELL;

void Create(CELL* currentCell, int insertNum);

void Index(CELL* cellStart);

CELL* GetInsertCellAddres(CELL* cellStart, int cellNum);

void DeleteCell(CELL* cellStart, int cellNum);

void EditCell(CELL* cellStart, int cellNum, int insertNum);

int GetCellSize(CELL* cellStart);