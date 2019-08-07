/****************************************************************
*	Practica 2  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código del tetraedro
*
****************************************************************/
#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/tetraedro.h"
#include <vector>
#include <iostream>

using namespace std;

/**
* Constructor
*/
Tetraedro::Tetraedro(){
	tam=50;
	this->createArrayData();
}

/**
* Constructor por parámetros
*/
Tetraedro::Tetraedro(float val){
	tam=val;	
	this->createArrayData();
}

/**
* Crea las estructuras de datos para contener la información que dibuja un tetraedro
*/
void Tetraedro::createArrayData(){
	//vertices
	vertices.push_back(_vertex3f(0,tam,-tam/2));
	vertices.push_back(_vertex3f(-tam,-tam,-tam/2));
	vertices.push_back(_vertex3f(tam,-tam,-tam/2));
	vertices.push_back(_vertex3f(0,0,tam/1.5));
	// triangulos
	indices.push_back(_vertex3i(2,3,1));
	indices.push_back(_vertex3i(2,0,3));
	indices.push_back(_vertex3i(0,1,3));
	indices.push_back(_vertex3i(1,0,2));

	Objeto3D::colorear();
}

