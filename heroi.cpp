#include "Heroi.h"
#include <iostream>

Heroi::Heroi() : HP(100), Municao(50){
    if(!texture.loadFromFile("images/personagem.png")){
        std::cerr << "Erro ao carregar a imagem" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(400,300); //Centro da janela
    sprite.setScale(0.05f,0.05f);  //Escala dependendo do tomanaho da imagem
} 

void Heroi::andar(float dx, float dy){ //Direção x e y
    sprite.move(dx, dy);
}

void Heroi::atirar(){
    if(Municao > 0){
        Municao--;
        //Mecanica de atirar:

    }
}

void Heroi::dano_tomado(int dano){
    HP -= dano;
    if (HP < 0){
        HP = 0;
        //Morte do Herói:

    }
}

void Heroi::draw(sf::RenderWindow& window){
    window.draw(sprite);
}

int Heroi::getHP() const{
    return HP;
}

int Heroi::getMunicao() const{
    return Municao;
}

sf::Vector2f Heroi::getPosition() const {
    return sprite.getPosition();
}
