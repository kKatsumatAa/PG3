#include<stdio.h>
#include<stdlib.h>


typedef struct cell
{
	int val = 0;
	struct cell* next = nullptr;//自己参照構造体

}CELL;

typedef struct cellstr
{
	const char* str;
	struct cellstr* next = nullptr;//自己参照構造体

}CELLSTR;

void Create(CELL* cellStart, int insertNum)
{
	CELL* newCell;
	//新規作成するセル分のメモリを確保
	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = insertNum;
	newCell->next = nullptr;

	//最後のセルのアドレスの一つ目の処理は引数から持ってきた
	//リストのうち最初のセルのアドレスが該当する
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
	}
	cellStart->next = newCell;
}

void Index(CELL* cellStart)
{
	//最後のcellになるまで出力
	while (cellStart->next != nullptr)
	{
		printf("%d\n", cellStart->val);
		cellStart = cellStart->next;
	}
	printf("%d\n", cellStart->val);
}


int main()
{
	CELL cellStart;
	cellStart.val = 1;

	for (int i = 0; i < 10; i++)
	{
		Create(&cellStart, i + 2);
	}

	Index(&cellStart);

	return 0;
}