//
//  small_enemy.hpp
//  small_game
//
//  Created by Yunus Syed on 12/29/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef small_enemy_hpp
#define small_enemy_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "bullet.hpp"

class SmallEnemy {
    sf::CircleShape graphic;
    sf::Vector2f position_;
    sf::Vector2f movement_;
    int quadrant_;
    bool made_impact;
    
public:
    SmallEnemy(sf::Vector2f enemy_position, float enemy_radius, int quadrant);
    void DrawSmallEnemy(sf::RenderTarget& target);
    void Move(sf::Time dt);
    bool GetImpactStatus();
    void MadeImpact();
    sf::CircleShape GetGraphic();
};

#endif /* small_enemy_hpp */
