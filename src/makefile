GLUT=-lGL -lGLU -lglut
OUTDIR=out
STD=-std=c++11

all: CreateDir MakeInit MakeParticle MakeDeltaTimeManager MakeSceneBuilder MakeMain

MakeMain:
	g++ -Wall $(STD) main2.cpp $(OUTDIR)/*.o $(GLUT) -o $(OUTDIR)/ParticlesTest.exe

MakeDeltaTimeManager:
	make -C DeltaTime
	mv DeltaTime/*.o $(OUTDIR)

MakeParticle:
	make -C Particle
	mv Particle/*.o $(OUTDIR)

MakeSceneBuilder:
	make -C SceneBuilder
	mv SceneBuilder/*.o $(OUTDIR)

MakeInit:
	make -C GlutInit
	mv GlutInit/*.o $(OUTDIR)

CreateDir:
	mkdir -p $(OUTDIR)

clean:
	rm -rf $(OUTDIR)
