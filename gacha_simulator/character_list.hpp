//
//  character_list.hpp
//  gacha_simulator
//
//  Created by Yunus Syed on 12/18/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef character_list_hpp
#define character_list_hpp

#include <stdio.h>
#include <vector>
#include "character.hpp"

class CharacterList {
    std::vector<Character> list;
    int rarity_divide; // Position of final character with rarity 4
    
public:
    CharacterList(): rarity_divide(-1) {}
    void AddCharacter(Character new_character);
    int Size();
    int GetDivide();
    virtual void DrawCharacter(int index, sf::RenderTarget& target);
    void LoadCharacters();
    Character GetCharacter(int character_index);
};

#endif /* character_list_hpp */
