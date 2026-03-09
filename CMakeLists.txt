cmake_minimum_required(VERSION 3.26)

project(Math LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------- Math library ----------------
add_executable(Math
    src/main.cpp
)

target_include_directories(Math PRIVATE
    include
)