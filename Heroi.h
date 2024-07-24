#ifndef HEROI_H
#define HEROI_H
#include <SFML/Graphics.hpp>

class Heroi
{

private:
    int HP;
    int Municao;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Heroi();
    void andar(float dx, float dy);
    void atirar();
    void dano_tomado(int dano);
    void draw(sf::RenderWindow& window);

    int getHP() const;
    int getMunicao() const;
    sf::Vector2f getPosition() const;
};
#endif