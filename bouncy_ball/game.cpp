//
//  game.cpp
//  bouncy_ball
//
//  Created by Yunus Syed on 11/15/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "game.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>


Game::Game():
my_window(sf::VideoMode(1500, 1500), "Bouncy Ball"),
world(my_window),
key_pressed(false),
time_per_frame(sf::seconds(1.f/60.f))
{
    
}

void Game::Run() {
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    while (my_window.isOpen()) {
        time_since_last_update += clock.restart();
        while(time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            ProcessEvents();
            Update(time_per_frame, key_pressed);
        }
        Render();
    }
}

void Game::ProcessEvents() {
    sf::Event event;
    while (my_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed)
            key_pressed = true;
            //key_pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        if (event.type == sf::Event::KeyReleased)
            key_pressed = false;
        if (event.type == sf::Event::Closed) {
            my_window.close();
            break;
        }
    }
}

void Game::Update(sf::Time dt, bool is_pressed) {
    world.Update(dt, is_pressed);
}

void Game::Render() {
    my_window.clear();
    world.draw();
    DisplayInfo();
    my_window.display();
}

void Game::DisplayInfo() {
    world.DisplayInfo();
}
