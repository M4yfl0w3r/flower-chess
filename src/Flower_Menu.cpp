#include "../include/Flower_Menu.h"
#include <cstdlib>

Flower_Menu::Flower_Menu()
{
  menu = std::make_unique<sf::RenderWindow>(sf::VideoMode(480, 480), "Chess", sf::Style::Titlebar | sf::Style::Close); 
}

void Flower_Menu::handle_events(sf::Event event)
{
  while (menu -> isOpen())
  { 
    menu -> clear(sf::Color::Black);

    while (menu -> pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        exit(-1);
      }
      
      else if (event.type == sf::Event::KeyPressed)
      {
        if (event.key.code == sf::Keyboard::Escape)
        {
          exit(-1);
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
          menu -> close();
        }
      }

      sf::Font my_font;

      if (!my_font.loadFromFile("../Roboto.ttf"))
      {
        exit(EXIT_FAILURE);
      }
      
      sf::Text welcome_text("Flower Chess", my_font, 40);
      welcome_text.setPosition(120, 10);
        
      sf::Text play_text("* Hit Enter to play *", my_font, 30);
      play_text.setPosition(120, 120);
      
      sf::Text exit_text("* Hit Esc to exit *", my_font, 30);
      exit_text.setPosition(120, 200);

      menu -> draw(play_text);
      menu -> draw(exit_text);
      menu -> draw(welcome_text);
      menu -> display();
    }
  }
}
