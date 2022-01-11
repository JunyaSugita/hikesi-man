#pragma once
#include "Struct.h"
#include "Bullet.h"
#include "Map.h"

class Player {
public:
	Player();
	~Player();

public:
	void SaveOldPlayer();
	void PlayerMove(int LInputX, int RInputX, int RInputY);
	void PlayerJump(int pad);
	void PlayerShot(int InputX, int InputY);
	void GetPlayer(int BLOCK_SIZE);
	void GetOldPlayer(int BLOCK_SIZE);
	void GetScroll();
	void BlockCollision(int map[][50]);

	void DrawPlayer();
public:
	PLAYER player;
	OldPlayer oldPlayer;

	//����̍��W
	int leftTopX, leftTopY;
	//�����̍��W
	int leftBottomX, leftBottomY;
	//�E���̍��W
	int rightTopX, rightTopY;
	//�E���̍��W
	int rightBottomX, rightBottomY;
	//1�t���[���O�̍���̍��W
	int oldLeftTopX, oldLeftTopY;
	//1�t���[���O�̉E��̍��W
	int oldRightTopX, oldRightTopY;
	//1�t���[���O�̍����̍��W
	int oldLeftBottomX, oldLeftBottomY;
	//1�t���[���O�̉E���̍��W
	int oldRightBottomX, oldRightBottomY;

	//�d��
	const int G = 8;

	//�X�N���[��
	int scroll;

	//�e
	Bullet* bullet;
	//�}�b�v
	Map* map;
};
