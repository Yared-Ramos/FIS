#include "Arrendatario.hpp"

#include "Plaza.hpp"
#include "funciones.hpp"

Arrendatario::Arrendatario(const std::string& nombre, const long int& dni,
                           const std::string& contrasena,
                           const std::string& matricula)
    : Usuario(nombre, dni, contrasena), matricula_(matricula) {}

std::string Arrendatario::getClave() { return "Arrendatario"; }

json Arrendatario::serializar() const {
  json j = {{"Nombre", Nombre_},
            {"DNI", DNI_},
            {"Contraseña", contraseña_},
            {"Matricula", matricula_}};
  return j;
}

void Arrendatario::mostrarInfo() const {
  std::cout << "Nombre: " << Nombre_ << " | DNI: " << DNI_
            << " | Vehículo: " << matricula_ << "\n";
}

Arrendatario Arrendatario::deserializar(const json& j) {
  return Arrendatario(j["Nombre"], j["DNI"], j["Contraseña"], j["Matricula"]);
}

void Arrendatario::reservarPlaza(const std::string& fichero,
                                 const int& id) const {
  auto plazas = cargar<Plaza>(fichero);
  for (auto& p : plazas) {
    if (p.getId() == id) {
      if (!p.isDisponible()) {
        std::cout << "La plaza ya está reservada.\n";
        return;
      }
      p.reservar();
      guardar<Plaza>(fichero, plazas);
      std::cout << "Plaza " << id << " reservada correctamente.\n";
      return;
    }
  }
  std::cout << "No se encontró la plaza con id " << id << "\n";
}

void Arrendatario::liberarPlaza(const std::string& fichero,
                                const int& id) const {
  auto plazas = cargar<Plaza>(fichero);
  for (auto& p : plazas) {
    if (p.getId() == id) {
      p.liberar();
      guardar<Plaza>(fichero, plazas);
      std::cout << "Plaza " << id << " liberada correctamente.\n";
      return;
    }
  }
  std::cout << "No se encontró la plaza con id " << id << "\n";
}

std::ostream& operator<<(std::ostream& os, const Arrendatario& a) {
  a.mostrarInfo();
  return os;
}