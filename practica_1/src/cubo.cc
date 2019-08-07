/****************************************************************
*	Practica 1  Informática Gráfica
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

Cubo::Cubo(){
	
}


Cubo::Cubo(int tam){	
	createArrayData(tam);
}


void Cubo::createArrayData(int tam){

	//vertice 0
	vertices.push_back(tam);//x
	vertices.push_back(tam);//y
	vertices.push_back(tam);//z

	//vertice 1
	vertices.push_back(-tam);
	vertices.push_back(tam);
	vertices.push_back(tam);

	//vertice 2
	vertices.push_back(-tam);
	vertices.push_back(-tam);
	vertices.push_back(tam);
	
	//vertice 3
	vertices.push_back(tam);
	vertices.push_back(-tam);
	vertices.push_back(tam);
	
	//vertice 4
	vertices.push_back(tam);
    vertices.push_back(tam);
    vertices.push_back(-tam);

    //vertice 5
	vertices.push_back(-tam);
    vertices.push_back(tam);
    vertices.push_back(-tam);

    //vertice 6
	vertices.push_back(-tam);
    vertices.push_back(-tam);
    vertices.push_back(-tam);
    
    //vertice 7
    vertices.push_back(tam);
    vertices.push_back(-tam);
    vertices.push_back(-tam);
	
    //caras Frontal
    caras.push_back(6);
    caras.push_back(3);
    caras.push_back(2);

    //caras Frontal 
    caras.push_back(6);
    caras.push_back(7);
    caras.push_back(3);

    //caras Frontal derecha
    caras.push_back(7);
    caras.push_back(0);
    caras.push_back(3);

    //caras Frontal derecha
    caras.push_back(7);
    caras.push_back(4);
    caras.push_back(0);

    //caras Frontal izquierda
    caras.push_back(5);
    caras.push_back(2);
    caras.push_back(1);

    //caras Frontal izquierda
    caras.push_back(5);
    caras.push_back(6);
    caras.push_back(2);

    //caras superior
    caras.push_back(0);
    caras.push_back(1);
    caras.push_back(2);

    //caras superior
    caras.push_back(2);
    caras.push_back(3);
    caras.push_back(0);

    //caras trasera
    caras.push_back(1);
    caras.push_back(4);
    caras.push_back(0);

    //caras  trasera 
    caras.push_back(5);
    caras.push_back(4);
    caras.push_back(1);

    //caras abajo
    caras.push_back(5);
    caras.push_back(4);
    caras.push_back(7);

    //caras abajo
    caras.push_back(7);
    caras.push_back(6);
    caras.push_back(5);

    //colores 
    colores.push_back(1);
    colores.push_back(0);
    colores.push_back(0);

   //colores 
    colores.push_back(1);
    colores.push_back(0);
    colores.push_back(0);

    //colores 
    colores.push_back(1);
    colores.push_back(0);
    colores.push_back(0);

    //colores 
    colores.push_back(1);
    colores.push_back(0);
    colores.push_back(0);

    //colores 
    colores.push_back(1);
    colores.push_back(0);
    colores.push_back(0);

    //colores 
    colores.push_back(1);
    colores.push_back(0);
    colores.push_back(0);

    //colores 
    colores.push_back(1);
    colores.push_back(0);
    colores.push_back(0);

    //colores 
    colores.push_back(1);
    colores.push_back(0);
    colores.push_back(0);
    
}

