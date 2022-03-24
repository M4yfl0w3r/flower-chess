#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <memory>

class Chess_Piece : public sf::Drawable
{	

protected:
  std::shared_ptr<sf::Texture> piece_texture;
  std::shared_ptr<sf::Sprite> piece_sprite;

public:
	Chess_Piece(const std::string&, int, int);

  auto virtual draw(sf::RenderTarget&, sf::RenderStates) const -> void;

  auto load_texture(const std::string&) -> void;
  auto set_position(double x, double y) -> void;

};

class King_Piece : public Chess_Piece
{

public:
  King_Piece(const std::string&, int, int);
};


class Queen_Piece: public Chess_Piece
{

public:
  Queen_Piece(const std::string&, int, int);
};


class Bishop_Piece : public Chess_Piece
{

public:
  Bishop_Piece(const std::string&, int, int); 
};

class Pawn_Piece : public Chess_Piece
{

public:
  Pawn_Piece(const std::string&, int, int); 
};


class Rook_Piece : public Chess_Piece
{

public:
  Rook_Piece(const std::string&, int, int); 
};

class Knight_Piece : public Chess_Piece
{

public:
  Knight_Piece(const std::string&, int, int); 
};
