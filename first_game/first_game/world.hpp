//
//  world.hpp
//  first_game
//
//  Created by Yunus Syed on 11/14/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef world_hpp
#define world_hpp

#include <stdio.h>
#include <SFML/System/NonCopyable.hpp>
#include "resource_identifiers.hpp"
#include "resource_holder.hpp"
#include "scene_node.hpp"
#include "sprite_node.hpp"
#include "entities.hpp"

#include <array>

class World : private sf::NonCopyable {
    
public:
    explicit World(sf::RenderWindow& window);
    void Update(sf::Time dt);
    void draw();
    
private:
    void LoadTextures();
    void BuildScene();
    
private:
    enum Layer {Background, Air, LayerCount};
    
private:
    sf::RenderWindow& window;
    sf::View world_view;
    TextureHolder textures;
    SceneNode scene_graph;
    std::array<SceneNode*, LayerCount> scene_layers;
    
    sf::FloatRect world_bounds;
    sf::Vector2f spawn_position;
    float scroll_speed;
    Aircraft* player_aircraft;
    
};

#endif /* world_hpp */
