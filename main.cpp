#include<stdio.h>
#include<stdlib.h>


typedef struct cell
{
	int val;
	struct cell* next;//���ȎQ�ƍ\����

}CELL;

void Create(CELL* cellStart, int insertNum)
{
	CELL* newCell;
	//�V�K�쐬����Z�����̃��������m��
	newCell = (CELL*)malloc(sizeof(CELL));
}


int main()
{
	

	return 0;
}