cmake_minimum_required(VERSION 3.17)
project(PAsta C)

set(CMAKE_C_STANDARD 11)

include_directories(CCPL2G05)

add_executable(PAsta
        CCPL2G05/aritimetica.c
        CCPL2G05/aritimetica.h
        CCPL2G05/convertetipo.c
        CCPL2G05/convertetipo.h
        CCPL2G05/logica.c
        CCPL2G05/logica.h
        CCPL2G05/logicabin.c
        CCPL2G05/logicabin.h
        CCPL2G05/Main.c
        CCPL2G05/manipstack.c
        CCPL2G05/manipstack.h
        CCPL2G05/parser.c
        CCPL2G05/parser.h
        CCPL2G05/readline.c
        CCPL2G05/readline.h
        CCPL2G05/stack.c
        CCPL2G05/stack.h
        CCPL2G05/variaveis.c
        CCPL2G05/variaveis.h)
