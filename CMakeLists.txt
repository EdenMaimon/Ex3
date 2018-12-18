cmake_minimum_required(VERSION 3.13)
project(Ex3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Ex3 main.cpp Interpreter.h Interpreter.cpp Command.h Expression.h CommandExpression.h clientTast.cpp clientTast.h ThreadSafeMap.h)