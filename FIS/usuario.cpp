#include "usuario.hpp"

Usuario::Usuario(const std::string& nombre, const long int& dni,
                 const std::string& contrasena)
    : Nombre_(nombre), DNI_(dni), contraseña_(contrasena) {}

const std::string& Usuario::getNombre() const { return Nombre_; }
const long int& Usuario::getDNI() const { return DNI_; }
const std::string& Usuario::getContraseña() const { return contraseña_; }

std::ostream& operator<<(std::ostream& os, const Usuario& u) {
  u.mostrarInfo();  // Delega a la hija
  return os;
}