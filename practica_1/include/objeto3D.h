/****************************************************************
*	Practica 1  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código del objeto3D
*
****************************************************************/
#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h> 
#include <vector>

using namespace std;

class Objeto3D {

protected:
	
	vector <float> vertices;
	vector <int> caras;
	vector <float> colores;	
	vector <int> indicesPares;
	vector <int> indicesImpares;
	vector <float> coloresPares;
	vector <float> coloresImpares;

public:
	Objeto3D();
	~Objeto3D();
	void dibujar(char modo);

private:
};

#endif
