//
//  sprite_node.cpp
//  first_game
//
//  Created by Yunus Syed on 11/14/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "sprite_node.hpp"

SpriteNode::SpriteNode(const sf::Texture& Texture) : my_sprite(Texture) {}

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect): my_sprite(texture, textureRect) {}

void SpriteNode::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(my_sprite, states);
}

