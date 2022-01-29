cmake_minimum_required(VERSION 3.20)
project(projekt)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES
        Node.cpp
        Tree.cpp
        AVL.cpp

        tests_Node.cpp
        tests_Tree.cpp
        tests_AVL.cpp


        GoogleTest/gtest-death-test.cc
        GoogleTest/gtest-filepath.cc
        GoogleTest/gtest-port.cc
        GoogleTest/gtest-printers.cc
        GoogleTest/gtest-test-part.cc
        GoogleTest/gtest-typed-test.cc
        GoogleTest/gtest.cc
        GoogleTest/gtest_main.cc )

include_directories(GoogleTest)
add_executable(projekt ${SOURCE_FILES})
