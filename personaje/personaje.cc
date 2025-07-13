#include "personaje.h"

void Personaje::CheckBichitos() {
  for (int i = 0; i < this->bichitos_.size(); ++i) {
    std::cout << bichitos_[i] << " ";
  }
}

// void Personaje::StatsBicho() <--- no se si lo va a hacer cris

void Personaje::CheckItems() {
  for (int i = 0; i < this->items_.size(); ++i) {
    std::cout << items_[i] << " ";
  }
}


// DEPENDENCIA DE CLASE COORDENADAS
bool Personaje::CheckCoords() {
  // asegurarse de que las coordenadas actuales son positivas por ejm
}

// DEPENDENCIA DE CLASE MOVIMIENTO
bool Personaje::CheckIteration() {
  // comprobar si en un radio de 
}