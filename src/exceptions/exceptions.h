/**
** Author: Marco Pérez Padilla
** Email: alu0101469348@ull.edu.es
** Date of creation: 22/03/2025

** File exceptions.h: Personalized exceptions classes to manage the code
**
** References:
**       

** History of revisions:
**      12/07/2025 - Creation of the code
**/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>


/**
 * @brief Class Exceptions that inheritages from std:exception, it has a protected member which is the message to be thrown if an error occurs
 */
class Exceptions : public std::exception {
 protected:
  std::string error_message_;
 public:
  explicit Exceptions (const std::string& error_message) : error_message_(error_message) {}
  const char* what() const throw() {return error_message_.c_str();}
};


/**
 * @brief Class MissingFields. Used when there is a missing field in a JSON file 
 */
class MissingFieldsException : public Exceptions {
 public:
  explicit MissingFieldsException(const std::string& json_file) : Exceptions("Error: There are missing fields in JSON file " + json_file) {}
};


/**
 * @brief Class IncorrectDimensions. Used when there two matrixes doesn't have the exact same size
 */
class IncorrectDimensionsException : public Exceptions {
 public:
  IncorrectDimensionsException() : Exceptions("Error: Dimensional error in matrixes, non coincident size") {}
};


#endif