//
//  game.hpp
//  small_game
//
//  Created by Yunus Syed on 12/26/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "airplane.hpp"
#include <SFML/Graphics.hpp>
#include "enemy.hpp"
#include "small_enemy.hpp"
#include <vector>

class Game {
    sf::RenderWindow window;
    Airplane user;
    std::vector<Bullet> bullets;
    std::vector<BigEnemy> big_enemies;
    std::vector<SmallEnemy> small_enemies;
    int level;
    
public:
    Game();
    void Run();
    void Draw();
    sf::Keyboard::Key ProcessInput();
    void Update(sf::Keyboard::Key input, sf::Time dt);
    void Render();
    
public:
    void LevelSetup(int level);
    void CheckForImpact();
    void FireBullet();
    void ReduceBullets();
    bool DetectImpact(sf::CircleShape thing_1, sf::CircleShape thing_2);
    
public:
    void Move(sf::Keyboard::Key input, sf::Time dt);
};

#endif /* game_hpp */
