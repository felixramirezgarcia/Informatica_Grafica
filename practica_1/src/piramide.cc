/****************************************************************
*	Practica 1  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código de la pirámide
*
****************************************************************/
#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/piramide.h"
#include <vector>

Piramide::Piramide(){
	
}

Piramide::Piramide(int tam){	
	createArrayData(tam);
}

void Piramide::createArrayData(int tam){

	//vertice 0
	vertices.push_back(-tam);
	vertices.push_back(-tam);
	vertices.push_back(-tam/2);

	//vertice 1
	vertices.push_back(tam);
	vertices.push_back(-tam);
	vertices.push_back(-tam/2);

	//vertice 2
	vertices.push_back(tam);
	vertices.push_back(tam);
	vertices.push_back(-tam/2);
	
	//vertice 3
	vertices.push_back(-tam);
	vertices.push_back(tam);
	vertices.push_back(-tam/2);

    //vertice 3
    vertices.push_back(0);
    vertices.push_back(0);
    vertices.push_back(tam*1.5);
	/*--------------------------------------------------------------------------------*/
    //caras 0
    caras.push_back(0);
    caras.push_back(1);
    caras.push_back(4);
    //caras1
    caras.push_back(1);
    caras.push_back(2);
    caras.push_back(4);
    //caras2
    caras.push_back(2);
    caras.push_back(3);
    caras.push_back(4);
    //caras3
    caras.push_back(3);
    caras.push_back(0);
    caras.push_back(4);
    //caras4
    caras.push_back(3);
    caras.push_back(0);
    caras.push_back(1);
    //caras5
    caras.push_back(1);
    caras.push_back(2);
    caras.push_back(3);
    /*---------------------------------------------------------------------------------*/
    //colores
    colores.push_back(1);
    colores.push_back(0.5);
    colores.push_back(0.5);

    colores.push_back(0.5);
    colores.push_back(0.5);
    colores.push_back(1);

    colores.push_back(0.5);
    colores.push_back(1);
    colores.push_back(0.5);

    colores.push_back(1);
    colores.push_back(0.5);
    colores.push_back(0.5);

    colores.push_back(0.5);
    colores.push_back(0.5);
    colores.push_back(1);

    

}