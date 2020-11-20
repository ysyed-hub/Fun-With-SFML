//
//  resource_identifier.hpp
//  bouncy_ball
//
//  Created by Yunus Syed on 11/16/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef resource_identifier_hpp
#define resource_identifier_hpp

#include <stdio.h>


namespace sf
{
    class Texture;
}

namespace Textures
{
    enum ID
    {
        Court,
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif /* resource_identifier_hpp */
