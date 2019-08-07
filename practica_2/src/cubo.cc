/****************************************************************
*	Practica 2  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código del cubo
*
****************************************************************/
#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/cubo.h"
#include <vector>
#include <iostream>

using namespace std;

/**
* Constructor
*/
Cubo::Cubo(){
	tam=50;
	this->createArrayData();
}

/**
* Constructor por parametro
*/
Cubo::Cubo(float val){
	tam=val;
	this->createArrayData();
}

/**
* Crea las estructuras de datos para contener la información que dibuja un cubo
*/
void Cubo::createArrayData(){
	// vertices
	vertices.push_back(_vertex3f(tam,tam,tam));
	vertices.push_back(_vertex3f(-tam,tam,tam));
	vertices.push_back(_vertex3f(-tam,-tam,tam));
	vertices.push_back(_vertex3f(tam,-tam,tam));
	vertices.push_back(_vertex3f(tam,tam,-tam));			
	vertices.push_back(_vertex3f(-tam,tam,-tam));			
	vertices.push_back(_vertex3f(-tam,-tam,-tam));			
	vertices.push_back(_vertex3f(tam,-tam,-tam));			
	// orden de los triangulos
	indices.push_back(_vertex3i(6,3,2));
	indices.push_back(_vertex3i(6,7,3));
	indices.push_back(_vertex3i(7,0,3));
	indices.push_back(_vertex3i(7,4,0));
	indices.push_back(_vertex3i(5,2,1));
	indices.push_back(_vertex3i(5,6,2));
	indices.push_back(_vertex3i(0,1,2));
	indices.push_back(_vertex3i(2,3,0));
	indices.push_back(_vertex3i(1,4,0));
	indices.push_back(_vertex3i(5,4,1));
	indices.push_back(_vertex3i(5,4,7));
	indices.push_back(_vertex3i(7,6,5));
	// colorear la figura
	Objeto3D::colorear();
}

