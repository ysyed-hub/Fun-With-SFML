//
//  Textures.hpp
//  first_game
//
//  Created by Yunus Syed on 11/8/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef Textures_hpp
#define Textures_hpp

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>


namespace Textures {
enum ID {Landscape, Airplane, Missile, };
}

class TextureHolder {
    
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> my_texture_map;
    
public:
    void Load(Textures::ID id, const std::string& filename);
    sf::Texture& Get(Textures::ID id);
    const sf::Texture& Get(Textures::ID id) const;
};



#endif /* Textures_hpp */
