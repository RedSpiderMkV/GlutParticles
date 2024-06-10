CC=g++
OUTDIR=out

all: MakeThreeComponentVector MakeParticle

MakeParticle: MakeThreeComponentVector
	$(CC) -Wall -c Particle.cpp -o Particle.o

MakeThreeComponentVector:
	$(CC) -Wall -c ThreeComponentVector.cpp -o ThreeComponentVector.o


