#include "Sprite.h"

void Sprite::setCoordinates( int newX, int newY ) {
  xCoord = newX;
  yCoord = newY;

  mySprite.setPosition( newX * 1.0f, newY * 1.0f );
}

void Sprite::setTexture( sf::Texture newTexture ) {
  // 
}