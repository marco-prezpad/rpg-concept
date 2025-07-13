#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <vector>

#include "../movimiento/movimiento.h"
#include "../coordenadas/coordenadas.h"
#include "../bichito/bichito.h"

class Personaje {
 public:
  const std::string GetName() const { return this->name_; }
  void SetName(const std::string name) { name_ = name; }
  // void CheckMenu() <-- meter aqui los demas checks (idea)
  void CheckItems();
  void CheckBichitos();
  bool CheckCoords();
  bool CheckIteration();


 private:
  std::string name_;
  // Movimiento mov_; 
  // Coordenadas coords_;
  std::vector<Bichito> bichitos_; 
  std::vector<std::string> items_;

};

#endif // PERSONAJE_H