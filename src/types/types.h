/**
** Author: Marco Pérez Padilla
** Email: alu0101469348@ull.edu.es
** Date of creation: 22/03/2025

** File types.h: Declaration file of elemental types
**
** References:
**      Eigen documentation: https://eigen.tuxfamily.org/index.php?title=Main_Page 

** History of revisions:
**      12/07/2025 - Creation of the code
**/

#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include "libraries/Eigen/Eigen/Dense"

enum Type {
 Water,
 Fire,
 Earth, 
 Wind,
 Lightness,
 Darkness,
 Thunder
};

bool LoadElementMatrixes(const std::string& filename, Eigen::MatrixXd& weaknesses, Eigen::MatrixXd& strengths);

#endif