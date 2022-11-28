#include"CellManager.h"
#include "DeleteState.h"

//-------------------------------------------------------------
void DeleteState::Update()
{
	scanf_s("%d", cellManager->GetNum());

	//�v�f���Ȃ����(�Y������0����Ȃ̂�-1�i0�Ԗڂ�����ƃT�C�Y��1�ɂȂ�j)
	if (*cellManager->GetNum() > GetCellSize(cellManager->GetCell()) - 1)
	{
		cellManager->ChangeState(new DeleteState3);
	}
	//�����
	else
	{
		cellManager->ChangeState(new DeleteState2);
	}
}
void DeleteState::Draw()
{
	printf("\n------------------------------------------------------\n");
	printf("[�v�f�̍폜]\n");
	printf("�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");
	printf("\n-\n\n");
}


//-------------------------------------------------------------------------------
void DeleteState2::Update()
{
	//�폜
	DeleteCell(GetInsertCellAddres(cellManager->GetCell(), *cellManager->GetNum()));

	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new DeleteState);
		break;
	case 2:
		cellManager->ChangeState(new InitialState);
		break;
	}
}

void DeleteState2::Draw()
{
	printf("%d�Ԗڂ̗v�f\"%s\"���폜���܂����B\n", *cellManager->GetNum(),
		GetInsertCellAddres(cellManager->GetCell(), *cellManager->GetNum())->val);
	printf("\n-\n\n");

	printf("\n------------------------------------------------------\n");
	printf("1.�v�f�̍폜�ɖ߂�\n");
	printf("2.�v�f�̑���ɖ߂�\n");
	printf("-\n\n");
}


//-------------------------------------------------------------------------------
void DeleteState3::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new DeleteState);
		break;
	case 2:
		cellManager->ChangeState(new InitialState);
		break;
	}
}

void DeleteState3::Draw()
{
	printf("%d�Ԗڂ̗v�f��������܂���ł����B\n", *cellManager->GetNum());
	printf("\n-\n\n");

	printf("\n------------------------------------------------------\n");
	printf("1.�v�f�̍폜�ɖ߂�\n");
	printf("2.�v�f�̑���ɖ߂�\n");
	printf("-\n\n");
}
