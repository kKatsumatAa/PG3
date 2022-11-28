#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <string>

typedef struct cell
{
	char val[128];
	struct cell* prev = nullptr;
	struct cell* next = nullptr;//自己参照構造体

}CELL;

void Create(CELL* currentCell, const char* insertNum);

void Index(CELL* cellStart);

CELL* GetInsertCellAddres(CELL* cellStart, int cellNum);

void DeleteCell(CELL* currentCell);

void EditCell(CELL* currentCell, const char* insertNum);

int GetCellSize(CELL* cellStart);