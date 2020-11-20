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

Ball::Ball(sf::RenderWindow& new_window) :
window(new_window),
time(),
ball_velocity(0.f, 0.f),
falling(false),
air_time(),
vertical_velocity(0.f)
{
    ball.setPosition(500.f, 100.f);
    ball.setRadius(50.f);
    ball.setOrigin(50.f, 100.f);
    ball.setFillColor(sf::Color::Blue);
}

void Ball::Update(sf::Time dt, bool key_pressed) {
    sf::Vector2f vert_movement(0.f, ball_velocity.y);
    sf::Vector2f hori_movement(ball_velocity.x, 0.f);
    
    sf::Clock key_press_time;
    
    if (key_pressed) {
        Jump();
        ball.move(ball_velocity);
    }
    
    if (ball.getPosition().y <= 900 && falling) { // Ball is falling
        Fall();
        vertical_velocity = .8 * ((vertical_velocity < ball_velocity.y) ? ball_velocity.y : vertical_velocity);
        ball.move(vert_movement);
    }
    
    if (ball.getPosition().y >= 900 && falling) { // Ball hit ground
        SwitchVerticalDirection();
        air_time.restart();
    }
    
    if (ball_velocity.y >= 0 && !falling) { // Ball at apex
        vertical_velocity = 0;
        SwitchVerticalDirection();
        air_time.restart();
    }
    
    if (ball_velocity.y <= 0 && !falling) { // Bounced off ground and heading upwards
        Rise(vertical_velocity);
        ball.move(vert_movement);
    }
    
    if (ball.getPosition().x < 1500 && ball_velocity.x > 0) { // Ball is going to the right
        ball.move(hori_movement);
    }
    
    if (ball.getPosition().x >= 1500 && ball_velocity.x > 0) { // Ball hit right wall
        SwitchHorizontalDirection();
    }
    
    if (ball.getPosition().x >= 0 && ball_velocity.x < 0) { // Ball is going left
        ball.move(hori_movement);
    }
    
    if (ball.getPosition().x < 0 && ball_velocity.x < 0) { // Ball hit left wall
        SwitchHorizontalDirection();
    }
    
}

void Ball::Fall() {
    SetVelocity(ball_velocity.x, 9.8 * air_time.getElapsedTime().asSeconds());
    
}

void Ball::Rise(float vertical_velocity) {
    SetVelocity(ball_velocity.x, 9.8 * air_time.getElapsedTime().asSeconds() - vertical_velocity);
}

void Ball::SwitchVerticalDirection() {
    SetVelocity(ball_velocity.x, ball_velocity.y * -1);
    falling = !falling;
}

void Ball::SwitchHorizontalDirection() {
    SetVelocity(ball_velocity.x * -0.9, ball_velocity.y);
}

float Ball::GetAirTime() const {
    return air_time.getElapsedTime().asSeconds();
}

sf::Vector2f Ball::GetPosition() const {
    return ball.getOrigin();
}

sf::Vector2f Ball::GetVelocity() const {
    return ball_velocity;
}

void Ball::SetVelocity(sf::Vector2f new_velocity) {
    ball_velocity = new_velocity;
}

void Ball::SetVelocity(float x_velocity, float y_velocity) {
    ball_velocity.x = x_velocity;
    ball_velocity.y = y_velocity;
}

void Ball::Jump() {
    air_time.restart();
    falling = false;
    //SetVelocity((ball_velocity.x < 0) ? ball_velocity.x - 1.f : ball_velocity.x + 1.f, ball_velocity.y);
    SetVelocity(0.f, -7.f);
}

void Ball::draw() {
    window.draw(ball);
}

void Ball::DisplayInfo() const {
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(10);
    
    text.setString("Ball Velocity: (" + std::to_string(ball_velocity.x) + ", " +  std::to_string((ball_velocity.y < 0 ? 0 : ball_velocity.y)));
    text.setPosition(20, 20);
    //text.move(ball_velocity);
    window.draw(text);
    
    text.setString("Total Time: " + std::to_string(time.getElapsedTime().asSeconds()));
    text.setPosition(20, 70);
    //text.move(ball_velocity);
    window.draw(text);
    
    text.setString("Current Position: (" + std::to_string(ball.getPosition().x) + ", " + std::to_string(ball.getPosition().y) + ")");
    text.setPosition(20, 120);
    //text.move(ball_velocity);
    window.draw(text);
}

