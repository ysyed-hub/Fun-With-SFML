//
//  world.hpp
//  bouncy_ball
//
//  Created by Yunus Syed on 11/16/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef world_hpp
#define world_hpp

#include <stdio.h>
#include <SFML/System/NonCopyable.hpp>
#include "resource_identifier.hpp"
#include "resource_holder.hpp"
#include "scene_node.hpp"
#include "sprite_node.hpp"
#include "ball.hpp"

#include <array>

class World : private sf::NonCopyable {
    
public:
    explicit World(sf::RenderWindow& window);
    void Update(sf::Time dt, bool key_pressed);
    void draw();
    void DisplayInfo() const;
    
private:
    void LoadTextures();
    void BuildScene();
    
private:
    enum Layer {Background, LayerCount};
    
private:
    sf::RenderWindow& window;
    sf::View world_view;
    TextureHolder textures;
    SceneNode scene_graph;
    std::array<SceneNode*, LayerCount> scene_layers;
    
    sf::FloatRect world_bounds;
    sf::Vector2f spawn_position;
    float scroll_speed;
    Ball* player_ball;
    
};

#endif /* world_hpp */
