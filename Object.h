#pragma once
class Object
{
protected:
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
	int color_;


public:
	virtual void Update();
	virtual void Draw();
};

