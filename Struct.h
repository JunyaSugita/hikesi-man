#pragma once
#include "Global.h"

//プレイヤーの定義
typedef struct {
	int x;
	int y;
} Transform;

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