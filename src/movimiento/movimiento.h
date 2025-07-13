#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include <SFML/Graphics.hpp>

// Clase Personaje: representa al jugador en pantalla
class Personaje {
 private:
   sf::RectangleShape forma;  // Rectángulo que representa al personaje
   float velocidad;           // Velocidad de movimiento
 public:
   Personaje();                                // Constructor
   void mover(const sf::RenderWindow& ventana); // Mover según teclas
   void dibujar(sf::RenderWindow& ventana);     // Dibujar en pantalla
};

#endif