#include"CellManager.h"
#include "DeleteState.h"

//-------------------------------------------------------------
void DeleteState::Update()
{
	scanf_s("%d", cellManager->GetNum());

	//—v‘f‚ª‚È‚¯‚ê‚Î
	if (*cellManager->GetNum() > GetCellSize(cellManager->GetCell()))
	{
		cellManager->ChangeState(new DeleteState3);
	}
	//‚ ‚ê‚Î
	else
	{
		cellManager->ChangeState(new DeleteState2);
	}
}
void DeleteState::Draw()
{
	printf("\n------------------------------------------------------\n");
	printf("[—v‘f‚Ìíœ]\n");
	printf("íœ‚µ‚½‚¢—v‘f‚Ì”Ô†‚ğw’è‚µ‚Ä‚­‚¾‚³‚¢B\n");
	printf("\n-\n\n");
}


//-------------------------------------------------------------------------------
void DeleteState2::Update()
{
	//íœ
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
	//GetInsertCellAddres()‚Í‘}“ü‚·‚é‚Æ‚«—p‚É]‚P‚µ‚Ä‚ ‚é‚Ì‚Ånum‚É{‚P‚·‚é
	printf("%d”Ô–Ú‚Ì—v‘f[%s]‚ğíœ‚µ‚Ü‚µ‚½B\n", *cellManager->GetNum(),
		GetInsertCellAddres(cellManager->GetCell(), *cellManager->GetNum() + 1)->val);
	printf("\n-\n\n");

	printf("\n------------------------------------------------------\n");
	printf("1.—v‘f‚Ìíœ‚É–ß‚é\n");
	printf("2.—v‘f‚Ì‘€ì‚É–ß‚é\n");
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
	printf("%d”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B\n", *cellManager->GetNum());
	printf("\n-\n\n");

	printf("\n------------------------------------------------------\n");
	printf("1.—v‘f‚Ìíœ‚É–ß‚é\n");
	printf("2.—v‘f‚Ì‘€ì‚É–ß‚é\n");
	printf("-\n\n");
}
