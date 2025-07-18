/**
** Author: Marco Pérez Padilla
** Email: alu0101469348@ull.edu.es
** Date of creation: 22/03/2025

** File types.cc: Implementation of the code to manage elemental types, including its reading from JSON file in data directory
**
** References:
**      Eigen documentation: https://eigen.tuxfamily.org/index.php?title=Main_Page 
**      json: https://github.com/nlohmann/json/releases

** History of revisions:
**      12/07/2025 - Creation of the code
**/

#include <iostream>
#include <string>
#include <fstream>
#include "libraries/json/single_include/nlohmann/json.hpp"

#include "exceptions/exceptions.h"
#include "types.h"

bool LoadElementMatrixes(const std::string& filename, Eigen::MatrixXd& weaknesses, Eigen::MatrixXd& strengths) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Critical error: File couldn't be opened " << filename << std::endl;
    return false;
  }

  try {
    nlohmann::json matrix_file;
    file >> matrix_file;

    if (!matrix_file.contains("weaknesses") || !matrix_file.contains("strengths")) {
      throw MissingFieldsException(filename);
    }

    auto weak_data = matrix_file["weaknesses"];
    auto strength_data = matrix_file["strengths"];

    const int weak_rows = weak_data.size();
    const int weak_cols = weak_data[0].size();
    const int strength_rows = strength_data.size();
    const int strength_cols = strength_data[0].size();

    if ((weak_rows != weak_cols) || (strength_rows != strength_cols) || (weak_rows != strength_rows)) {
      throw IncorrectDimensionsException();
    }

    weaknesses = Eigen::MatrixXd(weak_rows, weak_cols);
    strengths  = Eigen::MatrixXd(weak_rows, weak_cols);

    for (int i = 0; i < weak_rows; ++i) {
      for (int j = 0; j < weak_cols; ++j) {
        weaknesses(i, j) = weak_data[i][j];
        strengths(i, j)  = strength_data[i][j];
      }
    }

    return true;
  } catch (const Exceptions& error) {
    std::cerr << error.what() << std::endl;
    return false;
  }
}

