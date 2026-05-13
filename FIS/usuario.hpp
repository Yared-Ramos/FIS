#if !defined(USUARIO_HPP)
#define USUARIO_HPP

#include <iostream>

#include "json.hpp"

using json = nlohmann::json;

using json = nlohmann::json;

class Usuario {
 public:
  Usuario(const std::string&, const long int&, const std::string&);
  virtual ~Usuario() = default;
  // Métodos que TODAS las clases hijas deben implementar
  virtual json serializar() const = 0;
  virtual void mostrarInfo() const = 0;
  const std::string& getNombre() const;
  const long int& getDNI() const;
  const std::string& getContraseña() const;
  friend std::ostream& operator<<(std::ostream&, const Usuario&);

 protected:
  std::string Nombre_;
  long int DNI_;
  std::string contraseña_;
};

#endif