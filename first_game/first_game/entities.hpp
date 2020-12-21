//
//  entities.hpp
//  first_game
//
//  Created by Yunus Syed on 11/10/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef entities_hpp
#define entities_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "scene_node.hpp"
#include "resource_identifiers.hpp"


class Entity : public SceneNode {
    sf::Vector2f velocity;
public:
    Entity();
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity() const;
private:
    virtual void UpdateCurrent(sf::Time dt);
};

class Aircraft : public Entity {
public:
    enum Type {Eagle, Raptor};
    Aircraft(Type type, const TextureHolder& textures);
    virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    Type my_type;
    sf::Sprite my_sprite;
};

#endif /* entities_hpp */
