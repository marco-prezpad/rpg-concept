#include "movimiento.h"

// Constructor: inicializa la forma y la velocidad
Personaje::Personaje() {
  forma.setSize({40, 40});              // Tamaño del personaje (cuadrado 40x40)
  forma.setFillColor(sf::Color::Green); // Color verde
  forma.setPosition(400, 300);          // Posición inicial (centro de 800x600)
  velocidad = 5.0f;                     // Velocidad en píxeles por frame
}

// Mover al personaje con teclas WASD
void Personaje::mover(const sf::RenderWindow& ventana) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) forma.move(0, -velocidad); // Arriba
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) forma.move(0, velocidad);  // Abajo
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) forma.move(-velocidad, 0); // Izquierda
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) forma.move(velocidad, 0);  // Derecha
}

  // Dibuja el personaje en la ventana
  void Personaje::dibujar(sf::RenderWindow& ventana) {
  ventana.draw(forma);
}