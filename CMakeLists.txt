cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(ex4 main.cpp CacheManager.cpp CacheManager.h ClientHandler.h FileCacheManager.cpp FileCacheManager.h
        MySerialServer.cpp MySerialServer.h Server.h Solver.cpp Solver.h StringReverser.cpp StringReverser.h Boot.h
        MyTestClientHandler.h MyTestClientHandler.cpp State.h ISearchable.h Searcher.h BestFS.h SearchByPQ.h
        CostsCompare.h MyMatrixClientHandler.cpp MyMatrixClientHandler.h Matrix.h Matrix.cpp )