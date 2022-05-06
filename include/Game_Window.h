#pragma once

#include "../include/Flower_Board.h"
#include "../include/Chess_Piece.h"

class Game_Window
{
  std::unique_ptr<sf::RenderWindow> game_window;
  
  inline static const int 
    width = 480,
    height = 480;

public:
  Game_Window();

  void handle_events(sf::Event, Flower_Board*);
};
