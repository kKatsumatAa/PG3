#include"CellManager.h"
#include "EditState.h"

//-------------------------------------------------------------
void EditState::Update()
{
	scanf_s("%d", cellManager->GetNum());

	//�v�f���Ȃ����(�擪�g��Ȃ��̂�-1)
	if (*cellManager->GetNum() > GetCellSize(cellManager->GetCell()) - 1)
		cellManager->ChangeState(new EditState4);
	//�����
	else
		cellManager->ChangeState(new EditState2);
}

void EditState::Draw()
{
	printf("\n------------------------------------------------------\n");
	printf("[�v�f�̕ҏW]\n");
	printf("�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
	printf("\n-\n\n");
}

//------------------------------------------------------------------
//�v�f����
void EditState2::Update()
{
	char str[128] = { "" };

	scanf_s("%s", str, 128);

	cellManager->SetInsertStr(str);

	//�ҏW
	EditCell(GetInsertCellAddres(cellManager->GetCell(), *cellManager->GetNum()), cellManager->GetInsertStr());

	cellManager->ChangeState(new EditState3);
}

void EditState2::Draw()
{
	printf("%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", *cellManager->GetNum());
	printf("\n-\n\n");
}

//------------------------------------------------------------------
//�v�f����Q
void EditState3::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new EditState);
		break;
	case 2:
		cellManager->ChangeState(new InitialState);
		break;
	}
}

void EditState3::Draw()
{
	printf("%d�Ԗڂ̗v�f��[%s]�ɕύX����܂����B\n",
		*cellManager->GetNum(), cellManager->GetInsertStr());
	printf("\n-\n\n");

	printf("\n------------------------------------------------------\n");
	printf("1.�v�f�̕ҏW�ɖ߂�\n");
	printf("2.�v�f�̑���ɖ߂�\n");
	printf("-\n\n");
}

//------------------------------------------------------------------
//�v�f�Ȃ�
void EditState4::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new EditState);
		break;
	case 2:
		cellManager->ChangeState(new InitialState);
		break;
	}
}

void EditState4::Draw()
{
	printf("%d�Ԗڂ̗v�f��������܂���ł����B\n",
		*cellManager->GetNum());

	printf("\n------------------------------------------------------\n");
	printf("1.�v�f�̕ҏW�ɖ߂�\n");
	printf("2.�v�f�̑���ɖ߂�\n");
	printf("-\n\n");
}
