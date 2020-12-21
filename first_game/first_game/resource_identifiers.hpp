//
//  resource_identifiers.hpp
//  first_game
//
//  Created by Yunus Syed on 11/13/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef resource_identifiers_hpp
#define resource_identifiers_hpp

#include <stdio.h>


namespace sf
{
    class Texture;
}

namespace Textures
{
    enum ID
    {
        Eagle,
        Raptor,
        Desert,
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;



#endif /* resource_identifiers_hpp */
