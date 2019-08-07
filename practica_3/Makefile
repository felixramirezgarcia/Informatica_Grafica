# fichero Makefile
#
# nombre del fichero ejecutable
#
TARGETS= practica3

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuración
#
CFLAGS=    -std=c++11 -g -DXWINDOWS -DSHM -I/usr/include -I.
CXXFLAGS=  -std=c++11 -g -DXWINDOWS -DSHM -I/usr/include -I.

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
LDFLAGS=  -lGLU -lGL -lglut

# definicion del compilador
#
CC = g++ 

# definicion de objetos
#
OBJECTS= src/practica1.o src/escena.o src/ejes.o src/objeto3D.o src/cubo.o src/tetraedro.o src/piramide.o src/file_ply_stl.o src/objeto_ply.o src/objetorevolucionado.o src/ventilador.o src/cilindro.o
# orden que sera ejecutada por defecto
#
default : $(TARGETS)

# regla de ejecucion
#
$(TARGETS) : $(OBJECTS)
	$(CC) -o $@ $(CXXFLAGS) $(OBJECTS) $(LDFLAGS)

#
#
clean:
	rm -f *.o
	rm -f $(TARGETS)

#
#
redo:
	touch src/*.cc
	make

#
#
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#
tgz:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)
	tar -zcvf $(TARGETS).tgz *