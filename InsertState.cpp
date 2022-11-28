#include"InsertState.h"

//-------------------------------------------------------------
void InsertState::Update()
{
	//改行を認識するために文字列で取得、改行じゃなかった場合はintに変換する
	char buff[100];
	fgets(buff, sizeof(buff), stdin);
	fgets(buff, sizeof(buff), stdin);

	if (buff[0] == '\n') { cellManager->SetNum(-1); }
	else                 { cellManager->SetNum(atoi(buff)); }

	cellManager->ChangeState(new InsertState2);
}

void InsertState::Draw()
{
	printf("\n------------------------------------------------------\n");
	printf("[リスト要素の挿入]\n");
	printf("要素を何番目に追加するか指定してください。最後尾に追加する場合は何も入力しないでください。\n");
	printf("\n-\n\n");
}

//------------------------------------------------------------------
void InsertState2::Update()
{
	char str[128] = { 0 };

	scanf_s("%s", str, 128);

	cellManager->SetInsertStr(str);

	//最後尾に挿入の場合
	if (*cellManager->GetNum() == -1)
	{
		cellManager->SetNum(GetCellSize(cellManager->GetCell()));
	}
	//先頭は使わないため＋１しているが、挿入したい場所にもともとあったセルの前に挿入したいので-1で+-0にする
	Create(GetInsertCellAddres(cellManager->GetCell(), *cellManager->GetNum() - 1), cellManager->GetInsertStr());

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
	printf("要素\"%s\" が %d 番目に挿入されました\n", cellManager->GetInsertStr(), *cellManager->GetNum());
	printf("\n---------------------------------------------\n");
	printf("1.要素の挿入\n");
	printf("2.要素操作に戻る\n");
	printf("\n操作を選択してください\n");
	printf("-\n\n");
}
