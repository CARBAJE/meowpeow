# Requiere la versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(MeowPeow)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 17)

# Incluir las carpetas de cabeceras
include_directories(classes)

# Agregar los archivos fuente automáticamente
file(GLOB SOURCES "source_files/*.cpp")

# Buscar raylib
find_package(raylib REQUIRED)

# Crear el ejecutable
add_executable(meowpeow ${SOURCES})

# Opciones de compilación específicas
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(meowpeow PRIVATE -march=native)
endif()

# Vincular raylib al proyecto
target_link_libraries(meowpeow raylib)

# Opcional: Especificar otras bibliotecas necesarias (ej. OpenGL, X11 para Linux)
if(UNIX)
    target_link_libraries(meowpeow GL m pthread dl rt X11)
endif()

# --- Integración con herramientas de pruebas ---

## 1. Valgrind: Crear un target para pruebas con Valgrind
add_custom_target(valgrind
    COMMAND valgrind --leak-check=full --show-leak-kinds=all $<TARGET_FILE:meowpeow> > valgrind_output.txt 2>&1
    DEPENDS meowpeow
    COMMENT "Ejecutando Valgrind y guardando salida en valgrind_output.txt"
)

## 2. gcov y lcov: Activar cobertura de código
if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(meowpeow PRIVATE --coverage)
    target_link_options(meowpeow PRIVATE --coverage)
endif()

