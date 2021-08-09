#pragma once
<<<<<<< Updated upstream
//inherits from ships, which inhertis from entity
//has ai shooting and movement
=======
#include "Entity.h";


//enemy class, will be able to shoot based on ai, avoid planets, explode and drop fuel.
class Enemy : public Entity {

public:
	void Update(double dt) override;
	//constructor
	Enemy();
	void Render() override;


private:
	//set speed
	float _speed;
	//number of lives - number will be determined on what type 
	int _lives;
};
>>>>>>> Stashed changes
