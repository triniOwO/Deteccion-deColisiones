#include <SFML/Graphics.hpp>
#include <fstream>
using namespace sf;

int main()
{
    float x_min = 0.f, x_max = 800.f , y_min = 0.f, y_max = 400.f; //tamaño de la ventana
    float x_triangulo = x_max / 2; //coordenada x inicial de figura (triangulo)
    float y_triangulo = y_max / 2; //coordenada y inicial de figura (triangulo)
    float  radio_triangulo = 21.f; //Tamaño del triangulo
    float x_mov_triangulo = 10.f, y_mov_triangulo = 10.f;//incremento de coordenadas o velocidad del triangulo

    float x_rectangulo = x_max / 100; //coordenada x inicial de figura (rectangulo)
    float y_rectangulo = y_max / 2.3; //coordenada y inicial de figura (rectangulo)
    float  radio_rectangulo = 21.f; //Tamaño del rectangulo

    // creamos la ventana de 800x400 pixeles
    RenderWindow ventana(VideoMode(x_max, y_max), "@IntellVirtual!");
    ventana.setVerticalSyncEnabled(true);

    // definimos el triangulo
    CircleShape triangulo(radio_triangulo,3);
    triangulo.setPosition(x_triangulo, y_triangulo);
    triangulo.setFillColor(Color::Red);

    // definimos un rectangulo 20x60
    RectangleShape rectangulo(Vector2f(20, 60));
    rectangulo.setPosition(x_rectangulo, y_rectangulo);
    rectangulo.setFillColor(Color::Yellow);


     // ejecutar el programa mientras la ventana esté abierta
    while (ventana.isOpen())
    {

        //verificamos todos los eventos de la ventana
        Event event;

        while (ventana.pollEvent(event))
        {
            // "cierre solicitado" evento: cerramos la ventana
            if (event.type == Event::Closed)
                ventana.close();
       }

  //posicion actual  del triangulo
  Vector2f posicion_triangulo = triangulo.getPosition();
  x_triangulo = posicion_triangulo.x;
  y_triangulo = posicion_triangulo.y;

  // mueve el triangulo dentro de los limites de la ventana con las teclas A,D y las flechas
  if ((Keyboard::isKeyPressed(Keyboard::Right) ||
      (Keyboard::isKeyPressed(Keyboard::D)))   && x_triangulo < x_max - radio_triangulo *2)
      triangulo.move(x_mov_triangulo,0.f);

  if ((Keyboard::isKeyPressed(Keyboard::Left) ||
      (Keyboard::isKeyPressed(Keyboard::A)))  && x_triangulo > x_min)
      triangulo.move(-x_mov_triangulo,0.f);

  //obtenemos los limites globales a partir de las cordenadas del triangulo y el rectangulo
  FloatRect rectanguloBox = rectangulo.getGlobalBounds();
  FloatRect trianguloBox = triangulo.getGlobalBounds();

  //si el triangulo intersecta al rectangulo, este cambia a color azul(colision)
  if (trianguloBox.intersects(rectanguloBox))
    {
    rectangulo.setFillColor(Color::Blue);
    }

  //Si no se cumple la condicion vuelve a su color original(Amarillo)
  else
    {
    rectangulo.setFillColor(Color::Yellow);
    }

    // limpiamos la ventana con el color blanco
    ventana.clear(Color::White);
    // aqui dibujamos del triangulo en la ventana
    ventana.draw(triangulo);
    // aqui dibujamos el rectangulo en la ventana
    ventana.draw(rectangulo);
    // mostramos ventana en la pantalla
    ventana.display();
    }

return 0;
}
