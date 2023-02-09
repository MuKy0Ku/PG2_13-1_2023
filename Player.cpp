#include "Player.h"
#include"Novice.h"
#define _USE_MATH_DEFINES
#include<math.h>

Player::Player(int posX, int posY)
{
	this->pos.x = posX;
	this->pos.y = posY;
}

void Player::Move(char* keys, char* preKeys)
{


	if (keys[DIK_W])
	{
		vec.y = -speed;
	}
	else if (keys[DIK_S])
	{
		vec.y = speed;
	}
	else
	{
		vec.y = 0;
	}
	if (keys[DIK_A])
	{
		vec.x = -speed;
	}
	else if (keys[DIK_D])
	{
		vec.x = speed;
	}
	else
	{
		vec.x = 0;
	}

	if (keys[DIK_W] && keys[DIK_A])
	{
		vec.y = -speed;
		vec.x = -speed;
	}
	if (keys[DIK_W] && keys[DIK_D])
	{
		vec.y = -speed;
		vec.x = +speed;
	}
	if (keys[DIK_S] && keys[DIK_A])
	{
		vec.y = +speed;
		vec.x = -speed;
	}
	if (keys[DIK_S] && keys[DIK_D])
	{
		vec.y = +speed;
		vec.x = +speed;
	}



	if (vec.x != 0 || vec.y != 0)
	{
		length = sqrtf(pow(vec.x, 2) + pow(vec.y, 2));
		normal.x = vec.x / length;
		normal.y = vec.y / length;

		normal.x *= speed;
		normal.y *= speed;

		pos.x += normal.x;
		pos.y += normal.y;
	}

}

void Player::Shoot(char* keys, char* preKeys)
{
	cooldown--;
	if (keys[DIK_SPACE])
	{
		for (int i = bulletCount; i < maxBullet; i++)
		{
			if (cooldown <= 30)
			{
				bullet_[i].isShooting = 1;
				bulletCount++;
				cooldown = 60;
			}
			break;
		}
	}
	for (int i = 0; i < maxBullet; i++)
	{
		bullet_[i].returnPos = pos;
		bullet_[i].Update();
	}
	if (bulletCount >= maxBullet)
	{
		bulletCount = 0;
	}
}

void Player::Update(char* keys, char* preKeys)
{
	this->Move(keys, preKeys);
	this->Shoot(keys, preKeys);
}

void Player::Draw()
{
	Novice::DrawEllipse(pos.x, pos.y, 16, 16, 0, WHITE, kFillModeSolid);
}


