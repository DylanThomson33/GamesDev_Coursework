#pragma once
//bullet header - just the same as the one used at the end of the space invaders practical
// stored bullets in list of 256, etc 

//Cancel that, just make it 32 per entity that can shoot and declare it in a struct. Nice and easy that way. 

#include <SFML/Graphics.hpp>

class Bullets : public sf::Sprite {

public:

	void Update(const float& dt);
	Bullets(const sf::Vector2f& pos, const int firedBy, float angle);
	~Bullets() = default;
	Bullets();

protected:
	int firedBy; //0 = player, //1 = enemy, //2 = something else?
};