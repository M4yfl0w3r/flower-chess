#include "../include/Flower_Board.h"
#include <ios>

Flower_Board::Flower_Board() : square_size{60}
{
  remaining_pieces.flower_push_back(new Rook_Piece("b_rook.png", 0, 0, "white"));
  remaining_pieces.flower_push_back(new Rook_Piece("w_rook.png", 0, 7, "black"));
  remaining_pieces.flower_push_back(new Rook_Piece("b_rook.png", 7, 0, "black"));
  remaining_pieces.flower_push_back(new Rook_Piece("w_rook.png", 7, 7, "white"));

  remaining_pieces.flower_push_back(new Knight_Piece("b_knight.png", 1, 0, "black"));
  remaining_pieces.flower_push_back(new Knight_Piece("w_knight.png", 1, 7, "white"));
  remaining_pieces.flower_push_back(new Knight_Piece("b_knight.png", 6, 0, "black"));
  remaining_pieces.flower_push_back(new Knight_Piece("w_knight.png", 6, 7, "white"));

  remaining_pieces.flower_push_back(new Bishop_Piece("b_bishop.png", 2, 0, "black"));
  remaining_pieces.flower_push_back(new Bishop_Piece("w_bishop.png", 2, 7, "white"));
  remaining_pieces.flower_push_back(new Bishop_Piece("b_bishop.png", 5, 0, "black"));
  remaining_pieces.flower_push_back(new Bishop_Piece("w_bishop.png", 5, 7, "white"));

  remaining_pieces.flower_push_back(new Queen_Piece("b_queen.png", 3, 0, "black"));
  remaining_pieces.flower_push_back(new Queen_Piece("w_queen.png", 3, 7, "white"));
  
  remaining_pieces.flower_push_back(new King_Piece("b_king.png", 4, 0, "black"));
  remaining_pieces.flower_push_back(new King_Piece("w_king.png", 4, 7, "white"));

  for (int i = 0; i < 8; i++)
    remaining_pieces.flower_push_back(new Pawn_Piece("w_pawn.png", i, 6, "white"));

  for (int i = 0; i < 8; i++)
    remaining_pieces.flower_push_back(new Pawn_Piece("b_pawn.png", i, 1, "black"));
}

auto Flower_Board::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void
{
	sf::RectangleShape rect;	

	auto colors = std::make_tuple(sf::Color (234,182,118), sf::Color (153, 76, 0));

	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2)
				rect.setFillColor(std::get<1>(colors));
			
			else
				rect.setFillColor(std::get<0>(colors));
			
			rect.setPosition(sf::Vector2f(static_cast<float>(i)*square_size, static_cast<float>(j)*square_size));	
			rect.setSize(sf::Vector2f(static_cast<float>(square_size), static_cast<float>(square_size)));

			target.draw(rect);	
		}
	}

  for (size_t i = 0; i < remaining_pieces.flower_size(); i++)
  {
    remaining_pieces[i] -> draw(target, states);
  }  
}

auto Flower_Board::on_mouse_pressed(int x, int y) -> void
{
  mouse_pos_x = x / square_size;
  mouse_pos_y = y / square_size;

  mouse_pressed = true;
 
  if (!field_empty(mouse_pos_x, mouse_pos_y))
  {
    piece_clicked = true;
  }
}

auto Flower_Board::on_mouse_moved(int x, int y) -> void
{
  mouse_pos_x = x / square_size;
  mouse_pos_y = y / square_size;

  if (mouse_pressed && piece_clicked) 
  {
    if (remaining_pieces[current_piece_to_move] -> move_valid(mouse_pos_x, mouse_pos_y))
    {
      update_piece_position(mouse_pos_x, mouse_pos_y);
    }
  }

}

auto Flower_Board::on_mouse_released(int x, int y) -> void
{
  mouse_pressed = false;
  piece_clicked = false;
}

auto Flower_Board::field_empty(int x, int y) -> bool
{
  for (std::size_t i = 0; i < remaining_pieces.flower_size(); i++)
  {
    if (remaining_pieces[i] -> pos_x == x && remaining_pieces[i] -> pos_y == y)
    {
      current_piece_to_move = i;
      return false; 
    }
  }

  return true;
}

auto Flower_Board::update_piece_position(int x, int y) -> void
{
  remaining_pieces[current_piece_to_move] -> pos_x = x;
  remaining_pieces[current_piece_to_move] -> pos_y = y;
  
  remaining_pieces[current_piece_to_move] -> set_position(x, y); 
}
