#pragma once
#include "struct.h"
#include "Player.h"

class Rescued {
	//クラス変数
public:
	Transform transform;
	int r;
	int isRescued;
	Player* player;

	//クラス関数
public:
	Rescued();
	~Rescued();
	void RescuedCollision(Player* player);
	void Move(Player* player);
	void Draw(int scroll);
};