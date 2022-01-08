#pragma once

typedef struct {
	int x;
	int y;
} Transform;

typedef struct {
	Transform transform;
	int speed;
} PLAYER;