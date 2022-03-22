#include "../include/Chess_Piece.h"

Chess_Piece::Chess_Piece(double pos_x, double pos_y, const std::string& filename) : pos_x{pos_x}, pos_y{pos_y} 
{
  king_texture = new sf::Texture();
  king_sprite = new sf::Sprite();

  std::string path = "/home/hope/code/flower-chess/images/";
  load_texture(path.append(filename));

  king_sprite -> setPosition(pos_x, pos_y);
}

auto Chess_Piece::load_texture(const std::string& filename) -> void
{
  king_texture -> loadFromFile(filename);
  king_sprite -> setTexture(*king_texture);
}

auto Chess_Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void
{
  target.draw(*king_sprite);
}

King_Piece::King_Piece(double x, double y, const std::string& filename) : Chess_Piece(x, y, filename) {}



