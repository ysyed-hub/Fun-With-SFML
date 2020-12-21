//
//  Textures.cpp
//  first_game
//
//  Created by Yunus Syed on 11/8/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "Textures.hpp"
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>

void TextureHolder::Load(Textures::ID id, const std::string &filename) {
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    if (!texture->loadFromFile(filename)) {
        throw std::runtime_error("TextureHolder::Load - Failed to load" + filename);
    }
    
    my_texture_map.insert(std::make_pair(id, std::move(texture)));
}

sf::Texture& TextureHolder::Get(Textures::ID id) {
    auto found = my_texture_map.find(id);
    return *(found -> second);
}

const sf::Texture& TextureHolder::Get(Textures::ID id) const {
    auto found = my_texture_map.find(id);
    return *(found -> second);
}
