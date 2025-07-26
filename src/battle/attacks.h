/**
** Author: Marco Pérez Padilla
** Email: alu0101469348@ull.edu.es
** Date of creation: 26/07/2025

** File attacks.h: uses polimorfism to declare different attacks
**
** References:
**      

** History of revisions:
**      26/07/2025 - Creation of the code
**/

#ifndef ATTACKS_H
#define ATTACKS_H

#include <cstdlib> //rand(), srand()
#include <vector>
#include <variant>
#include "types/types.h"
#include "bichito/bichito.h"

/**
 * @brief Struct with common attributes for both Bichito and Personaje, it can be included as private attribute and create getters for each attribute
 */
struct CommonAttributes {
  std::vector<Type> types_;
  double attack_;
  double defense_;
  double speed_;
  double critic_prob_;
  double hp_;
  double xp_;
  //std::vector<Effect> effects;
  //std::vector<State> states;

  // Next lines must be on the public part of Personaje and Bichito classes
  // std::vector<Type> getTypes() const { return types; }
  // double getAttackStat() const { return attack; }
  // double getDefenseStat() const { return defense; }
  // double getSpeed() const { return speed; }
  // double getCriticProbability() const { return critic_prob; }
  // double getHP() const { return hp; }
  // double getXP() const { return xp; }
  // const std::vector<Effect>& GetEffects() const { return effects; }
  // const std::vector<State>& GetStates() const { return states; }
};


/**
 * @brief Virtual class Attack, defines the methods to calculate the damage an attack will do, depending on Entity's attributes
 */
class Attack {
 protected:
  double base_damage_;
  std::vector<Type> types_;

 public:
  Attack(double base_damage, std::vector<Type> types) : base_damage_(base_damage), types_(types) {}
  virtual std::string attack_name() const = 0;
  virtual double Attack::CalculateDamage(std::variant<Bichito>& attacking_entity, std::variant<Bichito>& target_entity) const; // Add Personaje to variant
  virtual ~Attack() = default;
};


/**
 * @brief Class Hydrobomb that inheritages from Attack, specifies an attack with its name, base damage, and Types
 */
class Hydrobomb: public Attack {
 public:
  Hydrobomb() : Attack(50, {Type::Water, Type::Wind}) {}
  std::string attack_name() const override {
    return "Hydrobomb";
  }
};


#endif