#include <Novice.h>
#include"Enemy.h"
#include"Player.h"
#include<math.h>

const char kWindowTitle[] = "GC1A_02_イワサキリョウマ";

bool Enemy::isAlive_;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Enemy* enemyA = new Enemy(16, 50, 400, UPDOWN, RED);
	Enemy* enemyB = new Enemy(16, 200, 30, LIGHTLEFT, BLUE);

	Player* player = new Player(400, 700);


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		/*if (Enemy::isAlive_)
		{*/
		enemyA->Update();
		enemyB->Update();
		//}


		player->Update(keys, preKeys);

		for (int i = 0; i < 5; i++)
		{
			float a, b, c;
			a = player->getBulletPos_(i).x - enemyA->getPosX();
			b = player->getBulletPos_(i).y - enemyA->getPosY();
			c = sqrtf(pow(a, 2) + pow(b, 2));

			if (c <= 50)
			{
				Enemy::isAlive_ = false;
			}

			float d, e, f;
			d = player->getBulletPos_(i).x - enemyB->getPosX();
			e = player->getBulletPos_(i).y - enemyB->getPosY();
			f = sqrtf(pow(d, 2) + pow(e, 2));

			if (f <= 50)
			{
				Enemy::isAlive_ = false;
			}
		}

		if (keys[DIK_R] && preKeys[DIK_R] == 0)
		{
			Enemy::isAlive_ = true;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		/*if (Enemy::isAlive_)
		{*/
		enemyA->Draw();
		enemyB->Draw();
		//}
		player->Draw();
		///
		/// ↑描画処理ここまで
		///


		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
