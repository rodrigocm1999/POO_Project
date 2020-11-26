cmake_minimum_required(VERSION 3.17)
project(TrabalhoPratico)

set(CMAKE_CXX_STANDARD 14)

add_executable(TrabalhoPratico main.cpp
        Imperio.cpp Imperio.h
        Mundo.cpp Mundo.h
        Utils.cpp Utils.h
        Jogo.cpp Jogo.h
        ComanFase.cpp ComanFase.h
        GameSaver.cpp GameSaver.h
        Territorios/Castelo.cpp Territorios/Castelo.h
        Territorios/Continente.cpp Territorios/Continente.h
        Territorios/Duna.cpp Territorios/Duna.h
        Territorios/Fortaleza.cpp Territorios/Fortaleza.h
        Territorios/Ilha.cpp Territorios/Ilha.h
        Territorios/Mina.cpp Territorios/Mina.h
        Territorios/Montanha.cpp Territorios/Montanha.h
        Territorios/Pescaria.cpp Territorios/Pescaria.h
        Territorios/Planicie.cpp Territorios/Planicie.h
        Territorios/Refugio.cpp Territorios/Refugio.h
        Territorios/Territorio.cpp Territorios/Territorio.h
        Territorios/TerritorioInicial.cpp Territorios/TerritorioInicial.h
        )