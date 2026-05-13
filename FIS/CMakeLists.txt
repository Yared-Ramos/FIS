cmake_minimum_required(VERSION 3.10)
project(Practica5)

set(CMAKE_CXX_STANDARD 17)

add_executable(datos
  main.cpp
  usuario.cpp
  arrendatario.cpp
  arrendador.cpp
  admin.cpp
  plaza.cpp
)