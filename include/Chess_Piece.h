#pragma once

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Chess_Piece : public sf::Drawable
{	

public:
  int pos_x = 0;
  int pos_y = 0;

  const std::string color = "";
  int piece_available_move_count = 0;   

protected:
  std::shared_ptr<sf::Texture> piece_texture;
  std::shared_ptr<sf::Sprite> piece_sprite;

public:
	Chess_Piece(const std::string&, int, int, const std::string&);

  auto virtual draw(sf::RenderTarget&, sf::RenderStates) const -> void override;
  auto virtual move_valid(int, int) -> bool;

public:
  auto load_texture(const std::string&) -> void;
  auto set_position(int, int) -> void;

};

class King_Piece : public Chess_Piece
{

public:
  King_Piece(const std::string&, int, int, const std::string&);

  auto move_valid(int, int) -> bool override;
};


class Queen_Piece: public Chess_Piece
{

public:
  Queen_Piece(const std::string&, int, int, const std::string&);
  
  auto move_valid(int, int) -> bool override;
};


class Bishop_Piece : public Chess_Piece
{

public:
  Bishop_Piece(const std::string&, int, int, const std::string&); 
  
  auto move_valid(int, int) -> bool override;
};

class Pawn_Piece : public Chess_Piece
{

public:
  Pawn_Piece(const std::string&, int, int, const std::string&); 

  auto move_valid(int, int) -> bool override;
};


class Rook_Piece : public Chess_Piece
{

public:
  Rook_Piece(const std::string&, int, int, const std::string&); 

  auto move_valid(int, int) -> bool override;
};

class Knight_Piece : public Chess_Piece
{

public:
  Knight_Piece(const std::string&, int, int, const std::string&); 

  auto move_valid(int, int) -> bool override;
};

