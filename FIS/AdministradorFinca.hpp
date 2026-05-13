#if !defined(ADMIN_HPP)
#define ADMIN_HPP

#include "usuario.hpp"
#include "Plaza.hpp"

class AdministradorFinca : public Usuario {
 public:
  AdministradorFinca(const std::string&, const long int&, const std::string&);
  static std::string getClave();
  json serializar() const override;
  void mostrarInfo() const override;
  static AdministradorFinca deserializar(const json&);
  // Métodos de consulta
  void mostrarTodasLasPlazas(const std::string& ficheroPlazas) const;
  void mostrarUsuarios(const std::string& ficheroUsuarios) const;
  friend std::ostream& operator<<(std::ostream&, const AdministradorFinca&);
};

#endif