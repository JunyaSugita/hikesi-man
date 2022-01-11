#include "Bullet.h"

Bullet::Bullet() {
	for (int i = 0; i < BULLET_CONST; i++) {
		bullet[i] = {
			{
				0,
				0
			},
			16,
			0,
			0,
			false
		};
		//����̍��W
		leftTopX[i] = 0;
		leftTopY[i] = 0;
		//�����̍��W
		leftBottomX[i] = 0;
		leftBottomY[i] = 0;
		//�E���̍��W
		rightTopX[i] = 0;
		rightTopY[i] = 0;
		//�E���̍��W
		rightBottomX[i] = 0;
		rightBottomY[i] = 0;
	}

	map = new Map;
}

Bullet::~Bullet() {
	delete map;
}

void Bullet::BulletShot(Transform transform, int x, int y) {
	for (int i = 0; i < BULLET_CONST; i++) {
		if (bullet[i].isBullet == false) {
			bullet[i].isBullet = true;
			bullet[i].transform = transform;
			bullet[i].speedX = x / 50;
			bullet[i].speedY = y / 50;
			break;
		}
	}
}

void Bullet::BulletMove(const int G) {
	for (int i = 0; i < BULLET_CONST; i++) {
		if (bullet[i].isBullet == true) {
			bullet[i].transform.x += bullet[i].speedX;
			bullet[i].transform.y += bullet[i].speedY;
			bullet[i].speedY++;
		}
	}
}

void Bullet::GetBullet(int BLOCK_SIZE) {
	for (int i = 0; i < BULLET_CONST; i++) {
		//����̍��W�̎擾
		leftTopX[i] = (bullet[i].transform.x - bullet[i].r) / BLOCK_SIZE;
		leftTopY[i] = (bullet[i].transform.y - bullet[i].r) / BLOCK_SIZE;
		//�E��̍��W�̎擾
		rightTopX[i] = (bullet[i].transform.x + bullet[i].r - 1) / BLOCK_SIZE;
		rightTopY[i] = (bullet[i].transform.y - bullet[i].r) / BLOCK_SIZE;
		//�����̍��W�̎擾
		leftBottomX[i] = (bullet[i].transform.x - bullet[i].r) / BLOCK_SIZE;
		leftBottomY[i] = (bullet[i].transform.y + bullet[i].r - 1) / BLOCK_SIZE;
		//�E���̍��W�̎擾
		rightBottomX[i] = (bullet[i].transform.x + bullet[i].r - 1) / BLOCK_SIZE;
		rightBottomY[i] = (bullet[i].transform.y + bullet[i].r - 1) / BLOCK_SIZE;
	}
}

void Bullet::BlockCollision(int map[][50]) {
	for (int i = 0; i < 500; i++) {
		if (bullet[i].isBullet == true) {
			if (map[leftTopY[i]][leftTopX[i]] == BLOCK) {
				bullet[i].isBullet = false;
			}
			if (map[leftBottomY[i]][leftBottomX[i]] == BLOCK) {
				bullet[i].isBullet = false;
			}
			if (map[rightTopY[i]][rightTopX[i]] == BLOCK) {
				bullet[i].isBullet = false;
			}
			if (map[rightBottomY[i]][rightBottomX[i]] == BLOCK) {
				bullet[i].isBullet = false;
			}
		}
	}
}


void Bullet::DrawBullet(int scroll) {
	for (int i = 0; i < BULLET_CONST; i++) {
		if (bullet[i].isBullet == true) {
			DrawCircle(bullet[i].transform.x - scroll, bullet[i].transform.y, bullet[i].r, GetColor(0, 0, 255), true);
		}
	}
}