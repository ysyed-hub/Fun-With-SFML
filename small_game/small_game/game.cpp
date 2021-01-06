//
//  game.cpp
//  small_game
//
//  Created by Yunus Syed on 12/26/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "game.hpp"
#include <cmath>
#include <iostream>


Game::Game():
window(sf::VideoMode(1000, 1000), "Small Game"),
user(),
level(1),
big_enemies(),
small_enemies(),
bullets()
{
    LevelSetup(level);
}

void Game::Run() {
    sf::Clock time;
    sf::Time time_since_last_update = sf::Time::Zero;
    const sf::Time time_per_frame(sf::seconds(1/120.f));
    
    while (window.isOpen()) {
        sf::Time elapsed_time = time.restart();
        time_since_last_update += time.getElapsedTime();
        while (time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            sf::Keyboard::Key input = ProcessInput();
            Update(input, time_per_frame);
            Render();
        }
    }
}

sf::Keyboard::Key Game::ProcessInput() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F) {
                    return sf::Keyboard::F;
                }
                else if (event.key.code == sf::Keyboard::W)
                    return sf::Keyboard::W;
                else if (event.key.code == sf::Keyboard::A)
                    return sf::Keyboard::A;
                else if (event.key.code == sf::Keyboard::S)
                    return sf::Keyboard::S;
                else if (event.key.code == sf::Keyboard::D)
                    return sf::Keyboard::D;
                else if (event.key.code == sf::Keyboard::U)
                    return sf::Keyboard::U;
                else if (event.key.code == sf::Keyboard::I)
                    return sf::Keyboard::I;
            }
    
            if (event.type == sf::Event::Closed)
                window.close();
        }
        return sf::Keyboard::B;
}

void Game::Update(sf::Keyboard::Key input, sf::Time dt) {
    if (input == sf::Keyboard::F) {
        FireBullet();
    }
    CheckForImpact();
    Move(input, dt);
    ReduceBullets();
    
    
    if (big_enemies.size() == 0 && small_enemies.size() == 0) {
        level++;
        while (bullets.size() > 0)
            bullets.erase(bullets.begin());
        LevelSetup(level);
    }
    
    if (bullets.size() > 0)
        std::cout << bullets[0].GetPosition().x << " " << bullets[0].GetPosition().y << std::endl;
}

void Game::Render() {
    window.clear();
    Draw();
    window.display();
}


void Game::FireBullet() {
    Bullet new_bullet(user.GetPosition(), user.GetRotation());
    bullets.push_back(new_bullet);
}

void Game::CheckForImpact() {
    for (int i = 0; i < bullets.size(); i++) {
        for (int j = 0; j < big_enemies.size(); j++) {
            if (DetectImpact(bullets[i].GetGraphic(), big_enemies[j].GetGraphic())) {
                std::cout << "Impact0" << std::endl;
                bullets[i].MadeImpact();
                big_enemies[j].MadeImpact();
            }
        }
    }
    
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].GetImpactStatus() == true) {
            bullets.erase(bullets.begin() + i);
            i--;
        }
    }
    
    for (int i = 0; i < big_enemies.size(); i++) {
        if (big_enemies[i].GetImpactStatus() == true) {
            for (int j = 0; j < 4; j++) {
                SmallEnemy new_enemy(big_enemies[i].GetPosition(), big_enemies[i].GetSize(), j);
                small_enemies.push_back(new_enemy);
            }
            big_enemies.erase(big_enemies.begin() + i);
            i--;
        }
    }
            
    for (int i = 0; i < bullets.size(); i++) {
        for (int j = 0; j < small_enemies.size(); j++) {
            if (DetectImpact(bullets[i].GetGraphic(), small_enemies[j].GetGraphic())) {
                std::cout << "Impact1" << std::endl;
                bullets[i].MadeImpact();
                small_enemies[j].MadeImpact();
            }
        }
    }
    
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].GetImpactStatus() == true) {
            bullets.erase(bullets.begin() + i);
            i--;
        }
    }
    
    for (int i = 0; i < small_enemies.size(); i++) {
        if (small_enemies[i].GetImpactStatus() == true) {
            small_enemies.erase(small_enemies.begin() + i);
            i--;
        }
    }
    
}



void Game::Draw() {
    user.DrawPlayer(window);
    for (int i = 0; i < big_enemies.size(); i++)
        big_enemies[i].DrawBigEnemy(window);
    for (int i = 0; i < small_enemies.size(); i++)
        small_enemies[i].DrawSmallEnemy(window);
    for (int i = 0; i < bullets.size(); i++)
        bullets[i].DrawBullet(window);
}

void Game::Move(sf::Keyboard::Key input, sf::Time dt) {
    user.Movement(input, dt);
    for (int i = 0; i < bullets.size(); i++)
        bullets[i].Move(dt);
    for (int i = 0; i < small_enemies.size(); i++)
        small_enemies[i].Move(dt);
    
}

void Game::LevelSetup(int level) {
    for (int i = 0; i < level; i++) {
        sf::Vector2f enemy_position = {static_cast<float>(500 + rand()%400), static_cast<float>(rand()%700)};
        BigEnemy new_enemy(enemy_position);
        big_enemies.push_back(new_enemy);
    }
}

void Game::ReduceBullets() {
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].GetPosition().x > 1000 || bullets[i].GetPosition().x < 0)
            bullets.erase(bullets.begin()+i);
        if (bullets[i].GetPosition().y > 1000 || bullets[i].GetPosition().y < 0)
            bullets.erase(bullets.begin()+i);
    }
}

bool Game::DetectImpact(sf::CircleShape thing_1, sf::CircleShape thing_2) {
    sf::Vector2f center_1 = {thing_1.getPosition().x + thing_1.getRadius(), thing_1.getPosition().y + thing_1.getRadius()};
    sf::Vector2f center_2 = {thing_2.getPosition().x + thing_2.getRadius(), thing_2.getPosition().y + thing_2.getRadius()};
    
    float distance = sqrtf(pow(center_1.x - center_2.x, 2) + pow(center_1.y - center_2.y, 2));
    
    if (distance < thing_1.getRadius() + thing_2.getRadius())
        return true;
    
    return false;
}
