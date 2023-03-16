SHELL =  /usr/bin/bash
CC := gcc
obj := main.o myIO.o myConv.o myCalc.o
exe := main

all: $(obj)
	$(CC) $(obj) -o $(exe)

%.o: %.c
	$(CC) -c $^ -o $@

.PHONY: clean
clean:
	rm -rf $(obj) $(exe)