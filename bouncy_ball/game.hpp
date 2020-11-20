//
//  game.hpp
//  bouncy_ball
//
//  Created by Yunus Syed on 11/15/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "world.hpp"


class Game {
    
    sf::RenderWindow my_window;
    sf::Time time_per_frame;
    void ProcessEvents();
    void Update(sf::Time dt, bool is_pressed);
    void Render();
    bool key_pressed;
    World world;
    
public:
    Game();
    void Run();
    void DisplayInfo();
    
};

#endif /* game_hpp */
