#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include "Chess_Piece.h"
#include "flower_vector.h"
#include "../src/flower_vector.cpp"

class Flower_Board : public sf::Drawable
{
	inline static const int square_size = 60;
  
  Flower_Vector<Chess_Piece*> remaining_pieces; 

public:
  int 
    mouse_pos_x = 0,
    mouse_pos_y = 0,
    current_piece_to_move = 1000,   // index of current clicked piece
    piece_in_danger = 1000,   // index of piece to be captured
    // piece_on_path = 1000,  
    x_update = 0,
    y_update = 0;

  inline static bool 
    mouse_pressed = false,
    to_capture = false,
    piece_clicked = false,
    lost = false;

  std::string 
    color_to_move = "white",
    color_chosen = "";

public:
	Flower_Board();

public:
  auto on_mouse_pressed(int, int) -> void;
  auto on_mouse_moved(int, int) -> void;
  auto on_mouse_released() -> void;

private:
  auto piece_chosen(int*, int, int) -> int;
  auto field_empty(int, int) const -> bool;
  // auto check_path(std::pair<int, int>) -> bool;
  auto update_piece_position(int, int) -> void;
  auto change_turn(int) -> void;

private:
	auto draw(sf::RenderTarget&, sf::RenderStates) const -> void override;
};

