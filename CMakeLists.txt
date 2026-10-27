
cmake_minimum_required(VERSION 3.20)
project(LinkedList C)

set(CMAKE_C_STANDARD 99)

add_executable(LinkedList
        main.c
        ll/ll.c
        dll/dll.c
)

add_executable(bitoperationen
        bitoperationen/main.c
)
add_executable(regelkreis regelkreis/main.c)
