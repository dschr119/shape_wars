#pragma once

class GameEngine {
private:


  // initialization functions
  void initializeGameWindow();
  void initializeGameState();
  void initializeSpriteSystem();
  void initializeGuiSystem();

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