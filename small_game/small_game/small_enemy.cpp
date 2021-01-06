//
//  small_enemy.cpp
//  small_game
//
//  Created by Yunus Syed on 12/29/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "small_enemy.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

SmallEnemy::SmallEnemy(sf::Vector2f enemy_position, float enemy_radius, int quadrant):
quadrant_(quadrant),
made_impact(false)
{
    graphic.setRadius(enemy_radius/2);
    graphic.setFillColor(sf::Color::Blue);
    movement_ = {500 * cosf((3.1415 * (90*quadrant + 45)) / 180), 500 * sinf((3.1415 * (90*quadrant + 45)) / 180)};
    
    sf::Vector2f starting_position;
    switch (quadrant_) {
        case 0:
            starting_position.x = enemy_position.x + enemy_radius / 2;
            starting_position.y = enemy_position.y + enemy_radius / 2;
            break;
        case 1:
            starting_position.x = enemy_position.x + enemy_radius / 2;
            starting_position.y = enemy_position.y;
            break;
        case 2:
            starting_position.x = enemy_position.x;
            starting_position.y = enemy_position.y + enemy_radius / 2;
            break;
        case 3:
            starting_position.x = enemy_position.x;
            starting_position.y = enemy_position.y;
            break;
        default:
            break;
    }
    position_ = starting_position;
    graphic.setPosition(position_);
    
}

void SmallEnemy::DrawSmallEnemy(sf::RenderTarget &target) {
    target.draw(graphic);
}

/*bool SmallEnemy::SmallEnemyImpact(Bullet bullet) {
    int bullet_height = bullet.GetBulletSize().y;
    int bullet_length = bullet.GetBulletSize().x;
    sf::Vector2f bullet_position = bullet.GetPosition();
    
    
    if (bullet_position.y + bullet_height > graphic.getPosition().y && bullet_position.y < graphic.getPosition().y + graphic.getSize().y) {
            
        if (bullet_position.x + bullet_length >= graphic.getPosition().x && bullet_position.x < graphic.getPosition().x + graphic.getSize().x) {
            return true;
        }
    }
    
    return false;
} */

void SmallEnemy::Move(sf::Time dt) {
    if (graphic.getPosition().x > 800 && movement_.x > 0)
        movement_.x *= -1;
    if (graphic.getPosition().x < 0 && movement_.x < 0)
        movement_.x *= -1;
    if (graphic.getPosition().y > 750 && movement_.y > 0)
        movement_.y *= -1;
    if (graphic.getPosition().y < 0 && movement_.y < 0)
        movement_.y *= -1;
    
    position_ += movement_ * dt.asSeconds();
    graphic.setPosition(position_);
}

bool SmallEnemy::GetImpactStatus() {
    return made_impact;
}

void SmallEnemy::MadeImpact() {
    made_impact = true;
}

sf::CircleShape SmallEnemy::GetGraphic() {
    return graphic;
}
