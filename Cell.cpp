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
	int no = 1;
	//�Ō��cell�ɂȂ�܂ŏo��
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
	//n�Ԗڂɓ��ꂽ���Ƃ���n�Ԗڂɂ��Ƃ��Ƃ������Z���̑O�ɓ���Ă�����i-1�j
	for (int i = 0; i < cellNum - 1; i++)
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

void DeleteCell(CELL* cellStart, int cellNum)
{

	//cellNum�̉񐔕��i��
	for (int i = 0; i < cellNum; i++)
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
	//�폜�������Z���̈�O�̃Z����next��,
	//�폜�������Z���̎��̃Z���̃A�h���X�����Ă�����
	if (cellStart->prev)
	{
		cellStart->prev->next = cellStart->next;
	}
	//�폜�������Z���̎��̃Z����prev��,
	//�폜�������Z���̈�O�̃Z���̃A�h���X�����Ă�����
	if (cellStart->next)
	{
		cellStart->next->prev = cellStart->prev;
	}

	//�폜
	delete cellStart;
}

void EditCell(CELL* cellStart, int cellNum, const char* insertNum)
{
	//cellNum�̉񐔕��i��
	for (int i = 0; i < cellNum; i++)
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

	//���g��ς���
	strcpy_s(cellStart->val, insertNum);
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
