# Requiere la versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(MeowPeow)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 17)

# Incluir las carpetas de cabeceras
include_directories(classes)

# Agregar los archivos fuente
set(SOURCES
    source_files/scene.cpp
    source_files/game_object.cpp
    source_files/assets.cpp
    source_files/player.cpp
    source_files/app.cpp
)

# Buscar raylib
find_package(raylib REQUIRED)

# Crear el ejecutable
add_executable(meowpeow ${SOURCES})

# Vincular raylib al proyecto
target_link_libraries(meowpeow raylib)

# Opcional: Especificar otras bibliotecas necesarias (ej. OpenGL, X11 para Linux)
if(UNIX)
    target_link_libraries(meowpeow GL m pthread dl rt X11)
endif()

