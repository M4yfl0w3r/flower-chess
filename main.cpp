#include "include/Flower_Board.h"
#include "include/Chess_Piece.h"

#include "src/Flower_Board.cpp"
#include "src/Chess_Piece.cpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(480, 480), "Chess", sf::Style::Titlebar | sf::Style::Close);
  sf::Event event;

  Flower_Board board;

  while (window.isOpen())
  {
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

      else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
      {

      }


      if (event.key.code == sf::Keyboard::Escape)
      {
        window.close();
      }
    } 
    
    window.draw(board);
 

    window.display();
  }

  return 0;
}
