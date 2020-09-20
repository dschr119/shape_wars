#include "Sprite.h"

void Sprite::setCoordinates( int newX, int newY ) {
  xCoord_ = newX;
  yCoord_ = newY;

  mySprite_.setPosition( newX * 1.0f, newY * 1.0f );
}

void Sprite::setTexture( sf::Texture newTexture ) {
  
  myTexture_ = newTexture;
  mySprite_.setTexture( myTexture_ );

}