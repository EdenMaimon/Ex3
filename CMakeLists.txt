cmake_minimum_required(VERSION 3.13)
project(Ex3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Ex3 main.cpp Interpreter.h Interpreter.cpp Command.h Expression.h CommandExpression.h SafeMap.h ThreadSafeMap.h DataServerReader.h DataServerReader.cpp DataManager.h ListThreadSafeMap.h ClientSendingData.h ClientSendingData.cpp Variable.h DoubleVariable.h BoundedVariable.h "BoundedVariable.cpp" DataManager.cpp Lexer.h Lexer.cpp FileCreator.h FIleCreator.cpp shuntingYard.cpp shuntingYard.h Plus.cpp Plus.h Minus.cpp Minus.h Div.cpp Div.h Mul.cpp Mul.h BinaryExpression.h Number.h StringExpression.h SafeMap.cpp)