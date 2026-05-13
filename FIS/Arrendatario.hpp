#if !defined(ARRENDATARIO_HPP)
#define ARRENDATARIO_HPP

#include "usuario.hpp"

using json = nlohmann::json;

class Arrendatario : public Usuario {
 public:
  Arrendatario(const std::string&, const long int&, const std::string&,
               const std::string&);
  static std::string getClave();
  json serializar() const override;
  void mostrarInfo() const override;
  static Arrendatario deserializar(const json&);
  void reservarPlaza(const std::string& fichero, const int& id) const;
  void liberarPlaza(const std::string& fichero, const int& id) const;
  friend std::ostream& operator<<(std::ostream&, const Arrendatario&);

 private:
  std::string matricula_;
};

#endif