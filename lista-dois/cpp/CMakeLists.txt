cmake_minimum_required(VERSION 3.14)
project(lista_dois)

set(CMAKE_CXX_STANDARD 17)

add_executable(lista_dois main.cpp parkings/BaseParkingSystem.cpp parkings/BaseParkingSystem.h ParkedCar.cpp ParkedCar.h parkings/ParkingA.cpp parkings/ParkingA.h parkings/ParkingB.cpp parkings/ParkingB.h)