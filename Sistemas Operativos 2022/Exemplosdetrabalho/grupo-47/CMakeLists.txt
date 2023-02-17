cmake_minimum_required(VERSION 3.17)
project(grupo_47)

set(CMAKE_CXX_STANDARD 14)

include_directories(aurras/src)

add_executable(grupo_47
        .idea/.gitignore
        .idea/workspace.xml
        aurras/bin/aurrasd-filters/aurrasd-echo
        aurras/bin/aurrasd-filters/aurrasd-gain-double
        aurras/bin/aurrasd-filters/aurrasd-gain-half
        aurras/bin/aurrasd-filters/aurrasd-tempo-double
        aurras/bin/aurrasd-filters/aurrasd-tempo-half
        aurras/docs/Grupo-47.pdf
        aurras/etc/aurrasd.conf
        "aurras/samples/Ievan Polkka (Loituma).m4a"
        aurras/samples/sample-1-so.m4a
        aurras/samples/sample-2-miei.m4a
        aurras/samples/sample-3-lcc.m4a
        aurras/samples/sample3.m4a
        aurras/src/_README
        aurras/src/aurras.c
        aurras/src/aurras.h
        aurras/src/aurrasd.c
        aurras/Makefile)
