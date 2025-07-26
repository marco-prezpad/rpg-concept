#include "pants.h"

Pants::Pants(const std::string& name, int defense, const std::string& description, int required_level)
            : name_(name), defense_(defense), description_(description), required_level(required_level) {}


void Weapon::GiveState() const {
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Defense: " << defense_ << std::endl;
  std::cout << "Description: " << description_ << std::endl;
  std::cout << "Required Level" << required_level_ << std::endl;
}
            

std::vector<int> Weapon::Numbers() const {
  std::vector<int> numbers;
  numbers.emplace_back(damage_);
  numbers.emplace_back(defense_);
  return numbers;
}