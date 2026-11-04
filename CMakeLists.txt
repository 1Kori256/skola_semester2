cmake_minimum_required(VERSION 3.16)
project(semester_two LANGUAGES CXX)

# The original coursework uses variable-length arrays supported by GCC/Clang.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

foreach(program IN ITEMS
    ctverec
    diff
    kvadrantova_komprese
    plot
    roztrzity_profesor
    sazba
    spolocny_podretezec
    tecky_a_zavorky)
    add_executable(${program} ${program}.cpp)
endforeach()
