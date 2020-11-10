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

class Ball {
    
    float ball_velocity;
    bool ball_falling;
    sf::CircleShape ball;
    sf::RenderWindow my_window;
    sf::Clock time;
    sf::Clock air_time;
    sf::Time time_per_frame;
    float max_velocity;
    void ProcessEvents();
    void Update();
    void Render();
public:
    Ball();
    void Run();
    void Fall(float *ball_velocityptr);
    void Rise(float *ball_velocityptr, float upward_velocity);
    void SwitchDirection();
    void DisplayInfo();
    void Bounce();
};

#endif /* ball_hpp */
