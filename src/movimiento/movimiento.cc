#include "movimiento.h"

Movimiento::Movimiento() : x(0), y(0) {}

void Movimiento::mover(char tecla) {
  switch (tecla) {
    case 'w': y++; break;
    case 's': y--; break;
    case 'a': x--; break;
    case 'd': x++; break;
  }
}

// getters
int Movimiento::getX() const { return x; }

int Movimiento::getY() const { return y; }