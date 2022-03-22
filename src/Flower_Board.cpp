#include "../include/Flower_Board.h"

Flower_Board::Flower_Board() : square_size{60}
{

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
}
