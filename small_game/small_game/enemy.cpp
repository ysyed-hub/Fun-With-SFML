//
//  enemy.cpp
//  small_game
//
//  Created by Yunus Syed on 12/27/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "enemy.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <cmath>

BigEnemy::BigEnemy(sf::Vector2f position):
position_(position),
made_impact(false)
{
    graphic.setRadius(30);
    graphic.setPosition(position);
    graphic.setFillColor(sf::Color(30, 100, 100));
}

void BigEnemy::DrawBigEnemy(sf::RenderTarget& target) {
    target.draw(graphic);
}

/*bool BigEnemy::BigEnemyImpact(Bullet bullet) {
    float bullet_radius = bullet.GetBulletSize();
    sf::Vector2f bullet_position = bullet.GetPosition();
    
    if (bullet_position.y + bullet_height > graphic.getPosition().y && bullet_position.y < graphic.getPosition().y + graphic.getSize().y) {
        if (bullet_position.x + bullet_length >= graphic.getPosition().x)
            return true;
    }

    return false;
}*/

sf::Vector2f BigEnemy::GetPosition() {
    return graphic.getPosition();
}

float BigEnemy::GetSize() {
    return graphic.getRadius();
}

bool BigEnemy::GetImpactStatus() {
    return made_impact;
}

void BigEnemy::MadeImpact() {
    made_impact = true;
}

sf::CircleShape BigEnemy::GetGraphic() {
    return graphic;
}
