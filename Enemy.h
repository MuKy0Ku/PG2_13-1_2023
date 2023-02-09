#pragma once
#include"Object.h"
#include"Novice.h"

enum type
{
	LIGHTLEFT,
	UPDOWN,
};
class Enemy : public Object
{
private:
	int type_;

public:
	static bool isAlive_;
	Enemy(int radius, int posX, int posY, int type, int color);
	int getPosX() { return posX_; };
	int getPosY() { return posY_; };
	void Update() override;
	void Draw() override;
};

