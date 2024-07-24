#include <SFML/Graphics.hpp>
#include <iostream>
#include "Heroi.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hero Game");

    Heroi heroi;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Erro ao abrir a fonte" << std::endl;
        return -1;
    }

    sf::Text hpText;
    hpText.setFont(font);
    hpText.setCharacterSize(12);
    hpText.setFillColor(sf::Color::Red);

    sf::Text ammoText;
    ammoText.setFont(font);
    ammoText.setCharacterSize(12);
    ammoText.setFillColor(sf::Color::White);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            heroi.andar(0, -200 * clock.getElapsedTime().asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            heroi.andar(0, 200 * clock.getElapsedTime().asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            heroi.andar(-200 * clock.getElapsedTime().asSeconds(), 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            heroi.andar(200 * clock.getElapsedTime().asSeconds(), 0);
        }

        
        clock.restart();

    
        hpText.setString("HP: " + std::to_string(heroi.getHP()));
        ammoText.setString("Ammo: " + std::to_string(heroi.getMunicao()));

        
        sf::Vector2f heroiPos = heroi.getPosition();
        hpText.setPosition(heroiPos.x, heroiPos.y - 30);
        ammoText.setPosition(heroiPos.x, heroiPos.y - 60);

        window.clear(sf::Color::Black);
        heroi.draw(window);
        window.draw(hpText);
        window.draw(ammoText);
        window.display();
    }

    return 0;
}