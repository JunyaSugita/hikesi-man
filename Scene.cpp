#include "Scene.h"

//コンストラクタ
Scene::Scene() {
	player = new Player;
	bullet = new Bullet;
	rescued = new Rescued;
	map = new Map;
	fire = new Fire;
}

//コンストラクタ
Scene::~Scene() {
	delete player;
	delete bullet;
	delete rescued;
	delete map;
	delete fire;
}


///-----関数-----///
void Scene::Update(char* keys,char* oldkeys) {
	if (keys == nullptr || oldkeys == nullptr) {
		printf("null\n");
		return;
	}
	GetJoypadDirectInputState(DX_INPUT_PAD1, &padInput);
	pad = GetJoypadInputState(DX_INPUT_PAD1);

	//マップ選択
	map->SelectMap1();

	//火の設置
	if (keys[KEY_INPUT_F] == 1) {
		fire->SetFire(map->map);
	}

	//プレイヤー位置の保存
	player->SaveOldPlayer();

	//プレイヤーの移動
	player->PlayerMove(padInput.X, padInput.Rx, padInput.Ry);
	player->PlayerJump(pad);

	//弾の発射
	player->PlayerShot(padInput.Rx, padInput.Ry);

	//弾の挙動
	player->bullet->BulletMove(player->G);

	//消化
	fire->FireFighting(player->bullet->bullet);

	//マップチップ上の座標位置の取得
	player->GetPlayer(map->BLOCK_SIZE);
	player->GetOldPlayer(map->BLOCK_SIZE);
	player->bullet->GetBullet(map->BLOCK_SIZE);

	//当たり判定
	player->BlockCollision(map->map);
	player->bullet->BlockCollision(map->map);

	//スクロール
	player->GetScroll();
}

void Scene::Draw() {
	// 描画処理
	fire->DrawFire(player->scroll);
	map->DrawMap(map->map, player->scroll);
	player->DrawPlayer();
	player->bullet->DrawBullet(player->scroll);

	//デバッグ
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBox(0, 0, 500, 100, GetColor(255, 255, 255), true);
	DrawFormatString(0, 0, GetColor(50, 50, 50), "X:%d Y:%d Z:%d",
		padInput.X, padInput.Y, padInput.Z);
	DrawFormatString(0, 16, GetColor(50, 50, 50), "Rx:%d Ry:%d Rz:%d",
		padInput.Rx, padInput.Ry, padInput.Rz);

	DrawFormatString(0, 32, GetColor(50, 50, 50), "左スティック：移動　右スティック：放水(左のみ)");
	DrawFormatString(0, 48, GetColor(50, 50, 50), "LB:ジャンプ");
	DrawFormatString(0, 64, GetColor(50, 50, 50), "Fキー:放火(デバッグ用)");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}