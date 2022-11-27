#include "Cell.h"
#include <string>

void Create(CELL* currentCell, const char* insertNum)
{
	CELL* newCell;
	//新規作成するセル分のメモリを確保
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->val, insertNum);
	//配置する場所にもともとあったセルのアドレスを入れる
	newCell->prev = currentCell;
	//配置する場所にもともとあったセルの、次にあるセルのアドレスを入れる
	newCell->next = currentCell->next;

	//挿入
	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		//配置する場所にもともとあったセルの、
		//次にあるセルのprevに新しく作るセルのアドレス
		nextCell->prev = newCell;
	}
	//配置する場所にもともとあったセルのnextに新しく作るセルのアドレス
	currentCell->next = newCell;
}

void Index(CELL* cellStart)
{
	int no = 0;
	//最後のcellになるまで出力
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
		printf(" %d:", no);
		printf("\"%s\"", cellStart->val);
		no++;

		if (cellStart->next)
		{
			printf(",\n");
		}
	}

	printf("\n");
}

CELL* GetInsertCellAddres(CELL* cellStart, int cellNum)
{
	//(一番最初のセルは使用させないため、+1してあげる)
	for (int i = 0; i < cellNum + 1; i++)
	{
		if (cellStart->next)
		{
			//最後のセルじゃないとき
			cellStart = cellStart->next;
		}
		else
		{
			break;
		}
	}
	return cellStart;
}

void DeleteCell(CELL* currentCell)
{
	//削除したいセルの一個前のセルのnextに,
	//削除したいセルの次のセルのアドレスを入れてあげる
	if (currentCell->prev)
	{
		currentCell->prev->next = currentCell->next;
	}
	//削除したいセルの次のセルのprevに,
	//削除したいセルの一個前のセルのアドレスを入れてあげる
	if (currentCell->next)
	{
		currentCell->next->prev = currentCell->prev;
	}

	//削除
	delete currentCell;
}

void EditCell(CELL* currentCell, const char* insertNum)
{
	//中身を変える
	strcpy_s(currentCell->val, insertNum);
}

int GetCellSize(CELL* cellStart)
{
	int count = 0;

	//nextがあればカウント増やす
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
		count++;
	}

	return count;
}
