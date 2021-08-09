#pragma once
#include "Entity.h";

class Bullets : public Entity {
private:
	float _speed;

public:
	void Update(double dt) override;
	void Fire(float x, float y, float angle, int type);
	Bullets();
	void Render() override;


};