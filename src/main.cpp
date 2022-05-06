#include "../include/Flower_Board.h"
#include "../include/Chess_Piece.h"
#include "../include/Game_Window.h"
#include "../include/Flower_Menu.h"

int main()
{
  sf::Event event;
  Flower_Board board;

  Flower_Menu menu;
  menu.handle_events(event);

  Game_Window window;
  window.handle_events(event, &board);

  return 0;
}

