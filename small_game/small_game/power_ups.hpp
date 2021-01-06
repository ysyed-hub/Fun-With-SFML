//
//  power_ups.hpp
//  small_game
//
//  Created by Yunus Syed on 1/3/21.
//  Copyright © 2021 Yunus Syed. All rights reserved.
//

#ifndef power_ups_hpp
#define power_ups_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class PowerUp {
    sf::CircleShape icon;
    sf::Vector2f position;
    sf::Vector2f velocity;
public:
    PowerUp(sf::Vector2f initial_position);
    void DrawPowerUp(sf::RenderTarget& target);
    void Move();
    
};

#endif /* power_ups_hpp */
