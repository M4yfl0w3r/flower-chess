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
	Flower_Board();

private:
	auto draw(sf::RenderTarget & target, sf::RenderStates states) const -> void override;

};
