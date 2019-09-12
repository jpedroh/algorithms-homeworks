cmake_minimum_required(VERSION 3.14)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp main.cpp structures/Stack.cpp structures/Stack.h operators/BinaryOperator.cpp operators/BinaryOperator.h operators/BinaryOperatorFactory.cpp operators/BinaryOperatorFactory.h operators/AndOperator.cpp operators/AndOperator.h operators/OrOperator.cpp operators/OrOperator.h operators/ImpliesOperator.cpp operators/ImpliesOperator.h)