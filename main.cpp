#include "include/Flower_Board.h"
#include "include/Chess_Piece.h"

#include "src/Flower_Board.cpp"
#include "src/Chess_Piece.cpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(480, 480), "Chess", sf::Style::Titlebar | sf::Style::Close);
  sf::Event event;

  Flower_Board board;

  King_Piece w_king(60, 60, "w_king.png");
  King_Piece b_king(0, 60, "b_king.png");

  Chess_Piece* pieces[] = {&w_king};

  while (window.isOpen())
  {
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

      if (event.key.code == sf::Keyboard::Escape)
      {
        window.close();
      }

    } 

    window.draw(board);

    for (size_t i = 0; i < sizeof(pieces) / sizeof(Chess_Piece*); i++)
    {
      Chess_Piece* piece = pieces[i];
    }

    window.draw(w_king);
    window.draw(b_king);

    window.display();
  }

  return 0;
}
