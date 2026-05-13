#include "Plaza.hpp"

Plaza::Plaza(const int& id, const std::string& direccion,
             const long int& propietario_dni, const std::string& horario_inicio,
             const std::string& horario_fin, const double& precio_hora)
    : id_(id),
      direccion_(direccion),
      propietario_dni_(propietario_dni),
      estado_(EstadoPlaza::DISPONIBLE),
      horario_inicio_(horario_inicio),
      horario_fin_(horario_fin),
      precio_hora_(precio_hora) {}

std::string Plaza::getClave() { return "Plaza"; }

std::string Plaza::estadoToString(EstadoPlaza e) {
  return e == EstadoPlaza::DISPONIBLE ? "disponible" : "reservada";
}

EstadoPlaza Plaza::stringToEstado(const std::string& s) {
  return s == "disponible" ? EstadoPlaza::DISPONIBLE : EstadoPlaza::RESERVADA;
}

json Plaza::serializar() const {
  return {{"id", id_},
          {"direccion", direccion_},
          {"propietario_dni", propietario_dni_},
          {"estado", estadoToString(estado_)},
          {"horario_inicio", horario_inicio_},
          {"horario_fin", horario_fin_},
          {"precio_hora", precio_hora_}};
}

Plaza Plaza::deserializar(const json& j) {
  Plaza p(j["id"], j["direccion"], j["propietario_dni"], j["horario_inicio"],
          j["horario_fin"], j["precio_hora"]);
  p.estado_ = stringToEstado(j["estado"]);
  return p;
}

void Plaza::mostrarInfo() const {
  std::cout << "[" << id_ << "] " << direccion_ << " | " << horario_inicio_
            << " - " << horario_fin_ << " | " << precio_hora_ << "€/h"
            << " | Estado: " << estadoToString(estado_) << "\n";
}

int Plaza::getId() const { return id_; }
long int Plaza::getPropietarioDNI() const { return propietario_dni_; }
EstadoPlaza Plaza::getEstado() const { return estado_; }
bool Plaza::isDisponible() const { return estado_ == EstadoPlaza::DISPONIBLE; }

void Plaza::reservar() { estado_ = EstadoPlaza::RESERVADA; }

void Plaza::liberar() { estado_ = EstadoPlaza::DISPONIBLE; }

const std::string& Plaza::getDireccion() const { return direccion_; }

const std::string& Plaza::getHorarioInicio() const { return horario_inicio_; }

const std::string& Plaza::getHorarioFin() const { return horario_fin_; }

double Plaza::getPrecioHora() const { return precio_hora_; }

std::ostream& operator<<(std::ostream& os, const Plaza& p) {
  p.mostrarInfo();
  return os;
}