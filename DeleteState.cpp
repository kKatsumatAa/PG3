#include"CellManager.h"
#include "DeleteState.h"

//-------------------------------------------------------------
void DeleteState::Update()
{
	scanf_s("%d", cellManager->GetNum());

	//要素がなければ
	if (*cellManager->GetNum() > GetCellSize(cellManager->GetCell()))
	{
		cellManager->ChangeState(new DeleteState3);
	}
	//あれば
	else
	{
		cellManager->ChangeState(new DeleteState2);
	}
}
void DeleteState::Draw()
{
	printf("\n------------------------------------------------------\n");
	printf("[要素の削除]\n");
	printf("削除したい要素の番号を指定してください。\n");
	printf("\n-\n\n");
}


//-------------------------------------------------------------------------------
void DeleteState2::Update()
{
	//削除
	DeleteCell(cellManager->GetCell(), *cellManager->GetNum());

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
	//GetInsertCellAddres()は挿入するとき用に‐１してあるのでnumに＋１する
	printf("%d番目の要素[%d]を削除しました。\n", *cellManager->GetNum(),
		GetInsertCellAddres(cellManager->GetCell(), *cellManager->GetNum() + 1)->val);
	printf("\n-\n\n");

	printf("\n------------------------------------------------------\n");
	printf("1.要素の削除に戻る\n");
	printf("2.要素の操作に戻る\n");
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
	printf("%d番目の要素が見つかりませんでした。\n", *cellManager->GetNum());
	printf("\n-\n\n");

	printf("\n------------------------------------------------------\n");
	printf("1.要素の削除に戻る\n");
	printf("2.要素の操作に戻る\n");
	printf("-\n\n");
}
