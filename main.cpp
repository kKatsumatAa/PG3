#include<stdio.h>
#include<stdlib.h>


typedef struct cell
{
	int val = 0;
	struct cell* prev = nullptr;
	struct cell* next = nullptr;//���ȎQ�ƍ\����

}CELL;

void Create(CELL* currentCell, int insertNum)
{
	CELL* endCell = currentCell;

	CELL* newCell;
	//�V�K�쐬����Z�����̃��������m��
	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = insertNum;
	//�z�u����ꏊ�ɂ��Ƃ��Ƃ������Z���̃A�h���X������
	newCell->prev = endCell;
	//�z�u����ꏊ�ɂ��Ƃ��Ƃ������Z���́A���ɂ���Z���̃A�h���X������
	newCell->next = endCell->next;

	//�}��
	if (endCell->next)
	{
		CELL* nextCell = endCell->next;
		//�z�u����ꏊ�ɂ��Ƃ��Ƃ������Z���́A
		//���ɂ���Z����prev�ɐV�������Z���̃A�h���X
		nextCell->prev = newCell;
	}
	//�z�u����ꏊ�ɂ��Ƃ��Ƃ������Z����next�ɐV�������Z���̃A�h���X
	endCell->next = newCell;
}

void Index(CELL* cellEnd)
{
	int no = 1;
	//�Ō��cell�ɂȂ�܂ŏo��
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

	//cellNum�̉񐔕��i��
	for (int i = 0; i < cellNum; i++)
	{
		if (endCell->next)
		{
			//�Ō�̃Z������Ȃ��Ƃ�
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
	struct cellstr* next = nullptr;//���ȎQ�ƍ\����

}CELLSTR;

void Create(CELLSTR* cellStart, const char* insertStr)
{
	CELLSTR* newCell;
	//�V�K�쐬����Z�����̃��������m��
	newCell = (CELLSTR*)malloc(sizeof(CELLSTR));

	newCell->str = insertStr;
	newCell->next = nullptr;

	//�Ō�̃Z���̃A�h���X�̈�ڂ̏����͈������玝���Ă���
	//���X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
	}
	cellStart->next = newCell;
}

void Index(CELLSTR* cellStart)
{
	//�Ō��cell�ɂȂ�܂ŏo��
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
	cellStrStart.str = "�p�p";
	Create(&cellStrStart, "�}�}");
	Create(&cellStrStart, "�|�`ex");
	Create(&cellStrStart, "�^�}�喂��");

	Index(&cellStrStart);

	return 0;
}