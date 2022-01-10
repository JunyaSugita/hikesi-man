#pragma once
#include "Global.h"

typedef struct {
	int x;
	int y;
} Transform;

//プレイヤーの定義
typedef struct {
	Transform transform;
	int r;
	int isJump;
	int jumpPow;
} PLAYER;

//前フレームのプレイヤーの定義
typedef struct {
	int x;
	int y;
}OldPlayer;

//水の発射
typedef struct {
	Transform transform;
	int r;
	float speedX;
	float speedY;
	int isBullet;
}BULLET;