#include "Rescued.h"

//コンストラクタ
Rescued::Rescued() {
	transform = {
		0,
		0
	};
	r = 20;
	isRescued = false;
	player = new Player;
}

//デストラクタ
Rescued::~Rescued() {
	delete player;
}

///-----クラス関数-----///

//当たり判定
void Rescued::RescuedCollision() {
	if (isRescued == false) {
		if (transform.x + r > player->player.transform.x - player->player.r && player->player.transform.x + player->player.r > transform.x - r) {
			if (transform.y + r > player->player.transform.y - player->player.r && player->player.transform.y + player->player.r > transform.y - r) {
				isRescued = true;
			}
		}
	}
}

//移動関数
void Rescued::Move() {
	if (isRescued == true) {
		transform.x = player->player.transform.x;
		transform.y = player->player.transform.y;
	}
}

//描画関数
void Rescued::Draw() {
	DrawBox(transform.x - r, transform.y - r, transform.x + r, transform.y + r, GetColor(255, 255, 255), true);
}