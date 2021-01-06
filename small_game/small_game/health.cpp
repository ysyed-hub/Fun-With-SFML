//
//  health.cpp
//  small_game
//
//  Created by Yunus Syed on 1/3/21.
//  Copyright © 2021 Yunus Syed. All rights reserved.
//

#include "health.hpp"

Health::Health(): health_amount(100) {
    health_bar.setFillColor(sf::Color::Red);
    health_bar.setOutlineColor(sf::Color::White);
    health_bar.setOutlineThickness(1.f);
    health_bar.setPosition(5.f, 10.f);
}

void Health::DecreaseHealth(int amount) {
    health_amount -= amount;
}

void Health::IncreaseHealth(int amount) {
    health_amount += amount;
}

void Health::DrawHealthBar(sf::RenderTarget &target) {
    health_bar.setSize({3.f * health_amount, 20});
    target.draw(health_bar);
}
