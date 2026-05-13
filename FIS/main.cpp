#include <iostream>
#include <limits>
#include <string>

#include "AdministradorFinca.hpp"
#include "Arrendador.hpp"
#include "Arrendatario.hpp"
#include "funciones.hpp"

const std::string FICHERO_USUARIOS = "datos.json";
const std::string FICHERO_PLAZAS = "plazas.json";

void pausar() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "\n  Pulsa Enter para continuar...";
  std::cin.get();
}

// Devuelve: 0=no encontrado, 1=Arrendatario, 2=Arrendador, 3=AdminFinca
int buscarUsuario(long int dni, const std::string& pass) {
  for (const auto& a : cargar<Arrendatario>(FICHERO_USUARIOS))
    if (a.getDNI() == dni && a.getContraseña() == pass) return 1;
  for (const auto& a : cargar<Arrendador>(FICHERO_USUARIOS))
    if (a.getDNI() == dni && a.getContraseña() == pass) return 2;
  for (const auto& a : cargar<AdministradorFinca>(FICHERO_USUARIOS))
    if (a.getDNI() == dni && a.getContraseña() == pass) return 3;
  return 0;
}

void menuArrendatario(long int dni) {
  auto lista = cargar<Arrendatario>(FICHERO_USUARIOS);
  Arrendatario* u = nullptr;
  for (auto& a : lista)
    if (a.getDNI() == dni) {
      u = &a;
      break;
    }
  if (!u) return;

  int op;
  do {
    std::cout << "\n=== Arrendatario: " << u->getNombre() << " ===\n"
              << "1. Ver plazas disponibles\n2. Reservar plaza\n3. Liberar "
                 "plaza\n0. Salir\nOpción: ";
    std::cin >> op;
    if (op == 1) {
      bool hay = false;
      for (const auto& p : cargar<Plaza>(FICHERO_PLAZAS))
        if (p.isDisponible()) {
          p.mostrarInfo();
          hay = true;
        }
      if (!hay) std::cout << "No hay plazas disponibles.\n";
    } else if (op == 2) {
      int id;
      std::cout << "ID de la plaza: ";
      std::cin >> id;
      u->reservarPlaza(FICHERO_PLAZAS, id);
    } else if (op == 3) {
      int id;
      std::cout << "ID de la plaza: ";
      std::cin >> id;
      u->liberarPlaza(FICHERO_PLAZAS, id);
    }
  } while (op != 0);
}

void menuArrendador(long int dni) {
  auto lista = cargar<Arrendador>(FICHERO_USUARIOS);
  Arrendador* u = nullptr;
  for (auto& a : lista)
    if (a.getDNI() == dni) {
      u = &a;
      break;
    }
  if (!u) return;

  int op;
  do {
    std::cout << "\n=== Arrendador: " << u->getNombre() << " ===\n"
              << "1. Ver mis plazas\n2. Añadir plaza\n0. Salir\nOpción: ";
    std::cin >> op;
    if (op == 1) {
      u->mostrarMisPlazas(FICHERO_PLAZAS);
    } else if (op == 2) {
      std::string dir, hi, hf;
      double precio;
      std::cin.ignore();
      std::cout << "Dirección: ";
      std::getline(std::cin, dir);
      std::cout << "Inicio (HH:MM): ";
      std::cin >> hi;
      std::cout << "Fin    (HH:MM): ";
      std::cin >> hf;
      std::cout << "Precio €/h: ";
      std::cin >> precio;
      u->agregarPlaza(FICHERO_PLAZAS, dir, hi, hf, precio);
    }
  } while (op != 0);
}

void menuAdmin(long int dni) {
  auto lista = cargar<AdministradorFinca>(FICHERO_USUARIOS);
  AdministradorFinca* u = nullptr;
  for (auto& a : lista)
    if (a.getDNI() == dni) {
      u = &a;
      break;
    }
  if (!u) return;

  int op;
  do {
    std::cout << "\n=== Admin: " << u->getNombre() << " ===\n"
              << "1. Ver todas las plazas\n2. Ver usuarios\n0. Salir\nOpción: ";
    std::cin >> op;
    if (op == 1)
      u->mostrarTodasLasPlazas(FICHERO_PLAZAS);
    else if (op == 2)
      u->mostrarUsuarios(FICHERO_USUARIOS);
  } while (op != 0);
}

void crearCuenta() {
  std::cout << "\n1. Arrendatario\n2. Arrendador\n3. Admin Finca\nTipo: ";
  int tipo;
  std::cin >> tipo;

  std::string nombre, pass, matricula;
  long int dni;
  std::cin.ignore();
  std::cout << "Nombre: ";
  std::getline(std::cin, nombre);
  std::cout << "DNI: ";
  std::cin >> dni;
  std::cout << "Contraseña: ";
  std::cin >> pass;

  if (tipo == 1) {
    std::cout << "Matrícula: ";
    std::cin >> matricula;
    auto v = cargar<Arrendatario>(FICHERO_USUARIOS);
    v.emplace_back(nombre, dni, pass, matricula);
    guardar<Arrendatario>(FICHERO_USUARIOS, v);
  } else if (tipo == 2) {
    auto v = cargar<Arrendador>(FICHERO_USUARIOS);
    v.emplace_back(nombre, dni, pass);
    guardar<Arrendador>(FICHERO_USUARIOS, v);
  } else if (tipo == 3) {
    auto v = cargar<AdministradorFinca>(FICHERO_USUARIOS);
    v.emplace_back(nombre, dni, pass);
    guardar<AdministradorFinca>(FICHERO_USUARIOS, v);
  }
  std::cout << "Cuenta creada.\n";
}

int main() {
  int op;
  do {
    std::cout << "\n=== ParkShare ===\n1. Iniciar sesión\n2. Crear cuenta\n0. "
                 "Salir\nOpción: ";
    std::cin >> op;
    if (op == 1) {
      long int dni;
      std::string pass;
      std::cout << "DNI: ";
      std::cin >> dni;
      std::cout << "Contraseña: ";
      std::cin >> pass;
      int tipo = buscarUsuario(dni, pass);
      if (tipo == 1)
        menuArrendatario(dni);
      else if (tipo == 2)
        menuArrendador(dni);
      else if (tipo == 3)
        menuAdmin(dni);
      else
        std::cout << "DNI o contraseña incorrectos.\n";
    } else if (op == 2) {
      crearCuenta();
    }
  } while (op != 0);
  return 0;
}