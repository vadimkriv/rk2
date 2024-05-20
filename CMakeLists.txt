cmake_minimum_required(VERSION 3.10)

# Название проекта
project(Singleton)

# Установить стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавить исходные файлы
add_executable(Singleton src/main.cpp)

# Добавить тесты
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(SingletonTest tests/test_Singleton.cpp)
target_link_libraries(SingletonTest ${GTEST_LIBRARIES} pthread)

add_test(NAME SingletonTest COMMAND SingletonTest)
