#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <vector>

#include "../movimiento/movimiento.h"
#include "../coordenadas/coordenadas.h"
#include "../bichito/bichito.h"

#include "../equipment/accesory.h
#include "../equipment/weapon.h"

#include "../equipment/helmet.h
#include "../equipment/chestplate.h
#include "../equipment/pants.h
#include "../equipment/boots.h


class Personaje {
 public:
  const std::string GetName() const { return this->name_; }
  const double GetAttack()  const { return this->attack_; }
  const double GetDefense() const { return this->defense_; }
  const double GetCritChance() const { return this->crit_chance_; }
  const double GetLife() const { return this->life_; }
  const double GetSpeed() const { return this->speed_; }
  const double GetCurrentExp() const { return this->exp_; }


  void SetName(const std::string name) { this->name_ = name; }
  void SetAttack(double attack) { this->attack_ = attack; }
  void SetDefense(double defense) { this->defense_ = defense; }
  void SetCritChance(double crit) { this->crit_chance_ = crit; }
  void SetLife(double life) { this->life_ = life; }
  void SetSpeed(double speed) { this->speed_ = speed; }
  void SetExp(double exp) { this->exp_ = exp; }
 



  // void CheckMenu() <-- meter aqui los demas checks (idea)
  void CheckItems();
  void CheckBichitos();
  bool CheckCoords();

  bool CheckIteration();
  void MoverMenu(char tecla, int i);
  
  bool HasHelmet();
  bool HasChestplate();
  bool HasPants();
  bool HasBoots();
  void CheckArmor();


 private:
 // atributos generales
// usar el struct de atributos generales (arreglar)
  std::string name_;
  double attack_;
  double defense_;
  double personal_crit_chance_;
  double total_crit_chance_; // critico general arma mas personaje
  double life_;
  double speed_;
  double exp_;

  // atributos especiales
  std::string type_class_; // podria ser un enum y/o otra clase
  Accesory accesory_;
  Helmet current_helmet_;
  Chestplate current_chestplate_;
  Pants current_pants_;
  Boots current_boots_;
  // estoy pensando en que puede usar dos armas (una por mano)
  Weapon weapon1_;
  Weapon weapon2_;

  double current_defense_; // suma de lo que tiene de cada pieza (llamara a funciones que verifiquen si tiene cierta pieza y se sumara a sus estadisticas)
  std::string afinity_; 
  bool right_hand_;
  bool left_hand_;


  // gestion de movimiento
  Movimiento mov_; // movimiento y coordenadas

  // iteractuables (almacenes) 
  std::vector<Bichito> bichitos_; 
  std::vector<std::string> items_; // idea: crear una clase que tenga todas las clases para poder meter cualquier cosa aca

};

#endif // PERSONAJE_H