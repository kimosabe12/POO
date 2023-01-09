cmake_minimum_required(VERSION 3.22)
project(trabalho_poo)

set(CMAKE_CXX_STANDARD 14)

add_executable(trabalho_poo main.cpp Terminal.cpp Terminal.h Animais.cpp Animais.h Utils.h Alimento.cpp Alimento.h Reserva.cpp Reserva.h Interface.cpp Interface.h le_constantes.cpp le_constantes.h)
target_link_libraries(${PROJECT_NAME} c:/PDCurses-3.9/wincon/pdcurses.a)