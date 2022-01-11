#pragma once
#include "struct.h"
#include "Player.h"

class Rescued {
	//�N���X�ϐ�
public:
	Transform transform;
	int r;
	int isRescued;
	Player* player;

	//�N���X�֐�
public:
	Rescued();
	~Rescued();
	void RescuedCollision(Player* player);
	void Move(Player* player);
	void Draw(int scroll);
};