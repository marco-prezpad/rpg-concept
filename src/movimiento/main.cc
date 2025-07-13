#include <SFML/Graphics.hpp>
#include "movimiento.h"

int main() {
  // Crear la ventana principal (800x600 píxeles)
  sf::RenderWindow ventana(sf::VideoMode(800, 600), "Movimiento WASD");

  // Crear una instancia del personaje
  Personaje jugador;

  // Bucle del juego
  while (ventana.isOpen()) {
    sf::Event evento;
    // Procesar eventos (como cerrar la ventana)
    while (ventana.pollEvent(evento)) {
      if (evento.type == sf::Event::Closed)
      ventana.close();
    }

    // Actualizar movimiento del personaje
    jugador.mover(ventana);

    // Dibujar en pantalla
    ventana.clear();          // Borrar la pantalla (fondo negro por defecto)
    jugador.dibujar(ventana); // Dibujar el personaje
    ventana.display();        // Mostrar lo dibujado
  }
  return 0;
}
