//
//  bullet.cpp
//  small_game
//
//  Created by Yunus Syed on 12/29/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "bullet.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>


Bullet::Bullet(sf::Vector2f player_position, float weapon_rotation):
rotation(weapon_rotation),
made_impact(false)
{
    float rotation_radian = weapon_rotation * 3.1415926 / 180;
    position = {player_position.x + 30 + 80 * cosf(rotation_radian), player_position.y + 30 + 80 * sinf(rotation_radian)};
    graphic.setRadius(20);
    graphic.setPosition(position);
    graphic.setFillColor(sf::Color::White);
    
}


void Bullet::DrawBullet(sf::RenderTarget& target) {
    target.draw(graphic);
}

void Bullet::Move(sf::Time dt) {
    velocity = {2000 * dt.asSeconds() * cosf(3.14159 * rotation / 180), 2000 * dt.asSeconds() * sinf(3.14159 * rotation / 180)};
    position += velocity;
    graphic.setPosition(position);

}

float Bullet::GetBulletSize() {
    return graphic.getRadius();
}

sf::Vector2f Bullet::GetPosition() {
    return position;
}

bool Bullet::GetImpactStatus() {
    return made_impact;
}

void Bullet::MadeImpact() {
    made_impact = true;
}

sf::CircleShape Bullet::GetGraphic() {
    return graphic;
}
