project(CS321)

SET(CMAKE_CXX_STANDARD 20)

# added for MacOS Sonoma + GCC 13.2 installation's linker problems
# selects classic linker to be used, not the new linker
SET(CMAKE_CXX_FLAGS "-Wl,-ld_classic")

add_executable(w1a1 "week1-app1.cpp")
add_executable(w3a1 "week3-app1.cpp")
add_executable(w4a1 "week4-app1.cpp")
add_executable(w5a1 "week5-app1.cpp")
add_executable(w5a2 "week5-app2.cpp")
add_executable(w5a3 "week5-app3.cpp")
add_executable(w6a1 "week6-app1.cpp")
add_executable(w8a1 "week8-app1.cpp")
add_executable(w8a2 "week8-app2.cpp")
add_executable(w9a1 "week9-app1.cpp")
add_executable(w10a1 "week10-app1.cpp")
add_executable(w10a2 "week10-app2.cpp")
add_executable(w10a3 "week10-app3.cpp")
add_executable(w10a4 "week10-app4.cpp")
add_executable(w11a1 "week11-app1.cpp")
add_executable(w12a1 "week12-app1.cpp")
add_executable(w12a2 "week12-app2.cpp")
add_executable(w12a3 "week12-app3.cpp")
add_executable(w12a4 "week12-app4.cpp")
