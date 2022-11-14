#include"CellManager.h"

int main()
{
	CellManager* cellManager = new CellManager;

	{
		//CELL cellStart;

		//for (int i = 0; i < 10; i++)
		//{
		//	Create(GetInsertCellAddres(&cellStart, i + 1), i + 1);
		//}

		//Create(GetInsertCellAddres(&cellStart, 5), 114514);

		////DeleteCell(&cellStart, 5);

		////EditCell(&cellStart, 5, 514);

		//Index(&cellStart);

		//printf("num:%d", GetCellSize(&cellStart));
	}


	while (true)
	{
		cellManager->Draw();
		cellManager->Update();
	}

	delete cellManager;

	return 0;
}