#include"InsertState.h"

//-------------------------------------------------------------
void InsertState::Update()
{
	scanf_s("%d", cellManager->GetNum());

	cellManager->ChangeState(new InsertState2);
}

void InsertState::Draw()
{
	printf("\n------------------------------------------------------\n");
	printf("[���X�g�v�f�̑}��]\n");
	printf("�v�f�����Ԗڂɒǉ����邩�w�肵�Ă��������B�Ō���ɒǉ�����ꍇ��[-1]�Ɠ��͂��Ă��������B\n");
	printf("\n-\n\n");
}

//------------------------------------------------------------------
void InsertState2::Update()
{
	char str[128] = { 0 };

	scanf_s("%s", str, 128);

	cellManager->SetInsertStr(str);

	//�Ō���ɑ}���̏ꍇ
	if (*cellManager->GetNum() == -1)
	{
		cellManager->SetNum(GetCellSize(cellManager->GetCell()));
	}
	//�擪�͎g��Ȃ����߁{�P���Ă��邪�A�}���������ꏊ�ɂ��Ƃ��Ƃ������Z���̑O�ɑ}���������̂�-1��+-0�ɂ���
	Create(GetInsertCellAddres(cellManager->GetCell(), *cellManager->GetNum() - 1), cellManager->GetInsertStr());

	cellManager->ChangeState(new InsertState3);
}

void InsertState2::Draw()
{
	printf("�ǉ�����v�f�̒l����͂��Ă�������\n");
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
	printf("�v�f\"%s\" �� %d �Ԗڂɑ}������܂���\n", cellManager->GetInsertStr(), *cellManager->GetNum());
	printf("\n---------------------------------------------\n");
	printf("1.�v�f�̑}��\n");
	printf("2.�v�f����ɖ߂�\n");
	printf("\n�����I�����Ă�������\n");
	printf("-\n\n");
}
