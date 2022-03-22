#pragma once

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Flower_Board : public sf::Drawable
{
	int square_size = 0;

public:
	Flower_Board();

private:
	auto draw(sf::RenderTarget & target, sf::RenderStates states) const -> void override;

};
