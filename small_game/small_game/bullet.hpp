//
//  bullet.hpp
//  small_game
//
//  Created by Yunus Syed on 12/29/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef bullet_hpp
#define bullet_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <cmath>

class Bullet {
    sf::CircleShape graphic;
    sf::Vector2f position;
    float rotation;
    sf::Vector2f velocity;
    bool made_impact;
    
public:
    Bullet(sf::Vector2f player_position, float weapon_rotation);
    void DrawBullet(sf::RenderTarget& target);
    void Move(sf::Time dt);
    float GetBulletSize();
    sf::Vector2f GetPosition();
    bool GetImpactStatus();
    void MadeImpact();
    sf::CircleShape GetGraphic();
};

#endif /* bullet_hpp */
