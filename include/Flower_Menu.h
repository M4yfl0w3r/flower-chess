#pragma once

#include "../include/Flower_Board.h"
#include "../include/Chess_Piece.h"

#include <stdlib.h>

class Flower_Menu 
{
  std::unique_ptr<sf::RenderWindow> menu;

  inline static const int 
    width = 480,
    height = 480;

public:
  Flower_Menu();

  void handle_events(sf::Event);
};
