#pragma once
//bullet header - just the same as the one used at the end of the space invaders practical
// stored bullets in list of 256, etc 
//bullet.h

#pragma once
#include <SFML/Graphics.hpp>

class Bullets : public sf::Sprite {
public:
	//updates All bullets
	static void Update(const float& dt);
	//Render's All bullets
	static void Render(sf::RenderWindow& window);
	//Chose an inactive bullet and use it.
	static void Fire(const sf::Vector2f& pos, const bool mode);

	~Bullets() = default;


protected:

	static unsigned char bulletPointer;
	static Bullets bulletList[256];
	//Called by the static Update()
	void _Update(const float& dt);
	//Never called by our code
	Bullets();
	//false=player bullet, true=Enemy bullet
	bool _mode;
};