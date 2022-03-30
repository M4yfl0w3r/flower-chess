#include "../include/Chess_Piece.h"
#include <memory>

Chess_Piece::Chess_Piece(const std::string& filename, int x, int y)
{
  piece_texture = std::make_shared<sf::Texture>();
  piece_sprite = std::make_shared<sf::Sprite>();

  std::string path = "/home/hope/Code/flower-chess/images/";
  load_texture(path.append(filename));
  piece_sprite -> setPosition(x * 60, y * 60);
}

auto Chess_Piece::load_texture(const std::string& filename) -> void
{
  piece_texture -> loadFromFile(filename);
  piece_sprite -> setTexture(*piece_texture);
}

auto Chess_Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void
{
  target.draw(*piece_sprite);
}

King_Piece::King_Piece(const std::string& filename, int x, int y) : Chess_Piece(filename, x, y) {}

Queen_Piece::Queen_Piece(const std::string& filename, int x, int y) : Chess_Piece(filename, x, y) {}

Bishop_Piece::Bishop_Piece(const std::string& filename, int x, int y) : Chess_Piece(filename, x, y) {}

Pawn_Piece::Pawn_Piece(const std::string& filename, int x, int y) : Chess_Piece(filename, x, y) {}

Rook_Piece::Rook_Piece(const std::string& filename, int x, int y) : Chess_Piece(filename, x, y) {}

Knight_Piece::Knight_Piece(const std::string& filename, int x, int y) : Chess_Piece(filename, x, y) {}




