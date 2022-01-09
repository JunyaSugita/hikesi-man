#include "Player.h"

Player::Player() {
	player = {
		{
			100,
			800
		},
		20,
		0,
		0
	};

	oldPlayer = {
		0,
		0
	};

	//左上の座標
	leftTopX = 0;
	leftTopY = 0;
	//左下の座標
	leftBottomX = 0;
	leftBottomY = 0;
	//右下の座標
	rightTopX = 0;
	rightTopY = 0;
	//右下の座標
	rightBottomX = 0;
	rightBottomY = 0;
	//1フレーム前の左上の座標
	oldLeftTopX = 0;
	oldLeftTopY = 0;
	//1フレーム前の右上の座標
	oldRightTopX = 0;
	oldRightTopY = 0;
	//1フレーム前の左下の座標
	oldLeftBottomX = 0;
	oldLeftBottomY = 0;
	//1フレーム前の右下の座標
	oldRightBottomX = 0;
	oldRightBottomY = 0;

	scroll = 0;
}

Player::~Player() {}

void Player::SaveOldPlayer() {
	oldPlayer.x = player.transform.x;
	oldPlayer.y = player.transform.y;
}

void Player::PlayerMove(int InputX) {
	if (InputX > 0 || InputX < 0) {
		player.transform.x += InputX / 200;
	}
	player.transform.y += G - player.jumpPow;
}

void Player::PlayerJump(int pad) {
	if (pad & PAD_INPUT_1 && player.isJump == 0) {
		player.isJump = 1;
		player.jumpPow = 20;
	}

	if (player.isJump == 1) {
		player.jumpPow --;
	}
}

void Player::GetPlayer(int BLOCK_SIZE) {
	//左上の座標の取得
	leftTopX = (player.transform.x - player.r) / BLOCK_SIZE;
	leftTopY = (player.transform.y - player.r) / BLOCK_SIZE;
	//右上の座標の取得
	rightTopX = (player.transform.x + player.r - 1) / BLOCK_SIZE;
	rightTopY = (player.transform.y - player.r) / BLOCK_SIZE;
	//左下の座標の取得
	leftBottomX = (player.transform.x - player.r) / BLOCK_SIZE;
	leftBottomY = (player.transform.y + player.r - 1) / BLOCK_SIZE;
	//右下の座標の取得
	rightBottomX = (player.transform.x + player.r - 1) / BLOCK_SIZE;
	rightBottomY = (player.transform.y + player.r - 1) / BLOCK_SIZE;
}

void Player::GetOldPlayer(int BLOCK_SIZE) {
	//1フレーム前の左上の座標の取得
	oldLeftTopX = (oldPlayer.x - player.r) / BLOCK_SIZE;
	oldLeftTopY = (oldPlayer.y - player.r) / BLOCK_SIZE;
	//1フレーム前の右上の座標の取得
	oldRightTopX = (oldPlayer.x + player.r - 1) / BLOCK_SIZE;
	oldRightTopY = (oldPlayer.y - player.r) / BLOCK_SIZE;
	//1フレーム前の左下の座標の取得
	oldLeftBottomX = (oldPlayer.x - player.r) / BLOCK_SIZE;
	oldLeftBottomY = (oldPlayer.y + player.r - 1) / BLOCK_SIZE;
	//1フレーム前の右下の座標の取得
	oldRightBottomX = (oldPlayer.x + player.r - 1) / BLOCK_SIZE;
	oldRightBottomY = (oldPlayer.y + player.r - 1) / BLOCK_SIZE;
}

void Player::GetScroll() {
	if (player.transform.x >= WIN_WIDTH / 2 && player.transform.x <= WIN_WIDTH + (WIN_WIDTH / 2)) {
		scroll = player.transform.x - WIN_WIDTH / 2;
	}
}


void Player::DrawPlayer() {
	DrawBox(player.transform.x - player.r - scroll, player.transform.y - player.r,
		player.transform.x + player.r - scroll, player.transform.y + player.r, GetColor(200, 200, 200), true);
}