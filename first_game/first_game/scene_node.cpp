//
//  scene_node.cpp
//  first_game
//
//  Created by Yunus Syed on 11/11/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "scene_node.hpp"
#include <stdio.h>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

SceneNode::SceneNode(): children(), parent(nullptr) {}

void SceneNode::AttachChild(Ptr child) {
    child -> parent = this;
    children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::DetachChild(const SceneNode &node) {
    auto found = std::find_if(children.begin(), children.end(), [&] (Ptr& p) -> bool {
        return p.get() == &node;
    });
    
    assert(found != children.end());
    
    Ptr result = std::move(*found);
    result -> parent = nullptr;
    children.erase(found);
    return result;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    DrawCurrent(target, states);
    DrawChildren(target, states);
}

void SceneNode::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {}

void SceneNode::DrawChildren(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const Ptr& child : children) 
        child -> draw(target, states);
}

void SceneNode::Update(sf::Time dt) {
    UpdateCurrent(dt);
    UpdateChildren(dt);
}

void SceneNode::UpdateCurrent(sf::Time dt) {}

void SceneNode::UpdateChildren(sf::Time dt) {
    for (Ptr& child : children)
        child -> Update(dt);
}

sf::Transform SceneNode::GetWorldTransform() const {
    sf::Transform transform = sf::Transform::Identity;
    for (const SceneNode* node = this; node != nullptr; node = node -> parent)
        transform *= node -> getTransform();
}

sf::Vector2f SceneNode::GetWorldPosition() const {
    return getTransform() * sf::Vector2f();
}
