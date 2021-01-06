//
//  airplane.cpp
//  small_game
//
//  Created by Yunus Syed on 12/26/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "airplane.hpp"
#include <cmath>

Airplane::Airplane():
rotation(0),
health()
{
    player.setRadius(50);
    player.setPosition(150.f, 450.f);
    player.setFillColor(sf::Color::Green);
    position = player.getPosition();
    
    float rotation_radian = 3.14159265 * rotation / 180;
    sf::Vector2f initial_position = {GetPosition().x + 30 + 80 * cosf(rotation_radian) , GetPosition().y + 30 + 80 * sinf(rotation_radian)};
    bullet.setRadius(20);
    bullet.setPosition(initial_position.x, initial_position.y);
    bullet.setFillColor(sf::Color::White);
    
}

void Airplane::DrawPlayer(sf::RenderTarget& target) {
    target.draw(player);
    target.draw(bullet);
    health.DrawHealthBar(target);
}

void Airplane::Movement(sf::Keyboard::Key input, sf::Time dt) {
    sf::Vector2f movement = {0,0};
    float player_speed = 1000;
    if (input == sf::Keyboard::W)
        movement.y -= player_speed;
    else if (input == sf::Keyboard::S)
        movement.y += player_speed;
    else if (input == sf::Keyboard::A)
        movement.x -= player_speed;
    else if (input == sf::Keyboard::D)
        movement.x += player_speed;
    position += movement * dt.asSeconds();
    player.setPosition(position);
    bullet.setPosition({position.x + 30 + 80 * cosf(rotation * 3.14159265/180), position.y + 30 + 80 * sinf(rotation * 3.14159265/180)});
    
    float rotation_speed = 1080 * dt.asSeconds();
    if (input == sf::Keyboard::I)
        rotation += rotation_speed;
    else if (input == sf::Keyboard::U)
        rotation -= rotation_speed;
    
}

sf::Vector2f Airplane::GetPosition() {
    return player.getPosition();
}

float Airplane::GetRotation() {
    return rotation;
}
