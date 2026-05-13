#include "Arrendador.hpp"

#include "funciones.hpp"

Arrendador::Arrendador(const std::string& nombre, const long int& dni,
                       const std::string& contrasena)
    : Usuario(nombre, dni, contrasena) {}

std::string Arrendador::getClave() { return "Arrendador"; }

json Arrendador::serializar() const {
  return {{"Nombre", Nombre_}, {"DNI", DNI_}, {"contraseña", contraseña_}};
}

void Arrendador::mostrarInfo() const {
  std::cout << "Arrendador | Nombre: " << Nombre_ << " | DNI: " << DNI_ << "\n";
}

Arrendador Arrendador::deserializar(const json& j) {
  return Arrendador(j["Nombre"], j["DNI"], j["contraseña"]);
}

void Arrendador::agregarPlaza(const std::string& fichero,
                              const std::string& direccion,
                              const std::string& horario_inicio,
                              const std::string& horario_fin,
                              const double& precio_hora) const {
  auto plazas = cargar<Plaza>(fichero);

  // Generar id automático
  int nuevoId = plazas.empty() ? 1 : plazas.back().getId() + 1;

  plazas.emplace_back(nuevoId, direccion, DNI_, horario_inicio, horario_fin,
                      precio_hora);
  guardar<Plaza>(fichero, plazas);

  std::cout << "Plaza añadida correctamente con id " << nuevoId << "\n";
}

void Arrendador::mostrarMisPlazas(const std::string& fichero) const {
  auto plazas = cargar<Plaza>(fichero);
  std::cout << "=== Mis plazas ===\n";
  for (const auto& p : plazas) {
    if (p.getPropietarioDNI() == DNI_) p.mostrarInfo();
  }
}

std::ostream& operator<<(std::ostream& os, const Arrendador& a) {
  a.mostrarInfo();
  return os;
}