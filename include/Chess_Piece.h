#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Chess_Piece : public sf::Drawable
{	

protected:
	double pos_x = 0;
	double pos_y = 0;

  sf::Texture* king_texture;
  sf::Sprite* king_sprite;

public:
	Chess_Piece(double, double, const std::string&);

  auto virtual draw(sf::RenderTarget&, sf::RenderStates) const -> void;

  auto load_texture(const std::string&) -> void;


};

class King_Piece : public Chess_Piece
{

public:
  King_Piece(double x, double y, const std::string&);
};
