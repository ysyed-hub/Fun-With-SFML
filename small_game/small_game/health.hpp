//
//  health.hpp
//  small_game
//
//  Created by Yunus Syed on 1/3/21.
//  Copyright © 2021 Yunus Syed. All rights reserved.
//

#ifndef health_hpp
#define health_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Health {
    int health_amount;
    sf::RectangleShape health_bar;
public:
    Health();
    void IncreaseHealth(int amount);
    void DecreaseHealth(int amount);
    int GetHealth();
    void DrawHealthBar(sf::RenderTarget& target);
};

#endif /* health_hpp */
