
cmake_minimum_required(VERSION 3.20)
project(LinkedList C)

set(CMAKE_C_STANDARD 99)

add_executable(LinkedList
        main.c
        ll/ll.c
        dll/dll.c
        bitoperationen/main.c
)
