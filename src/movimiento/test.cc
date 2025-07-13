#include <iostream>
#include "movimiento.h"

int main() {
  Movimiento jugador;
  char tecla;
  
  std::cout << "Usar WASD para mover al personaje. Q para salir.\n";
  
  while (true) {
    std::cin >> tecla;
    
    if (tecla == 'q' || tecla == 'Q') break;
    
    jugador.mover(tecla);
    std::cout << "Posicion: (" << jugador.getX() << ", " << jugador.getY() << ")\n";
  }
  
  return 0;
}
