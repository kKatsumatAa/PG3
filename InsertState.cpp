#include"InsertState.h"

//-------------------------------------------------------------
void InsertState::Update()
{
	scanf_s("%d", cellManager->GetNum());

	cellManager->ChangeState(new InsertState2);
}

void InsertState::Draw()
{
	printf("[リスト要素の挿入]\n");
	printf("要素を何番目に追加するか指定してください。最後尾に追加する場合は[-1]と入力してください。\n");
	printf("\n-\n\n");
}

//------------------------------------------------------------------
void InsertState2::Update()
{
	scanf_s("%d", cellManager->GetInsertNum());

	CELL* ptr;
	//最後尾に挿入の場合
	if (*cellManager->GetNum() == -1) cellManager->SetNum(GetCellSize(cellManager->GetCell()) + 1);

	Create(GetInsertCellAddres(cellManager->GetCell(), *cellManager->GetNum()), *cellManager->GetInsertNum());

	cellManager->ChangeState(new InsertState3);
}

void InsertState2::Draw()
{
	printf("追加する要素の値を入力してください\n");
	printf("\n-\n\n");
}

//------------------------------------------------------------------
void InsertState3::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new InsertState);
		break;
	case 2:
		cellManager->ChangeState(new InitialState);
		break;
	}
}

void InsertState3::Draw()
{
	printf("要素:%d が %d 番目に挿入されました\n", *cellManager->GetInsertNum(), *cellManager->GetNum());
	printf("\n---------------------------------------------\n");
	printf("1.要素の挿入\n");
	printf("2.要素操作に戻る\n");
	printf("\n操作を選択してください\n");
	printf("-\n\n");
}
