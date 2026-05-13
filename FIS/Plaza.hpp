#if !defined(PLAZA_HPP)
#define PLAZA_HPP

#include <iostream>
#include <string>

#include "json.hpp"

using json = nlohmann::json;

enum class EstadoPlaza { DISPONIBLE, RESERVADA };

class Plaza {
 public:
  Plaza(const int&, const std::string&, const long int&, const std::string&,
        const std::string&, const double&);
  static std::string getClave();
  json serializar() const;
  static Plaza deserializar(const json&);
  void mostrarInfo() const;
  // Getters
  int getId() const;
  long int getPropietarioDNI() const;
  EstadoPlaza getEstado() const;
  bool isDisponible() const;
  // Cambiar estado
  void reservar();
  void liberar();
  const std::string& getDireccion() const;
  const std::string& getHorarioInicio() const;
  const std::string& getHorarioFin() const;
  double getPrecioHora() const;
  friend std::ostream& operator<<(std::ostream&, const Plaza&);

 private:
  int id_;
  std::string direccion_;
  long int propietario_dni_;
  EstadoPlaza estado_;
  std::string horario_inicio_;
  std::string horario_fin_;
  double precio_hora_;

  // Helpers para serializar el enum
  static std::string estadoToString(EstadoPlaza);
  static EstadoPlaza stringToEstado(const std::string&);
};

#endif