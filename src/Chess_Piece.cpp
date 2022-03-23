#include "../include/Chess_Piece.h"

Chess_Piece::Chess_Piece(const std::string& filename)
{
  piece_texture = new sf::Texture();
  piece_sprite = new sf::Sprite();

  std::string path = "/home/hope/code/flower-chess/images/";
  load_texture(path.append(filename));
}

auto Chess_Piece::load_texture(const std::string& filename) -> void
{
  piece_texture -> loadFromFile(filename);
  piece_sprite -> setTexture(*piece_texture);
}

auto Chess_Piece::set_position(double x, double y) -> void
{
  piece_sprite -> setPosition(x, y);
}

auto Chess_Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void
{
  target.draw(*piece_sprite);
}

King_Piece::King_Piece(const std::string& filename) : Chess_Piece(filename) {}

Queen_Piece::Queen_Piece(const std::string& filename) : Chess_Piece(filename) {}

Bishop_Piece::Bishop_Piece(const std::string& filename) : Chess_Piece(filename) {}

Pawn_Piece::Pawn_Piece(const std::string& filename) : Chess_Piece(filename) {}

Rook_Piece::Rook_Piece(const std::string& filename) : Chess_Piece(filename) {}

Knight_Piece::Knight_Piece(const std::string& filename) : Chess_Piece(filename) {}




