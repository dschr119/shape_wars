#include <vector>
#include "GameEngine.h"

//initialization functions
void GameEngine::initializeGameWindow() {

	if (!textures[0].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/backdrop.png")) std::cout << "error" << std::endl;
	if (!textures[1].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/barracks.png")) std::cout << "error" << std::endl;
	if (!textures[2].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/base.png")) std::cout << "error" << std::endl;
	if (!textures[3].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/cruiser.png")) std::cout << "error" << std::endl;
	if (!textures[4].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/dreadnaut.png")) std::cout << "error" << std::endl;
	if (!textures[5].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/en_barracks.png")) std::cout << "error" << std::endl;
	if (!textures[6].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/en_base.png")) std::cout << "error" << std::endl;
	if (!textures[7].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/en_cruiser.png")) std::cout << "error" << std::endl;
	if (!textures[8].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/en_dreadnaut.png")) std::cout << "error" << std::endl;
	if (!textures[9].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/en_scout.png")) std::cout << "error" << std::endl;
	if (!textures[10].loadFromFile("C:/Users/David/source/repos/battle_bases/pics/scout.png")) std::cout << "error" << std::endl;


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

void GameEngine::initializeGameState() {}

void GameEngine::initializeSpriteSystem() {}

void GameEngine::initializeGuiSystem() {}

// game engine functions
void GameEngine::startGame() {

	window.create(sf::VideoMode(W, H), "SFML testing");

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