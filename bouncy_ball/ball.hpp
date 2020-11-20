//
//  ball.hpp
//  bouncy_ball
//
//  Created by Yunus Syed on 11/9/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef ball_hpp
#define ball_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "scene_node.hpp"
#include "resource_identifier.hpp"

class Ball : private sf::NonCopyable {
    sf::Vector2f ball_velocity;
    bool falling;
    sf::CircleShape ball;
    sf::Clock air_time;
    float vertical_velocity;
    sf::RenderWindow& window;
    sf::Clock time;


public:
    Ball(sf::RenderWindow& window);
    void Fall();
    void Rise(float upward_velocity);
    void SwitchVerticalDirection();
    void SwitchHorizontalDirection();
    void DisplayInfo() const;
    sf::Vector2f GetPosition() const;
    float GetAirTime() const;
    sf::Vector2f GetVelocity() const;
    void SetVelocity(sf::Vector2f new_velocity);
    void SetVelocity(float x_velocity, float y_velocity);
    void Update(sf::Time dt, bool key_pressed);
    virtual void draw();
    void Jump();
    
};



#endif /* ball_hpp */
