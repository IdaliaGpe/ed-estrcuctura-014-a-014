#pragma once
#include<SFML/Graphics.hpp>
#include<box2d/box2d.h>
#include "BoxCollider.hh"

class GameObject
{
    private:
        sf::Texture* texture;
        sf::Sprite* sprite;
        float cropPosX;  
        float cropPosY;
        float cropWidth;
        float cropHeight;
        float scaleX;
        float scaleY;
        BoxCollider* boxCollider;
        float tileBaseWidth;
        float tileBaseHeight;
        sf::RenderWindow* window;

        void InitSprite(b2World*&, b2Vec2*);
    public:
        GameObject(sf::Texture*&, float, float, float, float, float, float, b2Vec2*, b2World*&, sf::RenderWindow*&);
        ~GameObject();
};