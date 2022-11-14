#include"DisplayState.h"

//-------------------------------------------------------------
void DisplayState::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new AllDisplay);
		break;
	case 2:
		cellManager->ChangeState(new OrderDisplay);
		break;
	case 9:
		cellManager->ChangeState(new InitialState);
		break;
	}
}

void DisplayState::Draw()
{
	printf("[�v�f�̕\��]\n");
	printf("1.�v�f�̈ꗗ�\��\n");
	printf("2.���Ԃ��w�肵�ėv�f��\��\n");
	printf("9.�v�f����ɖ߂�\n");
	printf("\n�����I�����Ă�������\n");
	printf("-\n\n");
}

//-------------------------------------------------
void AllDisplay::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new DisplayState);
		break;
	case 2:
		cellManager->ChangeState(new InitialState);
		break;
	}
}

void AllDisplay::Draw()
{
	printf("[�v�f�̈ꗗ�\��]\n");
	printf("�v�f��:%d\n", GetCellSize(cellManager->GetCell()));
	printf("�v�f�ꗗ:{\n");
	Index(cellManager->GetCell());
	printf("}\n");
	printf("\n------------------------------------------------------\n");
	printf("1.�v�f�̕\���ɖ߂�\n");
	printf("2.�v�f�̑���ɖ߂�\n");
	printf("-\n\n");
}


//--------------------------------------------------
void OrderDisplay::Update()
{
}

void OrderDisplay::Draw()
{
}
