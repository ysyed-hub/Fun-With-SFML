//
//  power_ups.cpp
//  small_game
//
//  Created by Yunus Syed on 1/3/21.
//  Copyright © 2021 Yunus Syed. All rights reserved.
//

#include "power_ups.hpp"

PowerUp::PowerUp(sf::Vector2f initial_position):
position(initial_position),
velocity({0,-1})
{
    icon.setRadius(30);
    icon.setFillColor(sf::Color::Yellow);
    icon.setPosition(position);
    
}
