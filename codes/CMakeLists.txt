
# Requiere la versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(MeowPeow)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*,-clang-analyzer-alpha.*")

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

# Busca las rutas de raylib automáticamente con pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

# Añade las cabeceras y librerías encontradas por pkg-config
include_directories(${RAYLIB_INCLUDE_DIRS})
link_directories(${RAYLIB_LIBRARY_DIRS})
target_link_libraries(meowpeow ${RAYLIB_LIBRARIES})

