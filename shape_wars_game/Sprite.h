#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Sprite {

private:

  sf::Sprite mySprite;
  sf::Texture myTexture;

  int xCoord,yCoord;

public:

  Sprite() {}

  void setCoordinates( int, int );
  void setTexture( sf::Texture );

};