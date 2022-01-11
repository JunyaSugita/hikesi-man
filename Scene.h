#pragma once
#include"Bullet.h"
#include"Fire.h"
#include"Map.h"
#include"Player.h"
#include"Rescued.h"


class Scene {
public:
	Player* player;
	Bullet* bullet;
	Rescued* rescued;
	Map* map;
	Fire* fire;
	DINPUT_JOYSTATE padInput;
	int pad;

public:
	Scene();
	~Scene();
	void Update(char* keys,char* oldkeys);
	void Draw();
};