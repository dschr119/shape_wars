#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;


class GameEngine {
private:

  // window data
	const int H = 400;
	const int W = 800;
	sf::RenderWindow window(sf::VideoMode(W, H), "SFML testing");

  // initialization functions
  void initializeGameWindow();
  void initializeGameState();
  void initializeSpriteSystem();
  void initializeGuiSystem();

  // game data
	sf::Texture textures[11];              // <-- create textures array
	vector<sf::Sprite> bar_sprites;        // <-- create sprites vectors
	vector<sf::Sprite> en_bar_sprites;
	vector<sf::Sprite> unit_sprites;
	vector<sf::Sprite> en_unit_sprites;
	vector<sf::Sprite> base_sprites;

	sf::Sprite base;
	sf::Sprite base0;

  // game engine functions
  void startGame();

public:

  GameEngine() {

    // initialize a game window
    initializeGameWindow();

    // set up :

    //  game state system,
    initializeGameState();
    //  sprite/animation system,
    initializeSpriteSystem();
    //  GUI system
    initializeGuiSystem();

    // run main window loop
    startGame();
  }

};