//
//  gacha.hpp
//  gacha_simulator
//
//  Created by Yunus Syed on 12/18/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef gacha_hpp
#define gacha_hpp

#include <stdio.h>
#include "character_list.hpp"
#include <SFML/Graphics.hpp>


class Gacha {
    sf::RenderWindow window;
    CharacterList all_characters;
    int pity;
    
public:
    Gacha();
    void Roll();
    void Spinner();
    sf::Keyboard::Key ProcessInput();
    void Run();
    void Render(sf::Keyboard::Key input);
    void DisplayStats(int character_number);
};

#endif /* gacha_hpp */
