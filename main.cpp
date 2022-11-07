#include<stdio.h>
#include<stdlib.h>


typedef struct cell
{
	int val = 0;
	struct cell* prev = nullptr;
	struct cell* next = nullptr;//自己参照構造体

}CELL;

void Create(CELL* currentCell, int insertNum)
{
	CELL* newCell;
	//新規作成するセル分のメモリを確保
	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = insertNum;
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
		printf("val:%5d ", cellStart->val);//五桁右揃え
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
	cellStart->prev->next = cellStart->next;
	//削除したいセルの次のセルのprevに,
	//削除したいセルの一個前のセルのアドレスを入れてあげる
	cellStart->next->prev = cellStart->prev;

	//削除
	delete cellStart;
}


void EditCell(CELL* cellStart, int cellNum, int insertNum)
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
	cellStart->val = insertNum;
}


int main()
{
	CELL cellStart;

	for (int i = 0; i < 10; i++)
	{
		Create(GetInsertCellAddres(&cellStart, i + 1), i + 1);
	}

	Create(GetInsertCellAddres(&cellStart, 5), 114514);

	//DeleteCell(&cellStart, 5);

	//EditCell(&cellStart, 5, 514);

	Index(&cellStart);


	return 0;
}