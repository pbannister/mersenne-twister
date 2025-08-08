#
#
#

all : # default

clean : clean.o
clean.o : ; rm -rf o

o : ; mkdir o
bin : ; mkdir bin

CX	= g++ -O3 -Wall
#CX	= g++-6 -mavx2 -mtune=native -O3 -Wall

o/%.o: sources/%.cpp
	$(CX) -c -o $@ $<

O_rate=o/main.o o/mersenne_twister.o
X_rate=bin/rate

$(X_rate) : $(O_rate)
	$(CX) -o $@ $(O_rate)

rate : $(X_rate)
	$(X_rate)

all : o bin rate

o/%.s: sources/%.cpp
	$(CC) -S -c -o $@ $<

asm :  o/mersenne_twister.s

.PHONY: all rate clean clean.o asm
