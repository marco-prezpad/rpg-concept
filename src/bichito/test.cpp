#include "bichito.h"

bool TestBichito() {
  // Creamos dos bichitos con stats iniciales
  // Cucaracho Eduardus Supremo: Ataque 12, crítico 30%, defensa 4, vida 50
  Bichito b1("Cucaracho Eduardus Supremo", 12, 0.3f, 4, 50);
  std::cout << "\n";
  // Hormiga Danielosa Samurai: Ataque 9, crítico 15%, defensa 6, vida 45
  Bichito b2("Hormiga Danielosa Samurai", 9, 0.15f, 6, 45);
  std::cout << "\n";

  // Mostramos estado inicial
  b1.MostrarEstado();
  std::cout << "\n";
  b2.MostrarEstado();
  std::cout << "\n";

  std::cout << "\n--- Combate ---\n";

  // Cada bichito ataca una vez al otro
  b1.Atacar(b2);
  std::cout << "\n";
  b2.Atacar(b1);
  std::cout << "\n";

  // Mostramos estado final
  std::cout << "\n--- Estado Final ---\n";
  b1.MostrarEstado();
  std::cout << "\n";
  b2.MostrarEstado();
  std::cout << "\n";

  return true;
}
