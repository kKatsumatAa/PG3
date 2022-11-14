#include"CellManager.h"

//-------------------------------------------------------------
void InitialState::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new DisplayState);
		break;
	case 2:
		cellManager->ChangeState(new InsertState);
		break;
	case 3:
		cellManager->ChangeState(new EditState);
		break;
	case 4:
		cellManager->ChangeState(new DeleteState);
		break;
	case 5:
		//cellManager->ChangeState(new );
		break;
	}
}

void InitialState::Draw()
{
	printf("[�v�f�̑���]\n");
	printf("1.�v�f�̕\��\n");
	printf("2.�v�f�̑}��\n");
	//�v�f����0����Ȃ��Ƃ�
	if (GetCellSize(cellManager->GetCell()))
	{
		printf("3.�v�f�̕ҏW\n");
		printf("4.�v�f�̍폜\n");
	}
	printf("5.�v�f�̕��ёւ�(�I�v�V����)\n");
	printf("\n---------------------------------\n");
	printf("�����I�����Ă�������\n");
	printf("-\n\n");
}