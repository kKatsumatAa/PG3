#include"SceneManager.h"


int main()
{
	//�J��Ԃ�
	while (true)
	{
		SceneManager::GetInstance()->Update();
		SceneManager::GetInstance()->Draw();
	}

	return 0;
}