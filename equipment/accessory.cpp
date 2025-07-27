#include "accesory.h"

Accesory::Accesory(const std::string& name, const std::string& description, int damage, int precision, int crtical_damage,
                   int critician_probability, int defense, int required_level) {
  name_(name);
  description_(description);
  required_level_(required_level);
  statistics_.emplace_back(std::make_pair(1, damage));
  statistics_.emplace_back(std::make_pair(2, precision));
  statistics_.emplace_back(std::make_pair(3, crtical_damage));
  statistics_.emplace_back(std::make_pair(4, critician_probability));
  statistics_.emplace_back(std::make_pair(5, defense));
}


void Accesory::GiveState() const {
  std::cout << "Name: " << name_ << std::endl;
  std::cout << "Description: " << description_ << std::endl;
  std::cout << "Required Level" << required_level_ << std::endl;
  for (const auto& aux : statistics_) {
    switch (aux.first) {
      case 1:
        if (aux.second != 0) {
          std::cout << "Damage: +" << aux.second << std::endl;
        }
        break;
      case 2:
        if (aux.second != 0) {
          std::cout << "Precision: +" << aux.second << std::endl;
        }
        break;
      case 3:
        if (aux.second != 0) {
          std::cout << "Critical Damage: +" << aux.second << std::endl;
        }
        break;
      case 4:
        if (aux.second != 0) {
          std::cout << "Critician Probability: +" << aux.second << "%" << std::endl;
        }
        break;
      case 5:
        if (aux.second != 0) {
          std::cout << "Defense: +" << aux.second << std::endl;
        }
        break;
      default:
        break;
    }
  }
}

std::vector<int> Accesory::Numbers() const {
  std::vector<int> numbers;
  numbers.emplace_back(damage_);
  numbers.emplace_back(precision_);
  numbers.emplace_back(critical_damage_);
  numbers.emplace_back(critician_probability_);
  numbers.emplace_back(defense_);
  return numbers;
}
