//
//  game.cpp
//  first_game
//
//  Created by Yunus Syed on 11/8/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "game.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

const sf::Time Game::time_per_frame = sf::seconds(1.f/30.f);


Game::Game() :
my_window(sf::VideoMode(640, 480), "World", sf::Style::Close),
font(),
stats_text(),
stats_update_time(),
stats_num_frames(0),
world(my_window)
{
    font.loadFromFile("media/sansation.ttf");
    stats_text.setFont(font);
    stats_text.setPosition(5.f, 5.f);
    stats_text.setCharacterSize(10.f);
};


void Game::Run() {
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    while (my_window.isOpen()) {
        sf::Time elapsed_time = clock.restart();
        time_since_last_update += clock.restart();
        while(time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            ProcessEvents();
            Update(time_per_frame);
        }
        UpdateStats(elapsed_time);
        Render();
    }
}

void Game::ProcessEvents() {
    sf::Event event;
    while (my_window.pollEvent(event)) {
        switch (event.type) {
                
            case sf::Event::KeyPressed:
                HandlePlayerInput(event.key.code, true);
                break;
                
            case sf::Event::KeyReleased:
                HandlePlayerInput(event.key.code, false);
                break;
                
            case sf::Event::Closed:
                my_window.close();
                break;
        }
    }
}

void Game::Update(sf::Time elapsed_time) {
    world.Update(elapsed_time);
}

void Game::Render() {
    my_window.clear();
    world.draw();
    
    my_window.setView(my_window.getDefaultView());
   // my_window.draw(stats_text);
    my_window.display();
}

void Game::HandlePlayerInput(sf::Keyboard::Key key, bool is_pressed) {
    /*if (key == sf::Keyboard::W)
        moving_up = is_pressed;
    else if (key == sf::Keyboard::S)
        moving_down = is_pressed;
    else if (key == sf::Keyboard::A)
        moving_left = is_pressed;
    else if (key == sf::Keyboard::D)
        moving_right = is_pressed;
    
    if (key == sf::Keyboard::I)
        rotate_left = is_pressed;
    else if (key == sf::Keyboard::U)
        rotate_right = is_pressed;*/
}

void Game::UpdateStats(sf::Time elapsed_time) {
    stats_update_time += elapsed_time;
    stats_num_frames += 1;
    
    if (stats_update_time >= sf::seconds(1.0f))
    {
        stats_text.setString(
            "Frames / Second = " + std::to_string(stats_num_frames) + "\n" +
            "Time / Update = " + std::to_string(stats_update_time.asMicroseconds() / stats_num_frames) + "us");
                                 
        stats_update_time -= sf::seconds(1.0f);
        stats_num_frames = 0;
    }
    
}
