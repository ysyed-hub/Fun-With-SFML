//
//  world.cpp
//  first_game
//
//  Created by Yunus Syed on 11/14/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "world.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& new_window) :
window(new_window),
world_view(window.getDefaultView()),
world_bounds(0.f, 0.f, world_view.getSize().x, 2000.f),
spawn_position(world_view.getSize().x / 2.f, world_bounds.height - world_view.getSize().y / 2.f),
scroll_speed(-50.f),
player_aircraft(nullptr)
{
    LoadTextures();
    BuildScene();
    world_view.setCenter(spawn_position);
}

void World::LoadTextures() {
    textures.Load(Textures::Eagle, "media/eagle.png");
    textures.Load(Textures::Raptor, "media/raptor.png");
    textures.Load(Textures::Desert, "media/desert.png");
}

void World::BuildScene() {
    for (std::size_t i = 0; i < LayerCount; ++i) {
        SceneNode::Ptr layer(new SceneNode());
        scene_layers[i] = layer.get();
        
        scene_graph.AttachChild(std::move(layer));
    }
    
    sf::Texture& texture = textures.get(Textures::Desert);
    sf::IntRect texture_rect(world_bounds);
    texture.setRepeated(false);
    
    std::unique_ptr<SpriteNode> background_sprite(new SpriteNode(texture, texture_rect));
    background_sprite -> setPosition(world_bounds.left, world_bounds.top);
    
    scene_layers[Background] -> AttachChild(std::move(background_sprite));
    
    std::unique_ptr<Aircraft> leader (new Aircraft(Aircraft::Eagle, textures));
    player_aircraft = leader.get();
    player_aircraft -> setPosition(spawn_position);
    player_aircraft -> setVelocity(40.f, scroll_speed);
    scene_layers[Air] -> AttachChild(std::move(leader));
    
    std::unique_ptr<Aircraft> left_escort (new Aircraft(Aircraft::Raptor, textures));
    left_escort -> setPosition(-80.f, 50.f);
    player_aircraft -> AttachChild(std::move(left_escort));
    
    std::unique_ptr<Aircraft> right_escort (new Aircraft(Aircraft::Raptor, textures));
    right_escort -> setPosition(80.f, 50.f);
    player_aircraft -> AttachChild(std::move(right_escort));
}

void World::draw() {
    window.setView(world_view);
    window.draw(scene_graph);
}

void World::Update(sf::Time dt) {
    world_view.move(0.f, scroll_speed * dt.asSeconds());
    
    sf::Vector2f position = player_aircraft -> getPosition();
    sf::Vector2f velocity = player_aircraft -> getVelocity();
    
    if (position.x <= world_bounds.left + 150 || position.x >= world_bounds.left + world_bounds.width - 150) {
        velocity.x = -velocity.x;
        player_aircraft -> setVelocity(velocity);
    }
    scene_graph.Update(dt);
}
