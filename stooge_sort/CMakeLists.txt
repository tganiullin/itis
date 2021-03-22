cmake_minimum_required(VERSION 3.17)
project(stooge_sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    stooge_sort
    main.cpp
        StoogeSorts/stoogeSorts.h
        StoogeSorts/stoogeSortArray.cpp
        StoogeSorts/stoogeSortLinkedList.cpp DataGenerator/dataGenerator.cpp DataGenerator/dataGenerator.h)