run: prac_compo
	./prac_compo
prac_compo: prac_compo.cpp Rectangulo.o Coordenada.o
	g++ prac_compo.cpp Rectangulo.o Coordenada.o -o prac_compo
Rectangulo.o: Rectangulo.cpp
	g++ Rectangulo.cpp -c
Coordenada.o: Coordenada.cpp	
	g++ Coordenada.cpp -c