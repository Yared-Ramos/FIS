# FIS - Framework de Inyección de Servicios

Este proyecto implementa un sistema modular basado en programación orientada a objetos (OOP), utilizando clases, herencia y polimorfismo para estructurar distintos componentes de forma escalable y mantenible.

El objetivo principal es demostrar una arquitectura limpia, separando responsabilidades en clases base e implementaciones concretas.

---

# 📁 Estructura del proyecto

| Carpeta / Archivo | Descripción |
|------------------|------------|
| `FIS/` | Núcleo principal del proyecto |
| `core/` | Clases base abstractas e interfaces principales |
| `models/` | Clases hijas con implementaciones concretas |
| `services/` | Lógica de negocio del sistema |
| `utils/` | Funciones auxiliares y herramientas generales |
| `include/` | Cabeceras del proyecto (.h / .hpp) |
| `main.cpp` | Punto de entrada del programa |

---

# 🧠 Arquitectura del sistema

El proyecto sigue un enfoque de **Programación Orientada a Objetos (OOP)** basado en:

- Herencia
- Polimorfismo
- Encapsulación
- Abstracción

---

## 🔷 Clase base (Abstracta)

Define la estructura común que deben seguir todas las clases derivadas.

- Contiene métodos virtuales puros
- Actúa como interfaz general
- No puede instanciarse directamente

```cpp
class Base {
public:
    virtual void execute() = 0;
    virtual ~Base() {}
};
