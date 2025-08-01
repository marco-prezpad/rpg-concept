#ifndef ACCESORY_H
#define ACCESORY_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>

class Accesory {
 public:
  Accesory(const std::string& name, const std::string& description, int damage, int precision, int crtical_damage, int critician_probability, int defense, int required_level);

  //Give all the attributes of the accesory
  void GiveState() const;
  //Give required level
  int RequiredLevel() const { return required_level_; }
  //Give the statistics of the accesory to add them or subtract them to the character
  std::vector<int> Numbers() const;

 private:
  std::string name_;
  std::string description_;
  std::vector<std::pair<int, int>> statistics_;
  int required_level_;
};

#endif