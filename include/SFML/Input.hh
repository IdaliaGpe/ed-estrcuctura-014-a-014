#include<iostream>
#include <SFML/Graphics.hpp>

class Input
{
private:
{
    Key* = key;
    Vec* = axis;
}
public:
{
    Key* Teclas()
{
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            std::cout << "left" << std::endl;
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            std::cout << "right" << std::endl;
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            std::cout << "up" << std::endl;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            std::cout << "down" << std::endl;
        }
},

   Vec* JoystickAxis()
   {
       float x{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) / 100};
       float y{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) / 100};
       
       x = x > 0.2f ? 1 : x < -0.2f ? -1 : 0;
       y = -(y > 0.2f ? 1 : y < -0.2f ? -1 : 0);
       
       std::cout << "X: " << x << " Y: " << y << std::endl;
   }
};

