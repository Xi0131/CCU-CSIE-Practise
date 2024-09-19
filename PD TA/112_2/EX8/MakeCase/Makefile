all: input.cpp output.cpp input_validator.cpp input.o output.o input_validator.o

input: input.cpp
	g++ -std=c++11 input.cpp -o input.exe
	./input.exe

output: output.cpp
	g++ -std=c++11 output.cpp -o output.exe
	./output.exe

inputv: input_validator.cpp
	g++ -std=c++11 input_validator.cpp -o input_validator.exe

clean:
	rm input.exe
	rm output.exe
	rm input_validator.exe
