#include <iostream>
#include <conio.h>  // Para _kbhit() y _getch()

int main() {
  int x = 0, y = 0;  // Posición inicial del personaje (ficticia)
  
  std::cout << "Controla el personaje con WASD. Pulsa 'Q' para salir.\n";
  
  while (true) {
    if (_kbhit()) { // Si se ha pulsado una tecla
      char tecla = _getch(); // Leer la tecla (sin esperar Enter)
  
      if (tecla == 'q' || tecla == 'Q') break; // Salir con Q
  
      switch (tecla) {
        case 'w': y++; break; // Arriba
        case 's': y--; break; // Abajo
        case 'a': x--; break; // Izquierda
        case 'd': x++; break; // Derecha
      }
  
      std::cout << "Posicion: (" << x << ", " << y << ")\n";
    }
  }
  
  std::cout << "Fin del programa.\n";
  return 0;
}
