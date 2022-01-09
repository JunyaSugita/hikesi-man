#pragma once
#include "Struct.h"

class Player{
public:
	Player();
	~Player();

public:
	void SaveOldPlayer();
	void PlayerMove(int InputX);
	void PlayerJump(int pad);
	void GetPlayer(int BLOCK_SIZE);
	void GetOldPlayer(int BLOCK_SIZE);
	void GetScroll();

	void DrawPlayer();
public:
	PLAYER player;
	OldPlayer oldPlayer;

	//左上の座標
	int leftTopX, leftTopY;
	//左下の座標
	int leftBottomX, leftBottomY;
	//右下の座標
	int rightTopX, rightTopY;
	//右下の座標
	int rightBottomX, rightBottomY;
	//1フレーム前の左上の座標
	int oldLeftTopX, oldLeftTopY;
	//1フレーム前の右上の座標
	int oldRightTopX, oldRightTopY;
	//1フレーム前の左下の座標
	int oldLeftBottomX, oldLeftBottomY;
	//1フレーム前の右下の座標
	int oldRightBottomX, oldRightBottomY;

	//重力
	const int G = 5;

	//スクロール
	int scroll;
};

