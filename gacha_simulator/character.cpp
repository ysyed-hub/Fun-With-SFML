//
//  character.cpp
//  gacha_simulator
//
//  Created by Yunus Syed on 12/18/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "character.hpp"
#include <iostream>

Character::Character(std::string name, int rarity):
name(name),
rarity(rarity)
{

}

std::string Character::GetName() {
    return name;
}

int Character::GetRarity() {
    return rarity;
}

void Character::SetTexture(sf::Texture texture) {
    character_graphic = texture;
}


void Character::DrawCharacter(sf::RenderTarget& target) {
    sf::Sprite character_icon;
    character_icon.setTexture(character_graphic);
    character_icon.setPosition(450.f, 350.f);
    target.draw(character_icon);
}
