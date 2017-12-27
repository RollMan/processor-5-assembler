./obj/assembler: assembler.cpp
	g++ -std=c++11 -o ./obj/assembler assembler.cpp
run: ./obj/assembler
	cd test; ./testall.sh
