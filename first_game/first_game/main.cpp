
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "game.hpp"
#include <exception>
#include <iostream>


int main(int, char const**)
{
    
    try {
    Game game;
    game.Run();
    }
    catch(std::exception& e) {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
