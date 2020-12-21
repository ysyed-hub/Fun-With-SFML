//
//  sprite_node.hpp
//  first_game
//
//  Created by Yunus Syed on 11/14/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef sprite_node_hpp
#define sprite_node_hpp

#include <stdio.h>
#include "scene_node.hpp"

class SpriteNode : public SceneNode {
public:
    explicit SpriteNode (const sf::Texture& texture);
    SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);
    
private:
    virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Sprite my_sprite;
};

#endif /* sprite_node_hpp */
