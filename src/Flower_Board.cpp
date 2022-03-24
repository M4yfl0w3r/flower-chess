#include "../include/Flower_Board.h"

Flower_Board::Flower_Board() : square_size{60}
{
  remaining_pieces.flower_push_back(new Rook_Piece("b_rook.png", 0, 0));
  remaining_pieces.flower_push_back(new Rook_Piece("w_rook.png", 0, 7));
  remaining_pieces.flower_push_back(new Rook_Piece("b_rook.png", 7, 0));
  remaining_pieces.flower_push_back(new Rook_Piece("w_rook.png", 7, 7));

  remaining_pieces.flower_push_back(new Knight_Piece("b_knight.png", 1, 0));
  remaining_pieces.flower_push_back(new Knight_Piece("w_knight.png", 1, 7));
  remaining_pieces.flower_push_back(new Knight_Piece("b_knight.png", 6, 0));
  remaining_pieces.flower_push_back(new Knight_Piece("w_knight.png", 6, 7));

  remaining_pieces.flower_push_back(new Bishop_Piece("b_bishop.png", 2, 0));
  remaining_pieces.flower_push_back(new Bishop_Piece("w_bishop.png", 2, 7));
  remaining_pieces.flower_push_back(new Bishop_Piece("b_bishop.png", 5, 0));
  remaining_pieces.flower_push_back(new Bishop_Piece("w_bishop.png", 5, 7));

  remaining_pieces.flower_push_back(new Queen_Piece("b_queen.png", 3, 0));
  remaining_pieces.flower_push_back(new Queen_Piece("w_queen.png", 3, 7));
  
  remaining_pieces.flower_push_back(new King_Piece("b_king.png", 4, 0));
  remaining_pieces.flower_push_back(new King_Piece("w_king.png", 4, 7));

  for (int i = 0; i < 8; i++)
    remaining_pieces.flower_push_back(new Pawn_Piece("w_pawn.png", i, 6));

  for (int i = 0; i < 8; i++)
    remaining_pieces.flower_push_back(new Pawn_Piece("b_pawn.png", i, 1));
}

auto Flower_Board::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void
{
	sf::RectangleShape rect;	

	auto colors = std::make_tuple(sf::Color (234,182,118), sf::Color (153, 76, 0));

	int x = 0;

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

  for (std::size_t i = 0; i < remaining_pieces.flower_size(); i++)
  {
    remaining_pieces[i] -> draw(target, states);
  }  
}

