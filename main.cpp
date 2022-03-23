#include "include/Flower_Board.h"
#include "include/Chess_Piece.h"

#include "src/Flower_Board.cpp"
#include "src/Chess_Piece.cpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(480, 480), "Chess", sf::Style::Titlebar | sf::Style::Close);
  sf::Event event;

  Flower_Board board;
 
  Rook_Piece b_rook("b_rook.png");
  Knight_Piece b_knight("b_knight.png");
  Bishop_Piece b_bishop("b_bishop.png");
  Queen_Piece b_queen("b_queen.png");
  King_Piece b_king("b_king.png");
  Pawn_Piece b_pawn("b_pawn.png");
  
  Rook_Piece w_rook("w_rook.png");
  Knight_Piece w_knight("w_knight.png");
  Bishop_Piece w_bishop("w_bishop.png");
  Queen_Piece w_queen("w_queen.png");
  King_Piece w_king("w_king.png");
  Pawn_Piece w_pawn("w_pawn.png");

  Chess_Piece* b_pieces[] = {&b_rook, &b_knight, &b_bishop, &b_queen, &b_king, &b_bishop, &b_knight, &b_rook, &b_pawn};
  Chess_Piece* w_pieces[] = {&w_rook, &w_knight, &w_bishop, &w_queen, &w_king, &w_bishop, &w_knight, &w_rook, &w_pawn};

  while (window.isOpen())
  {
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

      if (event.key.code == sf::Keyboard::Escape)
      {
        window.close();
      }
    } 
    
    window.draw(board);
  
    for (size_t i = 0; i < sizeof(b_pieces) / sizeof(Chess_Piece*); i++)
    {
      Chess_Piece* piece = b_pieces[i];

      if (piece != &b_pawn)
      {
        piece -> set_position(60*i, 0);
        window.draw(*piece);
      }

      else 
      {
        for (int j = 0; j < 8; j++)
        {
          piece -> set_position(60*j, 60);
          window.draw(*piece);
        }
      }
    }

    for (size_t i = 0; i < sizeof(w_pieces) / sizeof(Chess_Piece*); i++)
    {
      Chess_Piece* piece = w_pieces[i];

      if (piece != &w_pawn)
      {
        piece -> set_position(60*i, 420);
        window.draw(*piece);
      }

      else 
      {
        for (int j = 0; j < 8; j++)
        {
          piece -> set_position(60*j, 360);
          window.draw(*piece);
        }
      }
    }

    window.display();
  }

  return 0;
}
