//
//  scene_node.hpp
//  first_game
//
//  Created by Yunus Syed on 11/11/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef scene_node_hpp
#define scene_node_hpp

#include <stdio.h>
#include <vector>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
public:
    typedef std::unique_ptr<SceneNode> Ptr;
    
public:
    SceneNode();
    void Update(sf::Time dt);
    void AttachChild(Ptr child);
    Ptr DetachChild(const SceneNode& node);
    sf::Transform GetWorldTransform() const;
    sf::Vector2f GetWorldPosition() const;
    
private:
    std::vector<Ptr> children;
    SceneNode* parent;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void DrawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void UpdateCurrent(sf::Time dt);
    void UpdateChildren(sf::Time dt);
    

};

#endif /* scene_node_hpp */
