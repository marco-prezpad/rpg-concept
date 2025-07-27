#ifndef HELMET_H
#define HELMET_H

#include <string>
#include <vector>
#include <iostream>

class Helmet {
 public:
  Helmet(const std::string& name, int defense, const std::string& description, int required_level);

  //Give all the attributes of the helmet
  void GiveState() const;
  //Give required level
  int RequiredLevel() const { return required_level_; }
  //Give the statistics of defense to add them or subtract them to the character
  int Defense() const { return defense_; }

 private:
  std::string name_;
  int defense_;
  std::string description_;
  int required_level_;
};

#endif