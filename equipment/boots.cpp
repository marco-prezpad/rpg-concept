#include "boots.h"

Boots::Boots(const std::string& name, int defense, const std::string& description, int required_level)
            : name_(name), defense_(defense), description_(description), required_level(required_level) {}


// Temporal
void Boots::GiveState() const {
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Defense: " << defense_ << std::endl;
  std::cout << "Description: " << description_ << std::endl;
  std::cout << "Required Level" << required_level_ << std::endl;
}
            