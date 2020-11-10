//
//  ball.cpp
//  bouncy_ball
//
//  Created by Yunus Syed on 11/9/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "ball.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>


Ball::Ball(): my_window(sf::VideoMode(3000, 3000), "Bouncy Ball"), air_time(), time(), ball_velocity(0.f), ball_falling(true), time_per_frame(sf::seconds(1.f/30.f)), max_velocity(0.f) {
    ball.setPosition(500.f, 100.f);
    ball.setRadius(50.f);
    ball.setOrigin(50.f, 100.f);
    ball.setFillColor(sf::Color::Red);
}

void Ball::Run() {
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    while (my_window.isOpen()) {
        ProcessEvents();
        time_since_last_update += clock.restart();
        while(time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            ProcessEvents();
            Update();
        }
        Render();
    }
}

void Ball::ProcessEvents() {
    sf::Event event;
    while (my_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            my_window.close();
            break;
        }
    }
}

void Ball::Update() {
    float *ball_velocityptr = &ball_velocity;
    sf::Vector2f movement(0.f, ball_velocity);
    
    if (ball.getPosition().y <= 700 && ball_falling) { // Ball is falling
        Fall(ball_velocityptr);
        max_velocity = .8 * ((max_velocity < ball_velocity) ? ball_velocity : max_velocity);
        ball.move(movement);
    }
    
    if (ball.getPosition().y >= 700 && ball_falling) { // Ball hit ground
        SwitchDirection();
        Bounce();
        air_time.restart();
    }
    
    if (ball_velocity <= 0 && !ball_falling) { // Ball at apex
        max_velocity = 0;
        SwitchDirection();
        air_time.restart();
    }
    
    if (ball_velocity > 0 && !ball_falling) { // Bounced off ground and heading upwards
        Rise(ball_velocityptr, max_velocity);
        ball.move(-movement);
    }
    
}

void Ball::Render() {
    my_window.clear();
    my_window.draw(ball);
    DisplayInfo();
    my_window.display();
}

void Ball::Fall(float *ball_velocityptr) {
    *ball_velocityptr = 9.8 * air_time.getElapsedTime().asSeconds();
    //current_position.y += *ball_velocityptr;
}

void Ball::Rise(float *ball_velocityptr, float upward_velocity) {
    *ball_velocityptr = upward_velocity - 9.8 * air_time.getElapsedTime().asSeconds();
    //current_position.y -= *ball_velocityptr;
}

void Ball::SwitchDirection() {
    ball_falling = !ball_falling;
}

void Ball::DisplayInfo() {
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(10);
    
    text.setString("Ball Velocity: " + std::to_string(ball_velocity));
    text.setPosition(20, 20);
    my_window.draw(text);
    
    text.setString("Air Time: " + std::to_string(air_time.getElapsedTime().asSeconds()));
    text.setPosition(20, 70);
    my_window.draw(text);
    
    text.setString("Total Time: " + std::to_string(time.getElapsedTime().asSeconds()));
    text.setPosition(20, 120);
    my_window.draw(text);
    
    text.setString("Current Position: (" + std::to_string(ball.getPosition().x) + ", " + std::to_string(ball.getPosition().y) + ")");
    text.setPosition(20, 170);
    my_window.draw(text);

}


void Ball::Bounce() {
    sf::SoundBuffer bounce;
    if (!bounce.loadFromFile("bounce.wav")) {
        std::cout << "Error loading bounce.wav" << std::endl;
    }
    sf::Sound bounce_sound;
    bounce_sound.setBuffer(bounce);
    bounce_sound.play();
}
