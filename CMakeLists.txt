
cmake_minimum_required(VERSION 3.10)
project(Singleton)

set(CMAKE_CXX_STANDARD 17)

# Добавляем исполняемый файл для основного приложения
add_executable(Singleton main.cpp Singleton.cpp)

# Добавляем исполняемый файл для тестов
add_executable(SingletonTest test.cpp Singleton.cpp)
