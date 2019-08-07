#"libgcc_s_sjlj-1.dll"
# D:\Programok\MinGW\bin\x86_64-w64-mingw32-g++.exe src/main.cpp -std=c++11 -I hpp -static-libstdc++ -o bin/game.exe
CC=g++
SRC=src/main.cpp
FLAGS=-std=c++11 -I hpp -static-libstdc++
END=-o bin/game.exe

build:
    $(CC) $(SRC) $(FLAGS) $(END)
