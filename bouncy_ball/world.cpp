//
//  world.cpp
//  bouncy_ball
//
//  Created by Yunus Syed on 11/16/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "world.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

World::World(sf::RenderWindow& new_window) :
window(new_window),
world_view(window.getDefaultView()),
world_bounds(0.f, 0.f, 4000.f, 3000.f),
//world_bounds(0.f, 0.f, world_view.getSize().x, 2000.f),
//spawn_position(world_view.getSize().x / 4.f, world_bounds.height - world_view.getSize().y / 2.f),
spawn_position(0.f, 0.f),
//scroll_speed(-50.f),
player_ball(new Ball(window))
{
    LoadTextures();
    BuildScene();
    world_view.setCenter(window.getSize().x/2, window.getSize().y/2);
}

void World::LoadTextures() {
    textures.Load(Textures::Court, "Hoop.jpg");
}

void World::BuildScene() {
    for (std::size_t i = 0; i < LayerCount; ++i) {
        SceneNode::Ptr layer(new SceneNode());
        scene_layers[i] = layer.get();
        
        scene_graph.AttachChild(std::move(layer));
    }
    
    sf::Texture& texture = textures.get(Textures::Court);
    sf::IntRect texture_rect(world_bounds);

    std::unique_ptr<SpriteNode> background_sprite(new SpriteNode(texture, texture_rect));
    background_sprite -> setPosition(0.f, 0.f);
    
    scene_layers[Background] -> AttachChild(std::move(background_sprite));
    
    
}

void World::draw() {
    window.setView(world_view);
    window.draw(scene_graph);
    player_ball -> draw();
}

void World::Update(sf::Time dt, bool key_pressed) {
    player_ball -> Update(dt, key_pressed);
    world_view.move(player_ball -> GetVelocity() / 10.f);
    
   /* sf::Vector2f position = player_ball -> GetPosition();
    sf::Vector2f velocity = (player_ball -> GetVelocity());
    
    scene_graph.Update(dt); */
}

void World::DisplayInfo() const {
    player_ball -> DisplayInfo();
}
