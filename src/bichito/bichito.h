#ifndef BICHITO_H_
#define BICHITO_H_

#include <iostream>
#include <string>
#include <vector>

class Bichito {
 public:
  Bichito(const std::string& nombre, int ataque, float critico,
          int defensa, int vida);

// Muestra todos los atributos actuales del bichito
  void MostrarEstado() const;
// Ataca a otro bichito (puede hacer crítico)
  void Atacar(Bichito& enemigo);
// Recibe daño (lo descuenta de su vida actual)
  void RecibirDaño(int cantidad);
// Aplica un efecto especial (ej: envenenado, escudo, etc.)
  void UsarObjeto(const std::string& efecto);
// Suma experiencia al bichito
  void GanarExperiencia(int exp);

 private:
  std::string nombre_;
  int ataque_;
  float critico_;
  int defensa_;
  int vida_;
  int vida_max_;
  int experiencia_;
  std::vector<std::string> efectos_especiales_;
};

#endif  // BICHITO_H_
