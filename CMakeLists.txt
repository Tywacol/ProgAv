cmake_minimum_required(VERSION 3.13)
project(ProgAv)

set(CMAKE_CXX_STANDARD 14)

include_directories(TP/TP2)

add_executable(ProgAv
        TP/TP2/annu.txt
        TP/TP2/entiers.txt
        TP/TP2/ldc.c
        TP/TP2/moyenne_fichier.c
        TP/TP2/nouveau_annu.txt
        TP/TP2/tp2.c
        TP/TP2/TP2.pdf)
