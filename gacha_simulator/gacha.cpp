//
//  gacha.cpp
//  gacha_simulator
//
//  Created by Yunus Syed on 12/18/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include "gacha.hpp"

Gacha::Gacha():
window(sf::VideoMode(1000, 1000), "Gacha Game"),
pity(0)
{
    all_characters.LoadCharacters();
}

void Gacha::Spinner() {
    int chosen = rand() % all_characters.Size();
    all_characters.DrawCharacter(chosen, window);
    window.display();
    sf::Clock gap_time;
    while (gap_time.getElapsedTime().asSeconds() < .05)
        ;
    window.clear();
}

void Gacha::Roll() {
    int rarity_rolled = 4;
    
    if (pity < 75) {
        int x = rand() % 1000 + 1;
        std::cout << x << std::endl;
        std::cout << rarity_rolled << std::endl;
        if (x > 994)
            rarity_rolled = 5;
    }
    else if (pity < 90) {
        int x = rand() % 100 + 1;
        if (x > 94)
            rarity_rolled = 5;
    }
    else
        rarity_rolled = 5;
        
    if (rarity_rolled == 4)
        pity++;
    else {
        pity = 0;
    }
    
    /*sf::Clock roll_time;
    while (roll_time.getElapsedTime().asSeconds() < 0.05) {
        sf::Clock gap_time;
        while (gap_time.getElapsedTime().asSeconds() > .2) {
            int chosen = rand() % all_characters.Size();
            all_characters.DrawCharacter(chosen, window);
            window.display();
            gap_time.restart();
            
            while (gap_time.getElapsedTime().asSeconds() < .2)
                ;
            //window.clear();
        }
    }*/
    
    for (int i = 0; i < 50; i++)
        Spinner();
    
    int chosen;
    if (rarity_rolled == 5) {
        chosen = rand() % (all_characters.Size() - all_characters.GetDivide()) + all_characters.GetDivide();
        all_characters.DrawCharacter(chosen, window);
    }
    else {
        chosen = rand() % all_characters.GetDivide();
        all_characters.DrawCharacter(chosen, window);
    }
    DisplayStats(chosen);
    window.display();
    
}

void Gacha::Run() {
    while (window.isOpen()) {
        sf::Keyboard::Key input = ProcessInput();
        Render(input);
    }
}

sf::Keyboard::Key Gacha::ProcessInput() {
    sf::Event event;
    
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
            return sf::Keyboard::R;
        }
        
        if (event.type == sf::Event::Closed)
            window.close();
    }
    
    return sf::Keyboard::A;
    
}

void Gacha::Render(sf::Keyboard::Key input) {
    if (input == sf::Keyboard::R) {
        window.clear();
        Roll();
    }
}

void Gacha::DisplayStats(int character_number) {
    sf::Font font;
    font.loadFromFile("sansation.ttf");
    sf::Text text;
    text.setFont(font);
    
    text.setString(all_characters.GetCharacter(character_number).GetName());
    text.setPosition(465.f, 450.f);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(15.f);
    window.draw(text);
    
    /*text.setString("pity: " + std::to_string(pity));
    text.setPosition(10.f, 10.f);
    window.draw(text);*/
    
    
}
