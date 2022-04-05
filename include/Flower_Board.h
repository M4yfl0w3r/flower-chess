#pragma once

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include "Chess_Piece.h"

#include "flower_vector.h"
#include "../src/flower_vector.cpp"

class Flower_Board : public sf::Drawable
{
	int square_size = 0;
  
  Flower_Vector<Chess_Piece*> remaining_pieces; 

public:
  int mouse_pos_x = 0;
  int mouse_pos_y = 0;

  bool mouse_pressed = false;
  bool piece_clicked = false;

  // index of current clicked piece
  int current_piece_to_move = 1000;
  int piece_in_danger = 1000;

  int move_count = 0;

  std::string color_to_move = "";
  std::string color_chosen = "";

  int x_update = 0;
  int y_update = 0;

public:
	Flower_Board();

public:
  auto piece_chosen(int*, int, int) -> int;
  auto field_empty(int, int) -> bool;
  auto update_piece_position(int, int) -> void;
  auto check_turn(int) -> void;
  auto on_mouse_pressed(int, int) -> void;
  auto on_mouse_moved(int, int) -> void;
  auto on_mouse_released(int, int) -> void;

private:
	auto draw(sf::RenderTarget&, sf::RenderStates) const -> void override;

};
