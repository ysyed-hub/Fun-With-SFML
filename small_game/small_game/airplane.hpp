//
//  airplane.hpp
//  small_game
//
//  Created by Yunus Syed on 12/26/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef airplane_hpp
#define airplane_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "health.hpp"

class Airplane {
    sf::CircleShape player;
    sf::CircleShape bullet;
    sf::Vector2f position;
    float rotation;
    Health health;
    
public:
    Airplane();
    void DrawPlayer(sf::RenderTarget& target);
    void Movement(sf::Keyboard::Key input, sf::Time dt);
    sf::Vector2f GetPosition();
    float GetRotation();
    
};

#endif /* airplane_hpp */
