#pragma once
#include<stdio.h>

class IShape
{
private:


public:
	/// <summary>
	/// �ʐς����߂�
	/// </summary>
	/// <returns></returns>
	virtual float size() = 0;

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() = 0;
};

