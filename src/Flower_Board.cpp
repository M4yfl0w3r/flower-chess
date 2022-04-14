#include "../include/Flower_Board.h"

Flower_Board::Flower_Board() 
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
  
  remaining_pieces.flower_push_back(new King_Piece("b_king.png", 4, 0, "black", "king"));
  remaining_pieces.flower_push_back(new King_Piece("w_king.png", 4, 7, "white", "king"));

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
 
  if (piece_chosen(&current_piece_to_move, mouse_pos_x, mouse_pos_y) <= 32)
  {
    if (color_to_move == color_chosen)
    {
      piece_clicked = true;
    }
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
      x_update = mouse_pos_x;
      y_update = mouse_pos_y; 
    }
  }
}

auto Flower_Board::on_mouse_released() -> void
{
  mouse_pressed = false;
  piece_clicked = false;
      
  if (field_empty(x_update, y_update))
  {
    update_piece_position(x_update, y_update);
    change_turn(current_piece_to_move);
  }

  else if (!field_empty(x_update, y_update))
  {
    // Piece to be captured
    piece_in_danger = piece_chosen(&piece_in_danger, x_update, y_update);

    if (remaining_pieces[piece_in_danger] -> name == "king")
    {
      std::cout << color_to_move << " won!\n";
      lost = true;
      return;
    }

    // Check if the pieces have different colors
    if (remaining_pieces[current_piece_to_move] -> color != remaining_pieces[piece_in_danger] -> color)
    {
      update_piece_position(x_update, y_update);
      remaining_pieces.erase(remaining_pieces.begin() + piece_in_danger);
      change_turn(current_piece_to_move);
    }
  }
}

auto Flower_Board::change_turn(int current_piece_to_move)-> void
{
  if (remaining_pieces[current_piece_to_move] -> color == "white") color_to_move = "black";
  else color_to_move = "white";
}

auto Flower_Board::field_empty(int x, int y) -> bool
{
  for (std::size_t i = 0; i < remaining_pieces.flower_size(); i++)
  {
    if (remaining_pieces[i] -> pos_x == x && remaining_pieces[i] -> pos_y == y)
    {
      return false; 
    }
  }

  return true;
}

auto Flower_Board::piece_chosen(int* piece, int x, int y) -> int
{
  for (std::size_t i = 0; i < remaining_pieces.flower_size(); i++)
  {
    if (remaining_pieces[i] -> pos_x == x && remaining_pieces[i] -> pos_y == y)
    {
      color_chosen = remaining_pieces[i] -> color;
      *piece = i;
    }
  }

  return *piece;
}

auto Flower_Board::update_piece_position(int x, int y) -> void
{
  remaining_pieces[current_piece_to_move] -> pos_x = x;
  remaining_pieces[current_piece_to_move] -> pos_y = y;
  
  remaining_pieces[current_piece_to_move] -> set_position(x, y); 
}

