#include <fstream>
#include <iostream>
#include <vector>

#include "json.hpp"

using json = nlohmann::json;

// Función para cargar a los usuarios desde el .json
template <class Key>
std::vector<Key> cargar(const std::string& ruta) {
  std::vector<Key> elementos;
  std::ifstream archivo(ruta);
  if (!archivo.is_open()) {
    return elementos;
  }
  archivo.seekg(0, std::ios::end);
  if (archivo.tellg() == 0) {
    return elementos;
  }
  archivo.seekg(0, std::ios::beg);
  json datos;
  archivo >> datos;
  std::string nombreClave = Key::getClave();  // ← usa la clave de la clase
  if (!datos.contains(nombreClave)) {
    return elementos;
  }
  for (auto& j : datos[nombreClave]) {
    elementos.push_back(Key::deserializar(j));
  }
  return elementos;
}

// Guardar usuarios en el archivo
template <class Key>
void guardar(const std::string& ruta, const std::vector<Key>& elementos) {
  json datos;
  // Leer lo que ya hay en el archivo
  std::ifstream entrada(ruta);
  if (entrada.is_open()) {
    entrada.seekg(0, std::ios::end);
    if (entrada.tellg() > 0) {
      entrada.seekg(0, std::ios::beg);
      entrada >> datos;
    }
  }
  // Actualizar solo la clave de esta clase
  std::string clave = Key::getClave();
  datos[clave] = json::array();
  for (const auto& e : elementos) {
    datos[clave].push_back(e.serializar());
  }
  // Reescribir el archivo completo
  std::ofstream salida(ruta);
  salida << datos.dump(4);
}