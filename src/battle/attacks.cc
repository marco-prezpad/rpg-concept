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

#include "attacks.h"

extern Eigen::MatrixXd weaknesses;
extern Eigen::MatrixXd strengths;


/**
 * @brief Auxiliar function to get the common stats of either a Bichito or a Personaje
 * @param Variant: Bichito or Personaje
 * @return struct with the common stats of the entity
 */
CommonAttributes& getEntityStats(std::variant<Bichito>& entity) { // Add Personaje to variant
  return std::visit([](auto& ent) -> CommonAttributes& {
    return ent.getCommonStats();                                        // Personaje and Bichito must have getCommonStats, returning the struct
  }, entity);
}

/**
 * @brief Function that calculates the total damage done by an entity to another one. Virtual method of Attack class. It might be overwritten by 
 *        child classes, for example if we differentiate physical and magical attacks. If not overwritten, this will be the general function
 * @param Variant: Attacking Bichito or Personaje
 * @param Variant: Attacked Bichito or Personaje
 * @return double, result of the damage
 */
double Attack::CalculateDamage(std::variant<Bichito>& attacking_entity, std::variant<Bichito>& target_entity) const { 
  CommonAttributes attacking_entity_attributes = getEntityStats(attacking_entity);
  CommonAttributes attacked_entity_attributes = getEntityStats(target_entity);
  double effectiveness {0.0};
  for (Type atk_type : attacking_entity_attributes.types_) {
    for (Type def_type :attacked_entity_attributes.types_) {
      double strength = strengths(atk_type, def_type);
      double weakness = weaknesses(def_type, atk_type);       
      double partial_effectiveness = strength - weakness; 

      effectiveness *= partial_effectiveness; 
    }
  }
  return 0.0;
}