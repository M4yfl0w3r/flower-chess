#include "include/Flower_Board.h"
#include "include/Chess_Piece.h"

#include "src/Flower_Board.cpp"
#include "src/Chess_Piece.cpp"
#include <SFML/Window/Mouse.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(480, 480), "Chess", sf::Style::Titlebar | sf::Style::Close);
  sf::Event event;

  Flower_Board board;

  while (window.isOpen())
  {
    window.clear(sf::Color::White);

    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

      else if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Escape)
        {
          window.close();
        }
      }

      else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) 
      {
        board.on_mouse_pressed(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
      }

      else if (event.type == sf::Event::MouseMoved)
      {
        board.on_mouse_moved(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);  
      }

      else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
      {
        board.on_mouse_released(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
      } 
    } 

    window.draw(board);
 
    window.display();
  }

  return 0;
}
