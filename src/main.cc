#include<iostream>
#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GAME_NAME "Roguelike Game"

int main()
{
    /*sf::RenderWindow window(sf::VideoMode(800, 600), "Platform Game");
    sf::Event event;
    while(window.isOpen())
    {
       
    }*/

    //Esto es la ventana de mi grafico
    sf::Window* window = new sf::Window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
    //Guardar eventos dentro de mi ventana, mouse, teclado, etc
    sf::Event event;
    //Loop principal, mientras la ventana este abierta, esto se va a ejecutar
    while (window->isOpen())
    {
        //Mientras se ejecute, esto se va a repetir
        while (window->pollEvent(event))
        {
            //Cerrar ventana
            if(event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            std::cout << "left" << std::endl;
        }
     //la clase Keyboard trae la inputs del teclado
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

        //Hay un control conectado
        if(sf::Joystick::isConnected(0)) //Busca el conectado numero 0 en la lista
        {
            //Cachamos el valor del axis X y Y, lo dividimos entre 100, porque el valor minimo de los axis es -100 y maximo 100
            //Escala de 1
            float x{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) / 100};
            float y{sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) / 100};

            // ? = si es verdadero; y : = si es falso
            //El control por si solo nunca deja de mandar valores aunque no lo estes tocando, envia datos
            //Por eso se crean filtros de las entradas de este
            //En este caso el espectro de menor a -0.2 y mayor a 0.2 es el valor 1
            x = x > 0.2f ? 1 : x < -0.2f ? -1 : 0;
            y = -(y > 0.2f ? 1 : y < -0.2f ? -1 : 0);

            std::cout << "X: " << x << " Y: " << y << std::endl;
        }
    }

    return 0;
}