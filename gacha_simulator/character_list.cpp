//
//  character_list.cpp
//  gacha_simulator
//
//  Created by Yunus Syed on 12/18/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "character_list.hpp"

void CharacterList::AddCharacter(Character new_character) {
    if (new_character.GetRarity() == 4) {
        list.insert(list.begin(), new_character);
        rarity_divide++;
    }
    else {
        list.push_back(new_character);
    }
}

int CharacterList::Size() {
    return list.size();
}

int CharacterList::GetDivide() {
    return rarity_divide;
}

void CharacterList::DrawCharacter(int index, sf::RenderTarget& target) {
    (list[index]).DrawCharacter(target);
}

Character CharacterList::GetCharacter(int character_index) {
    return list[character_index];
}


void CharacterList::LoadCharacters() {
    sf::Texture texture;
    
    Character Albedo("Albedo", 5);
    texture.loadFromFile("characters/albedo.png");
    Albedo.SetTexture(texture);
    AddCharacter(Albedo);
    
    Character Amber("Amber", 4);
    texture.loadFromFile("characters/amber.png");
    Amber.SetTexture(texture);
    AddCharacter(Amber);
    
    Character Ayaka("Ayaka", 5);
    texture.loadFromFile("characters/ayaka.png");
    Ayaka.SetTexture(texture);
    AddCharacter(Ayaka);
    
    Character Barbara("Barbara", 4);
    texture.loadFromFile("characters/barbara.png");
    Barbara.SetTexture(texture);
    AddCharacter(Barbara);

    Character Beidou("Beidou", 4);
    texture.loadFromFile("characters/beidou.png");
    Beidou.SetTexture(texture);
    AddCharacter(Beidou);
    
    Character Bennett("Bennett", 4);
    texture.loadFromFile("characters/bennett.png");
    Bennett.SetTexture(texture);
    AddCharacter(Bennett);

    Character Chongyun("Chongyun", 4);
    texture.loadFromFile("characters/chongyun.png");
    Chongyun.SetTexture(texture);
    AddCharacter(Chongyun);

    Character Diluc("Diluc", 5);
    texture.loadFromFile("characters/diluc.png");
    Diluc.SetTexture(texture);
    AddCharacter(Diluc);

    Character Diona("Diona", 4);
    texture.loadFromFile("characters/diona.png");
    Diona.SetTexture(texture);
    AddCharacter(Diona);

    Character Fischl("Fischl", 4);
    texture.loadFromFile("characters/fischl.png");
    Fischl.SetTexture(texture);
    AddCharacter(Fischl);

    Character Ganyu("Ganyu", 5);
    texture.loadFromFile("characters/ganyu.png");
    Ganyu.SetTexture(texture);
    AddCharacter(Ganyu);

    Character Jean("Jean", 5);
    texture.loadFromFile("characters/jean.png");
    Jean.SetTexture(texture);
    AddCharacter(Jean);

    Character Kaeya("Kaeya", 4);
    texture.loadFromFile("characters/kaeya.png");
    Kaeya.SetTexture(texture);
    AddCharacter(Kaeya);

    Character Keqing("Keqing", 5);
    texture.loadFromFile("characters/keqing.png");
    Keqing.SetTexture(texture);
    AddCharacter(Keqing);

    Character Klee("Klee", 5);
    texture.loadFromFile("characters/klee.png");
    Klee.SetTexture(texture);
    AddCharacter(Klee);

    Character Lisa("Lisa", 4);
    texture.loadFromFile("characters/lisa.png");
    Lisa.SetTexture(texture);
    AddCharacter(Lisa);

    Character Mona("Mona", 5);
    texture.loadFromFile("characters/mona.png");
    Mona.SetTexture(texture);
    AddCharacter(Mona);

    Character Ningguang("Ningguang", 4);
    texture.loadFromFile("characters/ningguang.png");
    Ningguang.SetTexture(texture);
    AddCharacter(Ningguang);

    Character Noelle("Noelle", 4);
    texture.loadFromFile("characters/Noelle.png");
    Noelle.SetTexture(texture);
    AddCharacter(Noelle);

    Character Qiqi("Qiqi", 5);
    texture.loadFromFile("characters/qiqi.png");
    Qiqi.SetTexture(texture);
    AddCharacter(Qiqi);

    Character Razor("Razor", 4);
    texture.loadFromFile("characters/razor.png");
    Razor.SetTexture(texture);
    AddCharacter(Razor);

    Character Sucrose("Sucrose", 4);
    texture.loadFromFile("characters/sucrose.png");
    Sucrose.SetTexture(texture);
    AddCharacter(Sucrose);

    Character Tartaglia("Tartaglia", 5);
    texture.loadFromFile("characters/tartaglia.png");
    Tartaglia.SetTexture(texture);
    AddCharacter(Tartaglia);

    Character Venti("Venti", 5);
    texture.loadFromFile("characters/venti.png");
    Venti.SetTexture(texture);
    AddCharacter(Venti);

    Character Xiangling("Xiangling", 4);
    texture.loadFromFile("characters/xiangling.png");
    Xiangling.SetTexture(texture);
    AddCharacter(Xiangling);

    Character Xiao("Xiao", 5);
    texture.loadFromFile("characters/xiao.png");
    Xiao.SetTexture(texture);
    AddCharacter(Xiao);

    Character Xingqiu("Xingqiu", 4);
    texture.loadFromFile("characters/xingqiu.png");
    Xingqiu.SetTexture(texture);
    AddCharacter(Xingqiu);

    Character Xinyan("Xinyan", 4);
    texture.loadFromFile("characters/xinyan.png");
    Xinyan.SetTexture(texture);
    AddCharacter(Xinyan);

    Character Zhongli("Zhongli", 5);
    texture.loadFromFile("characters/zhongli.png");
    Zhongli.SetTexture(texture);
    AddCharacter(Zhongli);
    
}
