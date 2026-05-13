# FIS - Fundamentos de Ingeniería del Software

Proyecto desarrollado siguiendo principios de **Programación Orientada a Objetos (OOP)**, utilizando herencia, encapsulación, abstracción y polimorfismo para construir una arquitectura modular, escalable y mantenible.

El objetivo principal del proyecto es separar correctamente las responsabilidades del sistema mediante clases base abstractas e implementaciones concretas.

---

# Características principales

* Arquitectura modular basada en OOP
* Uso de clases abstractas e interfaces
* Implementación de herencia y polimorfismo
* Separación clara entre lógica de negocio y utilidades
* Organización del proyecto por responsabilidades
* Código preparado para ampliaciones futuras

---

# Tecnologías utilizadas

| Tecnología                       | Uso                               |
| -------------------------------- | --------------------------------- |
| C++                              | Desarrollo principal del proyecto |
| Programación Orientada a Objetos | Diseño de arquitectura            |
| Archivos `.h/.hpp`               | Declaración de clases             |
| Archivos `.cpp`                  | Implementación de lógica          |

---

# Estructura del proyecto

| Carpeta / Archivo | Descripción                                     |
| ----------------- | ----------------------------------------------- |
| `FIS/`            | Núcleo principal del proyecto                   |
| `core/`           | Clases base abstractas e interfaces principales |
| `models/`         | Clases hijas con implementaciones concretas     |
| `services/`       | Lógica de negocio del sistema                   |
| `utils/`          | Funciones auxiliares y herramientas generales   |
| `include/`        | Cabeceras del proyecto (`.h` / `.hpp`)          |
| `main.cpp`        | Punto de entrada del programa                   |

---

# Arquitectura del sistema

El proyecto sigue un enfoque basado en componentes reutilizables.

## Clase base abstracta

Las clases base definen la estructura común que deben implementar las clases derivadas.

Características:

* Contienen métodos virtuales puros
* Funcionan como interfaz general del sistema
* No pueden instanciarse directamente
* Permiten desacoplar implementación y comportamiento

Ejemplo:

```cpp
class Base {
public:
    virtual void execute() = 0;
    virtual ~Base() {}
};
```

---

## Clases hijas

Las clases derivadas heredan de la clase base e implementan el comportamiento específico requerido.

Ventajas del enfoque utilizado:

* Reutilización de código
* Extensibilidad sencilla
* Sustitución de implementaciones mediante polimorfismo
* Mejor mantenimiento del sistema

---

# Flujo general del proyecto

```text
main.cpp
   │
   ├── Inicialización del sistema
   │
   ├── Uso de servicios
   │
   ├── Instanciación de modelos concretos
   │
   └── Ejecución de lógica mediante polimorfismo
```

---

# Principios OOP aplicados

| Principio     | Aplicación en el proyecto            |
| ------------- | ------------------------------------ |
| Encapsulación | Separación de datos y comportamiento |
| Herencia      | Uso de clases base y derivadas       |
| Polimorfismo  | Métodos virtuales y sobreescritura   |
| Abstracción   | Interfaces y clases abstractas       |

---

# Objetivo del proyecto

El proyecto busca demostrar una estructura limpia y organizada para aplicaciones desarrolladas en C++, aplicando buenas prácticas de diseño orientado a objetos.

---

# Posibles mejoras futuras

* Implementación de pruebas unitarias
* Sistema de gestión de dependencias
* Documentación automática con Doxygen
* Inyección de dependencias avanzada
* Manejo centralizado de errores

---

# Autor

Desarrollado por [Yared Ramos](https://github.com/Yared-Ramos?utm_source=chatgpt.com)

Repositorio:

[Repositorio FIS](https://github.com/Yared-Ramos/FIS?utm_source=chatgpt.com)
