cmake_minimum_required(VERSION 3.17)
project(TrabalhoPratico)

set(CMAKE_CXX_STANDARD 14)

add_executable(TrabalhoPratico main.cpp
        Kingdom.cpp Kingdom.h
        World.cpp World.h
        Utils.cpp Utils.h
        Game.cpp Game.h
        PhaseCommand.cpp PhaseCommand.h
        GameSaver.cpp GameSaver.h
        GameInterface.cpp GameInterface.h
        Factory.cpp Factory.h

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

        Technologies/Technology.cpp Technologies/Technology.h
        Technologies/BancoCentral.cpp Technologies/BancoCentral.h
        Technologies/BolsaValores.cpp Technologies/BolsaValores.h
        Technologies/DefesasTerritoriais.cpp Technologies/DefesasTerritoriais.h
        Technologies/DroneMilitar.cpp Technologies/DroneMilitar.h
        Technologies/MisseisTeleguiados.cpp Technologies/MisseisTeleguiados.h
        Constants.h)