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
	int no = 1;
	//最後のcellになるまで出力
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
		printf("no:%d ", no);
		printf("prev:%p ", cellStart->prev);
		printf("val:%s ", cellStart->val);
		printf("this:(%p) ", cellStart);
		printf("next:%p \n", cellStart->next);
		no++;
	}
}

CELL* GetInsertCellAddres(CELL* cellStart, int cellNum)
{
	//n番目に入れたいときはn番目にもともとあったセルの前に入れてあげる（-1）
	for (int i = 0; i < cellNum - 1; i++)
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

void DeleteCell(CELL* cellStart, int cellNum)
{

	//cellNumの回数分進む
	for (int i = 0; i < cellNum; i++)
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
	//削除したいセルの一個前のセルのnextに,
	//削除したいセルの次のセルのアドレスを入れてあげる
	if (cellStart->prev)
	{
		cellStart->prev->next = cellStart->next;
	}
	//削除したいセルの次のセルのprevに,
	//削除したいセルの一個前のセルのアドレスを入れてあげる
	if (cellStart->next)
	{
		cellStart->next->prev = cellStart->prev;
	}

	//削除
	delete cellStart;
}

void EditCell(CELL* cellStart, int cellNum, const char* insertNum)
{
	//cellNumの回数分進む
	for (int i = 0; i < cellNum; i++)
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

	//中身を変える
	strcpy_s(cellStart->val, insertNum);
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
