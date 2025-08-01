#include "personaje.h"

#define one_tile 1

void Personaje::CheckMenu() {
  while (true) {
    std::cin >> tecla;
    for (int i = 0; i >= 5; MoverMenu(char tecla))
      if (tecla == 'x') {
      // aqui se pondria una funcion que llame a cada opcion del menu
        if (i == 0) std::cout << "Personaje";
        if (i == 1) std::cout << "Bichitos";
        if (i == 2) std::cout << "Items";
        if (i == 3) std::cout << "Equipment";
        if (i == 4) std::cout << "Settings";
      }
      if (tecla == 'z') break; // me gustaria hacer que fuera escape
  }    
}

void Personaje::MoverMenu(char tecla, int i) {
  assert(tecla == 'w' || tecla == 's' || tecla == 'x');
  switch (tecla) {
    case 'w': i++; break;
    case 's': assert(i >= 0) i--; break; // para evitar acceder a indices negativos
  }
}

void Personaje::CheckItems() {
  while (true) {
    std::cin >> tecla;
    for (int i = 0; i >= this->items_.size(); MoverMenu(char tecla))
      if (tecla == 'z') break; // me gustaria hacer que fuera escape
  }
}

void Personaje::CheckCoords() {
  assert(this->mov_.GetX() >= 0 && this->mov_.GetY() >= 0);
  std::cout << this->mov_.GetX() << this->mov_.GetY() << std::endl;
}

bool Personaje::CheckIteration(const Personaje& other) {
  if (this->mov_.GetX() + one_tile == other.mov_.GetX() || this->mov_.GetX() - one_tile == other.mov_.GetX()) {
    return true;
  }
  if (this->mov_.GetY() + one_tile == other.mov_.GetY() || this->mov_.GetY() - one_tile == other.mov_.getY()) {
    return true;
  }
  return false;
}

  // necesitamos clases para cada objeto? o alguna idea para darle atributos a cada cosa sin una clase
  bool HasHelmet() {
    if (this->current_helmet_.equipped) { // equipped es un booleano 1 si esta equipado 0 si no
      return true;
    }
    return false;
  }

  bool HasChestplate() {
   if (this->current_chestplate_.equipped) { // equipped es un booleano 1 si esta equipado 0 si no
      return true;
    }
    return false;
  }
  bool HasPants() {
     if (this->current_pants_.equipped) { // equipped es un booleano 1 si esta equipado 0 si no
      return true;
    }
    return false;
  }

  bool HasBoots() {
     if (this->current_boots_.equipped) { // equipped es un booleano 1 si esta equipado 0 si no
      return true;
    }
    return false;
  }

  void CheckArmor() {
    // sumar los atributos
    if (HasHelmet) this->current_defense_ + this->current_helmet_.defense_;
    if (HasChestplate) this->current_defense_ + this->current_chestplate_.defense_;
    if (HasLeggins) this->current_defense_ + this->current_pants_.defense_;
    if (HasBoots) this->current_defense_ + this->current_boots_.defense_;
  }