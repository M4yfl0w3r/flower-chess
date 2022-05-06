#include "../include/Game_Window.h"

Game_Window::Game_Window()
{
  game_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(480, 480), "Chess", sf::Style::Titlebar | sf::Style::Close); 
}

void Game_Window::handle_events(sf::Event event, Flower_Board* board)
{
  while (game_window -> isOpen())
  {
    while (game_window -> pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        game_window -> close();
      }

      else if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Escape)
        {
          game_window -> close();
        }
      }

      else if (event.type == sf::Event::MouseButtonPressed) 
      {
        board -> on_mouse_pressed(sf::Mouse::getPosition(*game_window).x, sf::Mouse::getPosition(*game_window).y);
      }

      else if (event.type == sf::Event::MouseMoved)
      {
        board -> on_mouse_moved(sf::Mouse::getPosition(*game_window).x, sf::Mouse::getPosition(*game_window).y);  
      }

      else if (event.type == sf::Event::MouseButtonReleased)
      {
        board -> on_mouse_released();
      } 
    } 

    if (board -> lost)
    {
      game_window -> close();
    }

    game_window -> draw(*board); 
    game_window -> display(); 
  }
}
