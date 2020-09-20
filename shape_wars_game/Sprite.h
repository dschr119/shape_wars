#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Sprite {

private:

  sf::Sprite mySprite_;
  sf::Texture myTexture_;

  int xCoord_, yCoord_;

public:

  Sprite( int x, int y, sf::Texture texture , sf::Sprite sprite) {

    xCoord_ = x;
    yCoord_ = y;

    mySprite_ = sprite;
    myTexture_ = texture;

  }

  void setCoordinates( int, int );
  void setTexture( sf::Texture );

};