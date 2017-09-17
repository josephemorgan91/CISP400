CC = g++
CFLAGS = -Wall -pedantic -g

Marina.out: MarinaMain.o Marina.o Boat.o MusclePowered.o MotorPowered.o Kayak.o Shanty.o Ski.o CabinCruiser.o
	$(CC) $(CFLAGS) MarinaMain.o Marina.o Boat.o MusclePowered.o MotorPowered.o Ski.o Kayak.o Shanty.o CabinCruiser.o -o Marina.out

MarinaMain.o: MarinaMain.cpp
	$(CC) $(CFLAGS) MarinaMain.cpp -c

Marina.o: Marina.cpp Marina.h
	$(CC) $(CFLAGS) Marina.cpp -c

MusclePowered.o: MusclePowered.cpp MusclePowered.h
	$(CC) $(CFLAGS) MusclePowered.cpp -c

MotorPowered.o: MotorPowered.cpp MotorPowered.h
	$(CC) $(CFLAGS) MotorPowered.cpp -c

Kayak.o: Kayak.cpp Kayak.h
	$(CC) $(CFLAGS) Kayak.cpp -c

Shanty.o: Shanty.cpp Shanty.h
	$(CC) $(CFLAGS) Shanty.cpp -c

Ski.o: Ski.cpp Ski.h
	$(CC) $(CFLAGS) Ski.cpp -c

CabinCruiser.o: CabinCruiser.cpp CabinCruiser.h
	$(CC) $(CFLAGS) CabinCruiser.cpp -c

clean:
	rm *.o

vim:
	vim Marina.h Marina.cpp Boat.h MusclePowered.cpp MusclePowered.h MotorPowered.cpp MotorPowered.h Kayak.cpp Kayak.h Shanty.cpp Shanty.h Ski.cpp Ski.h CabinCruiser.cpp CabinCruiser.h
