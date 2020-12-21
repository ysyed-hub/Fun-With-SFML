//
//  entities.cpp
//  first_game
//
//  Created by Yunus Syed on 11/10/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "entities.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "resource_holder.hpp"

Textures::ID toTextureID(Aircraft::Type type) {
    switch (type) {
        case Aircraft::Eagle:
            return Textures::Eagle;
            
        case Aircraft::Raptor:
            return Textures::Raptor;
    }
}

Entity::Entity() : velocity(0.f,0.f) {}

void Entity::setVelocity(sf::Vector2f velocity) {
    this->velocity = velocity;
}

void Entity::setVelocity(float vx, float vy) {
    velocity.x = vx;
    velocity.y = vy;
}

void Entity::UpdateCurrent(sf::Time dt) {
    move(velocity * dt.asSeconds());
}

sf::Vector2f Entity::getVelocity() const {
    return velocity;
}

Aircraft::Aircraft(Type type, const TextureHolder& textures) : my_type(type), my_sprite(textures.get(toTextureID(type))) {
    
}

void Aircraft::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(my_sprite, states);
}
