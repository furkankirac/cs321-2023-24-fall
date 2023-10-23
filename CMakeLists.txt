project(CS321)

SET(CMAKE_CXX_STANDARD 20)

# added for MacOS Sonoma + GCC 13.2 installation's linker problems
# selects classic linker to be used, not the new linker
SET(CMAKE_CXX_FLAGS "-Wl,-ld_classic")

add_executable(w1a1 "week1-app1.cpp")
add_executable(w3a1 "week3-app1.cpp")
add_executable(w4a1 "week4-app1.cpp")
