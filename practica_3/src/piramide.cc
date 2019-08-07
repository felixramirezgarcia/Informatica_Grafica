/****************************************************************
*	Practica 2  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código de la piramide
*
****************************************************************/
#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/piramide.h"
#include <vector>
#include <iostream>

using namespace std;

/**
* Constructor
*/
Piramide::Piramide(){
	tam=50;
	this->createArrayData();
}

/**
* Constructor por parametro
*/
Piramide::Piramide(float val){
	tam=val;	
	this->createArrayData();
}

/**
* Crea las estructuras de datos para contener la información que dibuja una pirámide
*/
void Piramide::createArrayData(){
	//vertices
	vertices.push_back(_vertex3f(-tam,-tam,-tam/2));
	vertices.push_back(_vertex3f(tam,-tam,-tam/2));
	vertices.push_back(_vertex3f(tam,tam,-tam/2));
	vertices.push_back(_vertex3f(-tam,tam,-tam/2));
	vertices.push_back(_vertex3f(0,0,tam*1.5));
	// triangulos
	indices.push_back(_vertex3i(0,1,4));
	indices.push_back(_vertex3i(1,2,4));
	indices.push_back(_vertex3i(2,3,4));
	indices.push_back(_vertex3i(3,0,4));
	indices.push_back(_vertex3i(3,0,1));
	indices.push_back(_vertex3i(1,2,3));
	Objeto3D::colorear();
}

