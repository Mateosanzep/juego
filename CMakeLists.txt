cmake_minimum_required(VERSION 3.16)

project(Millonario)

# Agrega la ruta de Qt (ajusta según tu instalación)
set(CMAKE_PREFIX_PATH "C:/Qt/6.8.1/mingw_64/lib/cmake")

# Establece el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encuentra los módulos de Qt que necesitas
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Agrega tu ejecutable
# add_executable(Millonario main.cpp Ventana1.cpp Ventana2.cpp)
add_executable(Millonario juego.cpp constantes.cpp game.cpp questions.cpp main.cpp intro.cpp tiempo.cpp mal.cpp ganaste.cpp juego.h constantes.h game.h questions.h intro.h tiempo.h mal.h ganaste.h)

set_target_properties(Millonario PROPERTIES
    AUTOMOC ON
)

# Vincula las bibliotecas de Qt necesarias
target_link_libraries(Millonario PRIVATE Qt6::Widgets)

# poner un build step para windows, esto es para que prepare el ejecutable con "windeployqt.exe"
if(WIN32)
    add_custom_command(TARGET Millonario POST_BUILD 
        COMMAND "${CMAKE_PREFIX_PATH}/../../bin/windeployqt.exe" "$<TARGET_FILE:Millonario>"
    )
endif()

