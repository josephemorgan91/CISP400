CC = clang++
CFLAGS = -pedantic -g -Wno-c++11-long-long

Rational.out: RationalMain.o Rational.o
	$(CC) $(CFLAGS) RationalMain.o Rational.o -o Rational.out

RationalMain.o: RationalMain.cpp Rational.h
	$(CC) $(CFLAGS) -c RationalMain.cpp

Rational.o: Rational.cpp Rational.h
	$(CC) $(CFLAGS) -c Rational.cpp

clean:
	rm *.o
