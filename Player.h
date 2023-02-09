#include"Struct.h"
#include"Bullet.h"
#pragma once
class Player
{
public:
	Vector2 vec = {
		0.0f,0.0f
	};
	Vector2 normal;

	float length;

	Vector2 newPos;

	Vector2 pos = { 400,400 };

	float speed = 8;

	int cooldown = 0;

	//bullet
	int bulletCount = 0;
	const int maxBullet = 5;

	Bullet bullet_[5] = {
		Bullet(1,5,&pos.x,&pos.y),
		bullet_[0],
		bullet_[0],
		bullet_[0],
		bullet_[0]
	};

	//functions
	void Update(char* keys, char* preKeys);
	void Shoot(char* keys, char* preKeys);
	void Move(char* keys, char* preKeys);
	Vector2 getBulletPos_(int i) { return bullet_[i].pos; };
	void Draw();
	Player(int posX, int posY);
	~Player();
};

