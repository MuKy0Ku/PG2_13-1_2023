#include "Bullet.h"
#include"Novice.h"

Bullet::Bullet(int damage, int speed, float* posX, float* posY)
{
	this->damage = damage;
	this->returnPos.x = *posX;
	this->returnPos.y = *posY;
	this->speed = speed;
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	Shoot();
	Draw();
}

void Bullet::Shoot()
{
	if (isShooting)
	{
		pos.y -= speed;
	}
	else {
		pos.x = returnPos.x;
		pos.y = returnPos.y;
	}


	if (pos.y <= 0)
	{
		isShooting = 0;
	}
}
void Bullet::Draw()
{
	Novice::DrawEllipse(pos.x, pos.y, 8, 8, 0.0f, WHITE, kFillModeSolid);
}

