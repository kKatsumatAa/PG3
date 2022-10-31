#include<stdio.h>
#include<stdlib.h>


typedef struct cell
{
	int val;
	struct cell* next;//自己参照構造体

}CELL;

void Create(CELL* cellStart, int insertNum)
{
	CELL* newCell;
	//新規作成するセル分のメモリを確保
	newCell = (CELL*)malloc(sizeof(CELL));
}


int main()
{
	

	return 0;
}