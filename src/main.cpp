#include "../include/Flower_Board.h"
#include "../include/Chess_Piece.h"
#include "../include/Game_Window.h"

int main()
{
  sf::Event event;
  Flower_Board board;
  
  Game_Window window;
  window.handle_events(event, &board);


  return 0;
}

