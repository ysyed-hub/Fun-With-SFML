//
//  enemy.hpp
//  small_game
//
//  Created by Yunus Syed on 12/27/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef enemy_hpp
#define enemy_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "bullet.hpp"


class BigEnemy {
    sf::CircleShape graphic;
    sf::Vector2f position_;
    sf::Vector2f movement_;
    bool made_impact;
    
public:
    BigEnemy(sf::Vector2f position);
    void DrawBigEnemy(sf::RenderTarget& target);
    float GetSize();
    sf::Vector2f GetPosition();
    bool GetImpactStatus();
    void MadeImpact();
    sf::CircleShape GetGraphic();
};


#endif /* enemy_hpp */
