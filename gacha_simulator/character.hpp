//
//  character.hpp
//  gacha_simulator
//
//  Created by Yunus Syed on 12/18/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef character_hpp
#define character_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Character {
    std::string name;
    int rarity;
    sf::Texture character_graphic;
    
public:
    Character(std::string name, int rarity);
    std::string GetName();
    int GetRarity();
    virtual void DrawCharacter(sf::RenderTarget& target);
    void SetTexture(sf::Texture texture);
    
};


#endif /* character_hpp */
