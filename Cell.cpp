#include "Cell.h"
#include <string>

void Create(CELL* currentCell, const char* insertNum)
{
	CELL* newCell;
	//�V�K�쐬����Z�����̃��������m��
	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->val, insertNum);
	//�z�u����ꏊ�ɂ��Ƃ��Ƃ������Z���̃A�h���X������
	newCell->prev = currentCell;
	//�z�u����ꏊ�ɂ��Ƃ��Ƃ������Z���́A���ɂ���Z���̃A�h���X������
	newCell->next = currentCell->next;

	//�}��
	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		//�z�u����ꏊ�ɂ��Ƃ��Ƃ������Z���́A
		//���ɂ���Z����prev�ɐV�������Z���̃A�h���X
		nextCell->prev = newCell;
	}
	//�z�u����ꏊ�ɂ��Ƃ��Ƃ������Z����next�ɐV�������Z���̃A�h���X
	currentCell->next = newCell;
}

void Index(CELL* cellStart)
{
	int no = 0;
	//�Ō��cell�ɂȂ�܂ŏo��
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
	//(��ԍŏ��̃Z���͎g�p�����Ȃ����߁A+1���Ă�����)
	for (int i = 0; i < cellNum + 1; i++)
	{
		if (cellStart->next)
		{
			//�Ō�̃Z������Ȃ��Ƃ�
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
	//�폜�������Z���̈�O�̃Z����next��,
	//�폜�������Z���̎��̃Z���̃A�h���X�����Ă�����
	if (currentCell->prev)
	{
		currentCell->prev->next = currentCell->next;
	}
	//�폜�������Z���̎��̃Z����prev��,
	//�폜�������Z���̈�O�̃Z���̃A�h���X�����Ă�����
	if (currentCell->next)
	{
		currentCell->next->prev = currentCell->prev;
	}

	//�폜
	delete currentCell;
}

void EditCell(CELL* currentCell, const char* insertNum)
{
	//���g��ς���
	strcpy_s(currentCell->val, insertNum);
}

int GetCellSize(CELL* cellStart)
{
	int count = 0;

	//next������΃J�E���g���₷
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
		count++;
	}

	return count;
}
