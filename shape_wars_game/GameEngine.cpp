#include <vector>
#include "GameEngine.h"

//initialization functions
void GameEngine::initializeGameWindow() {

	
}

void GameEngine::initializeGameState() {}


/*
 * This method initializes sprites
 * with textures and coordinates, 
 * handling possible errors
 */

void GameEngine::initializeSpriteSystem() {

  // load textures, if the texture exists, from the source file

  string fileNames[11] = { "backdrop", "barracks", "base", "cruiser", "dreadnaut", "en_barracks",
                           "en_base", "en_cruiser", "en_dreadnaut", "en_scout", "scout" };

  int i=0;
  for( string name : fileNames ) {
		if (!textures[i].loadFromFile(sourceFile + name +".png")) 
      std::cout << "error, could not load '" << name << "'" << std::endl;
    i++;
  }


	// set up bases

	base.setTexture(textures[2]);
	base_sprites.push_back(base);

	base0.setTexture(textures[6]);
	base_sprites.push_back(base0);

	base_sprites[0].setPosition(sf::Vector2f(0.0f, ((H / 2 - 23) * 1.0f)));
	base_sprites[1].setPosition(sf::Vector2f(((W - 30) * 1.0f), ((H / 2 - 23) * 1.0f)));


	// set up barracks

	for (int i = 0; i < 4; i++) {
		sf::Sprite barracks;
		barracks.setTexture(textures[1]);
		bar_sprites.push_back(barracks);
		bar_sprites[i].setPosition(sf::Vector2f(0.0f, ((i * (H / 4) + 30) * 1.0f)));
	}

	for (int i = 0; i < 4; i++) {
		sf::Sprite barracks0;
		barracks0.setTexture(textures[5]);
		en_bar_sprites.push_back(barracks0);
		en_bar_sprites[i].setPosition(sf::Vector2f(((W - 30) * 1.0f), ((i * (H / 4) + 30) * 1.0f)));
	}
  

}

void GameEngine::initializeGuiSystem() {}

// game engine functions

/*
 * This method contains the main game loop
 * It takes no inputs
 * 
 */

void GameEngine::startGame() {

	window.create(sf::VideoMode(W, H), "battle base testing");

	while (window.isOpen()) {
    
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();         // <-- clear the window

								// draw bases
		for (int i = 0; i < 2; i++) window.draw(base_sprites[i]);
		// draw barracks
		for (int i = 0; i < 4; i++) window.draw(bar_sprites[i]);
		for (int i = 0; i < 4; i++) window.draw(en_bar_sprites[i]);
		// draw units
		for (int i = 0; i < units; i++) window.draw(unit_sprites[i]);
		for (int i = 0; i < en_units; i++) window.draw(en_unit_sprites[i]);

		window.display();       // <-- display the window with the things drawn 
	}

}