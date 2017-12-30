./obj/assembler: assembler.cpp
	@if [ ! -d ./obj/ ];\
		then mkdir ./obj/; \
	fi
	g++ -std=c++11 -o ./obj/assembler assembler.cpp
run: ./obj/assembler
	cd test; ./testall.sh
