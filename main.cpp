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
	CELL* endCell = currentCell;

	CELL* newCell;
	//新規作成するセル分のメモリを確保
	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = insertNum;
	//配置する場所にもともとあったセルのアドレスを入れる
	newCell->prev = endCell;
	//配置する場所にもともとあったセルの、次にあるセルのアドレスを入れる
	newCell->next = endCell->next;

	//挿入
	if (endCell->next)
	{
		CELL* nextCell = endCell->next;
		//配置する場所にもともとあったセルの、
		//次にあるセルのprevに新しく作るセルのアドレス
		nextCell->prev = newCell;
	}
	//配置する場所にもともとあったセルのnextに新しく作るセルのアドレス
	endCell->next = newCell;
}

void Index(CELL* cellEnd)
{
	int no = 1;
	//最後のcellになるまで出力
	while (cellEnd->next != nullptr)
	{
		cellEnd = cellEnd->next;
		printf("%d ", no);
		printf("%p ", cellEnd->prev );
		printf("%5d ", cellEnd->val );
		printf("(%p) ", cellEnd );
		printf("%p \n", cellEnd->next );
		no++;
	}
}

CELL* GetInsertCellAddres(CELL* cellEnd, int cellNum)
{
	CELL* endCell = cellEnd;

	//cellNumの回数分進む
	for (int i = 0; i < cellNum; i++)
	{
		if (endCell->next)
		{
			//最後のセルじゃないとき
			endCell = endCell->next;
		}
		else
		{
			break;
		}
	}
	return endCell;
}

//----------------------------------------
typedef struct cellstr
{
	const char* str;
	struct cellstr* next = nullptr;//自己参照構造体

}CELLSTR;

void Create(CELLSTR* cellStart, const char* insertStr)
{
	CELLSTR* newCell;
	//新規作成するセル分のメモリを確保
	newCell = (CELLSTR*)malloc(sizeof(CELLSTR));

	newCell->str = insertStr;
	newCell->next = nullptr;

	//最後のセルのアドレスの一つ目の処理は引数から持ってきた
	//リストのうち最初のセルのアドレスが該当する
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
	}
	cellStart->next = newCell;
}

void Index(CELLSTR* cellStart)
{
	//最後のcellになるまで出力
	while (cellStart->next != nullptr)
	{
		printf("%s\n", cellStart->str);
		cellStart = cellStart->next;
	}
	printf("%s\n", cellStart->str);
}

int main()
{
	CELL cellStart;
	cellStart.val = 1;

	for (int i = 0; i < 10; i++)
	{
		Create(&cellStart, i + 1);
	}

	Index(&cellStart);

	//-------------------------
	CELLSTR cellStrStart;
	cellStrStart.str = "パパ";
	Create(&cellStrStart, "ママ");
	Create(&cellStrStart, "ポチex");
	Create(&cellStrStart, "タマ大魔王");

	Index(&cellStrStart);

	return 0;
}