#include "weapon.h"

Weapon::Weapon(const std::string &name, int damage, int precision, const std::string &description,
               int crtical_damage, int critician_probability, int required_level)
              : name_(name), damage_(damage). precision_(precision), description_(description),
                critical_damage_(crtical_damage), critician_probability_(critician_probability), required_level_(required_level) {}

void Weapon::GiveState() const {
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Damage: " << damage_ << std::endl;
  std::cout << "Precision: " << precision_ << std::endl;
  std::cout << "Description: " << description_ << std::endl;
  std::cout << "Critical Damage: " << critical_damage_ << std::endl;
  std::cout << "Critician Probability" << critician_probability_ << std::endl;
  std::cout << "Required Level" << required_level_ << std::endl;
}

std::vector<int> Weapon::Numbers() const {
  std::vector<int> numbers;
  numbers.emplace_back(damage_);
  numbers.emplace_back(precision_);
  numbers.emplace_back(critical_damage_);
  numbers.emplace_back(critician_probability_);
  return numbers;
}
