#include<iostream>
#include <SFML/Graphics.hpp>

#include "Inputs.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define GAME_NAME "Roguelike game"

int main()
{
    //esto es la ventana de tu grafico
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
    //aqui vas a guardar los eventos dentro de la ventana, eje: teclado, mouse, etc.
    sf::Event event;

    Inputs* inputs = new Inputs();

    window->setVerticalSyncEnabled(true);


    /////Tarea

    // Creamos una textura
    sf::Texture textura;

    // Cargamos la textura desde un archivo
    if(!textura.loadFromFile("data/terezi.png"))
    {
        // Si hay un error salimos

        return EXIT_FAILURE;
    }

    // Creamos un sprite
    sf::Sprite sprite;

    // Asignamos la textura al sprite
    sprite.setTexture(textura);

    // Seleccionamos solo un rectangulo de la textura
    sprite.setTextureRect(sf::IntRect(120, 120, 128, 128));

    // Movemos el sprite
    sprite.move(100, 100);

    // Cambiamos el origen al centro del sprite
    sf::Vector2f centro;
    centro.x = sprite.getTextureRect().width / 2.f;
    centro.y = sprite.getTextureRect().height / 2.f;
    sprite.setOrigin(centro);
    
    // Rotamos el sprite 360 grados
    sprite.rotate(360);


    // Creamos otro sprite con la MISMA textura
    sf::Sprite terezi(textura);
    //el 100, 100 son la posicion donde estara en la pantalla
    terezi.setPosition(200, 100);

    //los 0 son las coordenadas en x y Y de donde se empezara a recortar la foto, mientras que los 364 son la resolución de la imagen (mientras menos estara más cortada
    //si le pones de más se va a estirar para que se cumpla con la resolución indicada (y se ve bien culero))
    terezi.setTextureRect(sf::IntRect(0, 0, 364, 364));





    //Clase


    
    //esto es el loop principal, mientras la ventana este abierta, esto se va ejecutar.
    while (window->isOpen())
    {
        //mientras se esten ejecutando eventos dentro de la ventana, esto se va repetir eje: teclado, joystick, mouse, etc
        while (window->pollEvent(event))
        {
            //si el evento fue la acción de cerrar la ventana, entonces termina la aplicación.
            if(event.type == sf::Event::Closed)
            {
                window->close();
            }
        }
        
        Vec2* keyboardAxis{inputs->GetKeyboardAxis()};
        Vec2* joystickAxis{inputs->GetJoystickAxis()};
        //std::cout << "keyboard axis x: " << keyboardAxis->x << " keyboard axis y: " << keyboardAxis->y << std::endl;
        
        std::cout << "joystic axis x: " << joystickAxis->x << " joystic axis y: " << joystickAxis->y << std::endl;

        //inputs->GetJoystickAxis();
        delete keyboardAxis;
        delete joystickAxis;

        window->clear(sf::Color(180, 200, 255));
        window->draw(sprite);
        window->draw(terezi);   
        window->display();
    }

    //return 0;
 
    std::cout << &window << std::endl;
    std::cout << &textura << std::endl;
    std::cout << &terezi << std::endl;
    std::cout << &sprite << std::endl;
    std::cin.get();

    return 0;
}