#include <iomanip>

#include "AdministradorFinca.hpp"
#include "Arrendador.hpp"
#include "Arrendatario.hpp"
#include "funciones.hpp"

AdministradorFinca::AdministradorFinca(const std::string& nombre,
                                       const long int& dni,
                                       const std::string& contrasena)
    : Usuario(nombre, dni, contrasena) {}

std::string AdministradorFinca::getClave() { return "AdministradorFinca"; }

json AdministradorFinca::serializar() const {
  return {{"Nombre", Nombre_}, {"DNI", DNI_}, {"contraseña", contraseña_}};
}

void AdministradorFinca::mostrarInfo() const {
  std::cout << "Administrador de Finca | Nombre: " << Nombre_
            << " | DNI: " << DNI_ << "\n";
}

AdministradorFinca AdministradorFinca::deserializar(const json& j) {
  return AdministradorFinca(j["Nombre"], j["DNI"], j["contraseña"]);
}

void AdministradorFinca::mostrarTodasLasPlazas(
    const std::string& ficheroPlazas) const {
  auto plazas = cargar<Plaza>(ficheroPlazas);

  if (plazas.empty()) {
    std::cout << "No hay plazas registradas.\n";
    return;
  }

  std::cout << "\n╔══════════════════════════════════════════════════════╗\n";
  std::cout << "║              ESTADO DE LAS PLAZAS                   ║\n";
  std::cout << "╚══════════════════════════════════════════════════════╝\n\n";

  int disponibles = 0;
  int reservadas = 0;

  for (const auto& p : plazas) {
    std::string estado = p.isDisponible() ? "✅ DISPONIBLE" : "🔴 RESERVADA ";
    std::cout << "  [" << std::setw(3) << p.getId() << "] " << std::left
              << std::setw(30) << p.getDireccion() << " | " << estado << " | "
              << p.getHorarioInicio() << " - " << p.getHorarioFin() << " | "
              << p.getPrecioHora() << "€/h\n";

    p.isDisponible() ? disponibles++ : reservadas++;
  }

  std::cout << "\n  Total: " << plazas.size()
            << " | Disponibles: " << disponibles
            << " | Reservadas: " << reservadas << "\n\n";
}

void AdministradorFinca::mostrarUsuarios(
    const std::string& ficheroUsuarios) const {
  auto arrendatarios = cargar<Arrendatario>(ficheroUsuarios);
  auto arrendadores = cargar<Arrendador>(ficheroUsuarios);

  std::cout << "\n╔══════════════════════════════════════════════════════╗\n";
  std::cout << "║              USUARIOS DE LA PLATAFORMA               ║\n";
  std::cout << "╚══════════════════════════════════════════════════════╝\n\n";

  std::cout << "  --- Arrendatarios ---\n";
  if (arrendatarios.empty()) {
    std::cout << "  Sin arrendatarios registrados.\n";
  } else {
    for (const auto& a : arrendatarios)
      std::cout << "  Nombre: " << std::left << std::setw(20) << a.getNombre()
                << " | DNI: " << a.getDNI() << "\n";
  }

  std::cout << "\n  --- Arrendadores ---\n";
  if (arrendadores.empty()) {
    std::cout << "  Sin arrendadores registrados.\n";
  } else {
    for (const auto& a : arrendadores)
      std::cout << "  Nombre: " << std::left << std::setw(20) << a.getNombre()
                << " | DNI: " << a.getDNI() << "\n";
  }

  std::cout << "\n";
}

std::ostream& operator<<(std::ostream& os, const AdministradorFinca& a) {
  a.mostrarInfo();
  return os;
}