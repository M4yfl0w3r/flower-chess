#pragma once

#include "../include/Flower_Board.h"
#include "../include/Chess_Piece.h"

#include <stdlib.h>

class Flower_Menu 
{
  std::unique_ptr<sf::RenderWindow> menu;

  inline static constexpr int width {480};
  inline static constexpr int height {480};

public:
  Flower_Menu();

  void handle_events(sf::Event);
};
