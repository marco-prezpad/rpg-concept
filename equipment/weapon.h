#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <vector>
#include <iostream>

class Weapon {
 public:
  Weapon(const std::string& name, int damage, int precision, const std::string& description, int crtical_damage, int critician_probability, int required_level);

  //Give all the attributes of the weapon
  void GiveState() const;
  //Give required level
  int RequiredLevel() const { return required_level_; }
  //Give the statistics of the weapon to add them or subtract them to the character
  std::vector<int> Numbers() const;

 private:
  std::string name_;
  int damage_;
  int precision_;
  std::string description_;
  int critical_damage_;
  int critician_probability_;
  int required_level_;
};

#endif
