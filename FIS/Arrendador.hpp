#if !defined(ARRENDADOR_HPP)
#define ARRENDADOR_HPP

#include <vector>

#include "Plaza.hpp"
#include "usuario.hpp"

class Arrendador : public Usuario {
 public:
  Arrendador(const std::string&, const long int&, const std::string&);
  static std::string getClave();
  json serializar() const override;
  void mostrarInfo() const override;
  static Arrendador deserializar(const json&);
  // Gestión de plazas
  void agregarPlaza(const std::string& fichero, const std::string& direccion,
                    const std::string& horario_inicio,
                    const std::string& horario_fin,
                    const double& precio_hora) const;
  void mostrarMisPlazas(const std::string& fichero) const;
  friend std::ostream& operator<<(std::ostream&, const Arrendador&);
};

#endif