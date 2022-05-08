#include "../include/Chess_Piece.h"
#include "../include/Flower_Board.h"

Chess_Piece::Chess_Piece(const std::string& filename, int x, int y, const std::string& color, const std::string& name = "") : pos_x{x}, pos_y{y}, color{color}, name{name}
{
  piece_texture = std::make_shared<sf::Texture>();
  piece_sprite = std::make_shared<sf::Sprite>();

  std::string path = "../images/";
  load_texture(path.append(filename));
  set_position(pos_x, pos_y);
}

auto Chess_Piece::load_texture(const std::string& filename) -> void
{
  piece_texture -> loadFromFile(filename);
  piece_sprite -> setTexture(*piece_texture);
}

auto Chess_Piece::set_position(int x, int y) -> void
{
  piece_sprite -> setPosition(x * 60, y * 60);
}

auto Chess_Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void
{
  target.draw(*piece_sprite);
}

[[maybe_unused]] auto Chess_Piece::move_valid(int x, int y, bool is_field_empty) -> bool
{
  return false;
}

King_Piece::King_Piece(const std::string& filename, int x, int y, const std::string& color, const std::string& name) : Chess_Piece(filename, x, y, color, name) {}

Queen_Piece::Queen_Piece(const std::string& filename, int x, int y, const std::string& color) : Chess_Piece(filename, x, y, color) {}

Bishop_Piece::Bishop_Piece(const std::string& filename, int x, int y, const std::string& color) : Chess_Piece(filename, x, y, color) {}

Pawn_Piece::Pawn_Piece(const std::string& filename, int x, int y, const std::string& color) : Chess_Piece(filename, x, y, color) {}

Rook_Piece::Rook_Piece(const std::string& filename, int x, int y, const std::string& color) : Chess_Piece(filename, x, y, color) {}

Knight_Piece::Knight_Piece(const std::string& filename, int x, int y, const std::string& color) : Chess_Piece(filename, x, y, color) {}

auto King_Piece::move_valid(int x, int y, bool is_field_empty) -> bool
{
  std::multimap<int, int> valid_positions;

  valid_positions.insert(std::pair<int, int>(pos_x - 1, pos_y - 1));
  valid_positions.insert(std::pair<int, int>(pos_x, pos_y - 1));
  valid_positions.insert(std::pair<int, int>(pos_x + 1 , pos_y - 1));

  valid_positions.insert(std::pair<int, int>(pos_x - 1, pos_y));
  valid_positions.insert(std::pair<int, int>(pos_x, pos_y));
  valid_positions.insert(std::pair<int, int>(pos_x + 1, pos_y));
  
  valid_positions.insert(std::pair<int, int>(pos_x - 1, pos_y + 1));
  valid_positions.insert(std::pair<int, int>(pos_x, pos_y + 1));
  valid_positions.insert(std::pair<int, int>(pos_x + 1, pos_y + 1));

  typedef std::multimap<int, int>::iterator map_iterator;

  std::pair<map_iterator, map_iterator> result = valid_positions.equal_range(x);

  for (map_iterator it = result.first; it != result.second; it++)
  {
    if (it -> second == y)
    {
      return true;
    }
  }

  return false;
}

auto Pawn_Piece::move_valid(int x, int y, bool is_field_empty) -> bool
{
  std::multimap<int, int> valid_positions;

  if (is_field_empty)
  {
    if (color == "black")
    {
      valid_positions.insert(std::pair<int, int>(pos_x, pos_y + 1));

      if (x == pos_x && pos_y == 1)
      {
        valid_positions.insert(std::pair<int, int>(pos_x, pos_y + 2));
      }
    }
    else if (color == "white")
    {
      valid_positions.insert(std::pair<int, int>(pos_x, pos_y - 1));

      if (x == pos_x && pos_y == 6)
      {
        valid_positions.insert(std::pair<int, int>(pos_x, pos_y - 2));
      }
    }
  }
  else
  {
    if (color == "black")
    {
      valid_positions.insert(std::pair<int, int>(pos_x - 1 , pos_y + 1));
      valid_positions.insert(std::pair<int, int>(pos_x + 1 , pos_y + 1));   
    }
    else if (color == "white")
    {
      valid_positions.insert(std::pair<int, int>(pos_x - 1 , pos_y - 1));
      valid_positions.insert(std::pair<int, int>(pos_x + 1 , pos_y - 1));  
    }
  }
 
  typedef std::multimap<int, int>::iterator map_iterator;

  std::pair<map_iterator, map_iterator> result = valid_positions.equal_range(x);

  for (map_iterator it = result.first; it != result.second; it++)
  {
    if (it -> second == y)
    {
      return true;
    }
  }

  return false;
}

