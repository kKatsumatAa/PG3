#include"DisplayState.h"
#include<string>

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
	printf("\n------------------------------------------------------\n");
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
	printf("�v�f�ꗗ:{\n");
	Index(cellManager->GetCell());
	printf("}\n");
	printf("\n�v�f��:%d\n", GetCellSize(cellManager->GetCell()));
	printf("\n------------------------------------------------------\n");
	printf("1.�v�f�̕\���ɖ߂�\n");
	printf("2.�v�f�̑���ɖ߂�\n");
	printf("-\n\n");
}


//--------------------------------------------------
void OrderDisplay::Update()
{
	cellManager->ClearOrder();

	int num = 0;

	//�J�E���g�p
	*cellManager->GetNum() = 0;

	int i = 0;
	//���s��F�����邽�߂ɕ�����Ŏ擾�A���s����Ȃ������ꍇ��int�ɕϊ�����
	char buff[100];
	fgets(buff, sizeof(buff), stdin);
	while (true)
	{
		fgets(buff, sizeof(buff), stdin);

		if (buff[0] == '\n') { break; }
		else
		{
			printf(",");

			cellManager->GetOrder()[i] = atoi(buff);

			i++;
			(*cellManager->GetNum()) = i;
		}
	}

	cellManager->ChangeState(new OrderDisplay2);
}

void OrderDisplay::Draw()
{
	printf("[���Ԃ��w�肵�ėv�f��\��]\n");
	printf("�\���������v�f�̏��Ԃ��w�肵�Ă��������B�������͂Ȃ��Ŋm��B\n");
	printf("\n\n-\n");
}

//-----------------------------------------------------------------
void OrderDisplay2::Update()
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

void OrderDisplay2::Draw()
{
	printf("{\n");

	int i = 0;
	while (true)
	{
		//�Ō���͂���-1�̃J�E���g�����炷(-1)
		if (*cellManager->GetNum() - 1 < i) { break; }

		printf(" %d: \"%s\",\n", cellManager->GetOrder()[i],
			GetInsertCellAddres(cellManager->GetCell(), cellManager->GetOrder()[i])->val);

		i++;
	}

	printf("}\n");

	printf("\n------------------------------------------------------\n");
	printf("1.�v�f�̕\���ɖ߂�\n");
	printf("2.�v�f�̑���ɖ߂�\n");
	printf("-\n\n");
}
