#include "Player.h"
#include "Bullet.h"
#include "Map.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言

	//スティック操作
	DINPUT_JOYSTATE padInput;
	int pad;


	//プレイヤー
	Player* player = new Player();
	//水
	Bullet* bullet = new Bullet();
	//マップ
	Map* map = new Map();

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}
		//配列なのでoldkey - keys;のようにできない。要素を１つずつコピー

		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		GetJoypadDirectInputState(DX_INPUT_PAD1, &padInput);
		pad = GetJoypadInputState(DX_INPUT_PAD1);

		//マップ選択
		map->SelectMap1();

		//プレイヤー位置の保存
		player->SaveOldPlayer();

		//プレイヤーの移動
		player->PlayerMove(padInput.X, padInput.Rx, padInput.Ry);
		player->PlayerJump(pad);

		//弾の発射
		player->PlayerShot(padInput.Rx, padInput.Ry);

		//弾の挙動
		player->bullet->BulletMove(player->G);

		//マップチップ上の座標位置の取得
		player->GetPlayer(map->BLOCK_SIZE);
		player->GetOldPlayer(map->BLOCK_SIZE);
		bullet->GetBullet(map->BLOCK_SIZE);

		//当たり判定
		player->BlockCollision(map->map);
		bullet->BlockCollision(map->map);

		//スクロール
		player->GetScroll();

		// 描画処理
		map->DrawMap(map->map, player->scroll);
		player->DrawPlayer();
		player->bullet->DrawBullet(player->scroll);

		//デバッグ
		DrawFormatString(0, 0, GetColor(255, 255, 255), "X:%d Y:%d Z:%d",
			padInput.X, padInput.Y, padInput.Z);
		DrawFormatString(0, 16, GetColor(255, 255, 255), "Rx:%d Ry:%d Rz:%d",
			padInput.Rx, padInput.Ry, padInput.Rz);

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}

	delete player;
	delete bullet;
	delete map;

	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
