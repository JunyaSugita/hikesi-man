#pragma once
#include "Struct.h"

class Map{
public:
	Map();
	~Map();

public:
	int map1(int y, int x);
public:
	int map[20][50];
	int mapCountX;
	int mapCountY;

	const int BLOCK_SIZE = 48;
};

