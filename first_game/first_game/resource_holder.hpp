//
//  resource_holder.hpp
//  first_game
//
//  Created by Yunus Syed on 11/13/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#ifndef resource_holder_hpp
#define resource_holder_hpp

#include <stdio.h>
#include <map>
#include <string>

template <typename Resource, typename Identifier>
class ResourceHolder {
    
public:
    void Load(Identifier id, const std::string& filename);
    
    template <typename Parameter>
    void Load(Identifier id, const std::string& filename, const Parameter& second_parameter);
    
    Resource& get(Identifier id);
    const Resource& get(Identifier id) const;
    
private:
    void InsertResource(Identifier id, std::unique_ptr<Resource> resource);
    std::map<Identifier, std::unique_ptr<Resource>> my_resource_map;
    
};



#include "resource_holder.inl"
#endif /* resource_holder_hpp */
