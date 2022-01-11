#include "Goal.h"

//�R���X�g���N�^
Goal::Goal() {
	player = new Player;
	rescued = new Rescued;
	isGoal = false;
	x = 144;
}

//�f�X�g���N�^
Goal::~Goal() {
	delete player;
	delete rescued;
}


///-----�N���X�֐�-----///
void Goal::GetGoal(Player* player, Rescued* rescued) {
	if (rescued->isRescued == true) {
		if (player->player.transform.x + player->player.r > x - 96 && x > player->player.transform.x - player->player.r) {
			if (isGoal == false) {
				isGoal = true;
			}
		}
	}
}

void Goal::Draw(Rescued* rescued, int scroll) {
	if (rescued->isRescued == true) {
		if (isGoal == false) {
			DrawBox(x - 96 - scroll, 812, x - scroll, 912, GetColor(255, 255, 0), false);
		}
		else {
			DrawBox(x - 96 - scroll, 812, x - scroll, 912, GetColor(255, 255, 0), true);
		}
	}
}