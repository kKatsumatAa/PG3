#pragma once
#include<stdio.h>
#include <stdlib.h>

class SceneManager final
{
private:
	enum SCENE
	{
		TITLE,
		NEW_GAME,
		GAME_PLAY,
		GAME_CLEAR
	};

	int sceneNum = SCENE::TITLE;

private:
	//�R���X�g���N�^��private
	SceneManager();
	//�f�X�g���N�^��
	~SceneManager();

public:
	//�R�s�[�R���X�g���N�^�𖳌�
	SceneManager(const SceneManager& obj) = delete;
	//������Z�q��
	SceneManager& operator=(const SceneManager& obj) = delete;

	//�C���X�^���X�擾
	static SceneManager* GetInstance();

	void ChangeScene(int sceneNo);

	void Update();
	void Draw();
};