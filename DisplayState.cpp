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
	printf("[要素の表示]\n");
	printf("1.要素の一覧表示\n");
	printf("2.順番を指定して要素を表示\n");
	printf("9.要素操作に戻る\n");
	printf("\n操作を選択してください\n");
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
	printf("[要素の一覧表示]\n");
	printf("要素数:%d\n", GetCellSize(cellManager->GetCell()));
	printf("要素一覧:{\n");
	Index(cellManager->GetCell());
	printf("}\n");
	printf("\n------------------------------------------------------\n");
	printf("1.要素の表示に戻る\n");
	printf("2.要素の操作に戻る\n");
	printf("-\n\n");
}


//--------------------------------------------------
void OrderDisplay::Update()
{
}

void OrderDisplay::Draw()
{
}
