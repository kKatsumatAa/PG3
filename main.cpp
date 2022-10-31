#include<stdio.h>
#include<stdlib.h>


typedef struct cell
{
	int val = 0;
	struct cell* next = nullptr;//���ȎQ�ƍ\����

}CELL;

void Create(CELL* cellStart, int insertNum)
{
	CELL* newCell;
	//�V�K�쐬����Z�����̃��������m��
	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = insertNum;
	newCell->next = nullptr;

	//�Ō�̃Z���̃A�h���X�̈�ڂ̏����͈������玝���Ă���
	//���X�g�̂����ŏ��̃Z���̃A�h���X���Y������
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
	}
	cellStart->next = newCell;
}

void Index(CELL* cellStart)
{
	//�Ō��cell�ɂȂ�܂ŏo��
	while (cellStart->next != nullptr)
	{
		printf("%d\n", cellStart->val);
		cellStart = cellStart->next;
	}
	printf("%d\n", cellStart->val);
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
		Create(&cellStart, i + 2);
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