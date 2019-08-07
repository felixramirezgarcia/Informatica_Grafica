/****************************************************************
*	Practica 2  Informática Gráfica
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
#include <stdlib.h> // pulls in declaration of malloc, free
#include <vector>
#include "vertex.h"

using namespace std;

/**
* Clase principal que contiene las estructuras de datos para modelar objetos3D
*/

class Objeto3D {

public:

	vector<_vertex3f> vertices;	//Variable que almacena los vertices del objeto3D
	vector<_vertex3f> colores;	//Variable que almacena los colores del objeto3D
	vector<_vertex3i> indices;	//Variable que almacena las caras del objeto3D

	//Variables para almacenar los colores y las caras para el modo ajedrez
	vector<_vertex3f> coloresPares;
	vector<_vertex3f> coloresImpares;
	vector<_vertex3i> indicesPares;
	vector<_vertex3i> indicesImpares;

	GLenum modePolygon = GL_LINE;
	GLenum mode;
	bool chess;

public:
	Objeto3D();
	void dibujar();
	void setGlEnumPolygon(GLenum elem){ modePolygon=elem; }
	void colorear();
	void colorearChess();
	void setChess(bool val){ chess=val; }
	void clear();
	vector<_vertex3i> & getIndices(){ return indices; }
	vector<_vertex3f> & getVertices(){ return vertices; }
	//Funcion para inicializar el vector de vertices
	void setVertices(vector<_vertex3f> vec){ vertices = vec; }
	//Funcion para inicializar el vector de caras
	void setIndices(vector<_vertex3i> vec){ indices = vec; }
	//Funcion para insertar un vertice al final del vector de vertices
	void setVertice(_vertex3f vec){ vertices.push_back(vec); }
	//Funcion para insertar una cara en el vector de caras
	void setIndice(_vertex3i vec){ indices.push_back(vec); }
	//Funcion para obtener un determinado vertice
	_vertex3f getVertice(int i){ return vertices[i]; }
	//Funcion par aobtener una determinada cara
	_vertex3i getIndice(int i){ return indices[i]; }

};

#endif
