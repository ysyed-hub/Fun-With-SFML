//
//  game.hpp
//  first_game
//
//  Created by Yunus Syed on 11/8/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "world.hpp"

class Game {
private:
    void ProcessEvents();
    void Update(sf::Time delta_time);
    void Render();
    void UpdateStats(sf::Time elapsed_time);
    
private:
    static const sf::Time time_per_frame;
    sf::RenderWindow my_window;
    World world;
    
    sf::Font font;
    sf::Text stats_text;
    sf::Time stats_update_time;
    std::size_t stats_num_frames;
    
    
public:
    Game();
    void Run();
    void HandlePlayerInput(sf::Keyboard::Key key, bool is_pressed);
};


#endif /* game_hpp */
