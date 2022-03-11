cmake_minimum_required(VERSION 3.17)
project(CCPL2G05_main C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CCPL2G05_main
        aritimetica.c
        aritimetica.h
        array.c
        array.h
        convertetipo.c
        convertetipo.h
        logica.c
        logica.h
        logicabin.c
        logicabin.h
        Main.c
        manipstack.c
        manipstack.h
        parser.c
        parser.h
        readline.c
        readline.h
        stack.c
        stack.h
        strtok.c
        variaveis.c
        variaveis.h)
