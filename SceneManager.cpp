#include "SceneManager.h"


SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
	if (sceneNo > SCENE::GAME_CLEAR) sceneNum = SCENE::TITLE;
	else                             sceneNum = sceneNo;
}

void SceneManager::Update()
{
	timer++;

	if (timer >= timerMax)
	{
		ChangeScene(sceneNum + 1);
	}
}

void SceneManager::Draw()
{
	if (timer >= timerMax)
	{
		switch (sceneNum)
		{
		case SCENE::TITLE:
			printf("TITLE\n");
			break;
		case SCENE::NEW_GAME:
			printf("NewGame\n");
			break;
		case SCENE::GAME_PLAY:
			printf("GamePlay\n");
			break;
		case SCENE::GAME_CLEAR:
			printf("GameClear\n");
			break;
		}

		timer = 0;
	}
}