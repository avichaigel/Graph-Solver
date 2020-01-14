cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex4 main.cpp ClientHandler.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.cpp CacheManager.h FileCacheManager.cpp FileCacheManager.h Solver.h Solver.cpp StringReverser.h StringReverser.cpp)