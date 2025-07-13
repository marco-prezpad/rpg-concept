#include "bichito.h"

Bichito::Bichito(const std::string& nombre, int ataque, float critico,
                 int defensa, int vida)
    : nombre_(nombre), ataque_(ataque), critico_(critico), defensa_(defensa),
      vida_(vida), vida_max_(vida), experiencia_(0) {}

// Método que muestra todas las stats y efectos de bichito
void Bichito::MostrarEstado() const {
  std::cout << "Estado de " << nombre_ << ":\n"
            << ">>  Vida: " << vida_ << "/" << vida_max_ << "\n"
            << ">>  Ataque: " << ataque_ << "\n"
            << ">>  Crítico: " << critico_ * 100 << "%\n"
            << ">>  Defensa: " << defensa_ << "\n"
            << ">>  Experiencia: " << experiencia_ << "\n"
            << ">>  Efectos: ";
  if (efectos_especiales_.empty()) { 
    std::cout << "Ninguno\n";
  } else {
    for (size_t i = 0; i < efectos_especiales_.size(); ++i) {
      std::cout << efectos_especiales_[i] << " ";
    }
    std::cout << "\n";
  }
}

// Método que permite atacar a otro bichito
void Bichito::Atacar(Bichito& enemigo) {
  float chance = static_cast<float>(rand()) / RAND_MAX; // % de crítico
  int daño = ataque_;
  if (chance < critico_) {
    daño *= 2;
    std::cout << "¡" << nombre_ << " le acaba de mandar un GOLPE CRÍTICO, "
    << "chungo la peluca!\n";
  }

  int daño_real = std::max(0, daño - enemigo.defensa_);
  enemigo.RecibirDaño(daño_real);

  std::cout << nombre_ << " atacó a " << enemigo.nombre_
            << " causando " << daño_real << " de daño.\n";
}

// Método que permite recibir daño (disminuir la vida actual)
void Bichito::RecibirDaño(int cantidad) {
  vida_ -= cantidad;
  if (vida_ < 0) {
    vida_ = 0;
  }
  if (vida_ > 0) {
  std::cout << nombre_ << " recibió " << cantidad
            << " de daño. Vida restante: " << vida_ << "\n";
  } else {
  std::cout << nombre_ << " ha muerto después de recibir " << cantidad
            << " de daño.\n";
  }
}

// Método que permite usar efectos especiales
void Bichito::UsarObjeto(const std::string& efecto) {
  efectos_especiales_.push_back(efecto);
  std::cout << nombre_ << " usó un objeto con efecto: " << efecto << "\n";
}

// Método que permite ganar experiencia
void Bichito::GanarExperiencia(int exp) {
  experiencia_ += exp;
  std::cout << nombre_ << " ganó " << exp << " puntos de experiencia.\n";
}