auto Knight_Piece::move_valid(int x, int y, bool is_field_empty) -> bool
{
  std::multimap<int, int> valid_positions;

  valid_positions.insert(std::pair<int, int>(pos_x - 1, pos_y - 2));
  valid_positions.insert(std::pair<int, int>(pos_x + 1, pos_y - 2));

  valid_positions.insert(std::pair<int, int>(pos_x - 2, pos_y - 1));
  valid_positions.insert(std::pair<int, int>(pos_x + 2, pos_y - 1));
  
  valid_positions.insert(std::pair<int, int>(pos_x - 2, pos_y + 1));
  valid_positions.insert(std::pair<int, int>(pos_x + 2, pos_y + 1));

  valid_positions.insert(std::pair<int, int>(pos_x - 1, pos_y + 2));
  valid_positions.insert(std::pair<int, int>(pos_x + 1, pos_y + 2));

  typedef std::multimap<int, int>::iterator map_iterator;

  std::pair<map_iterator, map_iterator> result = valid_positions.equal_range(x);

  for (map_iterator it = result.first; it != result.second; it++)
  {
    if (it -> second == y)
    {
      return true;
    }
  }

  return false;
}

auto Rook_Piece::move_valid(int x, int y, bool is_field_empty) -> bool
{
  std::multimap<int, int> valid_positions;

  int i = 0;

  while (pos_y + i < 8)
  {
    valid_positions.insert(std::pair<int, int>(pos_x, pos_y + i));  
    i++;
  }

  i = 0;

  while (pos_y - i >= 0)
  {
    valid_positions.insert(std::pair<int, int>(pos_x, pos_y - i));  
    i++;
  }

  i = 0;
  
  while (pos_x + i < 8)
  {
    valid_positions.insert(std::pair<int, int>(pos_x + i, pos_y));  
    i++;
  }

  i = 0;
  
  while (pos_x - i >= 0)
  {
    valid_positions.insert(std::pair<int, int>(pos_x - i, pos_y));  
    i++;
  }

  typedef std::multimap<int, int>::iterator map_iterator;

  std::pair<map_iterator, map_iterator> result = valid_positions.equal_range(x);

  for (map_iterator it = result.first; it != result.second; it++)
  {
    if (it -> second == y)
    {
      return true;
    }
  }

  return false;
}

auto Bishop_Piece::move_valid(int x, int y, bool is_field_empty) -> bool
{
  std::multimap<int, int> valid_positions;

  int i = 0;

  while (pos_x + i < 8)
  {
    valid_positions.insert(std::pair<int, int>(pos_x + i, pos_y + i));  
    valid_positions.insert(std::pair<int, int>(pos_x + i, pos_y - i));  
    i++;
  }

  i = 0;

  while (pos_x - i > 0)
  {
    valid_positions.insert(std::pair<int, int>(pos_x - i, pos_y - i));  
    valid_positions.insert(std::pair<int, int>(pos_x - i, pos_y + i));  
    i++;
  }

  typedef std::multimap<int, int>::iterator map_iterator;

  std::pair<map_iterator, map_iterator> result = valid_positions.equal_range(x);

  for (map_iterator it = result.first; it != result.second; it++)
  {
    if (it -> second == y)
    {
      return true;
    }
  }

  return false;
}

auto Queen_Piece::move_valid(int x, int y, bool is_field_empty) -> bool
{
  std::multimap<int, int> valid_positions;

  int i = 0;

  while (pos_x + i < 8)
  {
    valid_positions.insert(std::pair<int, int>(pos_x + i, pos_y + i));  
    valid_positions.insert(std::pair<int, int>(pos_x + i, pos_y - i));  
    valid_positions.insert(std::pair<int, int>(pos_x + i, pos_y));  
    i++;
  }

  i = 0;

  while (pos_x - i >= 0)
  {
    valid_positions.insert(std::pair<int, int>(pos_x - i, pos_y - i));  
    valid_positions.insert(std::pair<int, int>(pos_x - i, pos_y + i));  
    valid_positions.insert(std::pair<int, int>(pos_x - i, pos_y));  
    i++;
  }
  
  i = 0;

  while (pos_y + i < 8)
  {
    valid_positions.insert(std::pair<int, int>(pos_x, pos_y + i));  
    i++;
  }

  i = 0;

  while (pos_y - i >= 0)
  {
    valid_positions.insert(std::pair<int, int>(pos_x, pos_y - i));  
    i++;
  }

  typedef std::multimap<int, int>::iterator map_iterator;

  std::pair<map_iterator, map_iterator> result = valid_positions.equal_range(x);

  for (map_iterator it = result.first; it != result.second; it++)
  {
    if (it -> second == y)
    {
      return true;
    }
  }

  return false;
}

