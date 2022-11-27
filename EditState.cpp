#include"CellManager.h"
#include "EditState.h"

//-------------------------------------------------------------
void EditState::Update()
{
	scanf_s("%d", cellManager->GetNum());

	//要素がなければ(先頭使わないので-1)
	if (*cellManager->GetNum() > GetCellSize(cellManager->GetCell()) - 1)
		cellManager->ChangeState(new EditState4);
	//あれば
	else
		cellManager->ChangeState(new EditState2);
}

void EditState::Draw()
{
	printf("\n------------------------------------------------------\n");
	printf("[要素の編集]\n");
	printf("編集したい要素の番号を指定してください。\n");
	printf("\n-\n\n");
}

//------------------------------------------------------------------
//要素ある
void EditState2::Update()
{
	char str[128] = { "" };

	scanf_s("%s", str, 128);

	cellManager->SetInsertStr(str);

	//編集
	EditCell(GetInsertCellAddres(cellManager->GetCell(), *cellManager->GetNum()), cellManager->GetInsertStr());

	cellManager->ChangeState(new EditState3);
}

void EditState2::Draw()
{
	printf("%d番目の要素の変更する値を入力してください。\n", *cellManager->GetNum());
	printf("\n-\n\n");
}

//------------------------------------------------------------------
//要素ある２
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
	printf("%d番目の要素が[%s]に変更されました。\n",
		*cellManager->GetNum(), cellManager->GetInsertStr());
	printf("\n-\n\n");

	printf("\n------------------------------------------------------\n");
	printf("1.要素の編集に戻る\n");
	printf("2.要素の操作に戻る\n");
	printf("-\n\n");
}

//------------------------------------------------------------------
//要素ない
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
	printf("%d番目の要素が見つかりませんでした。\n",
		*cellManager->GetNum());

	printf("\n------------------------------------------------------\n");
	printf("1.要素の編集に戻る\n");
	printf("2.要素の操作に戻る\n");
	printf("-\n\n");
}
