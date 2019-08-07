/****************************************************************
*	Practica 1  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código del Objeto3D
*
****************************************************************/
#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include "../include/objeto3D.h"

Objeto3D::Objeto3D(){

}

Objeto3D::~Objeto3D(){
	/*this->vertices.clear();
	this->caras.clear();
	this->colores.clear();
	this->subcaraspares.clear();
	this->subcarasimpares.clear();
	this->colorespares.clear();
	this->coloresimpares.clear();*/
}

void Objeto3D::dibujar(char modo){
	//habilitar la maquina de estado de opengl
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_INDEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	//glEnable(GL_CULL_FACE);
	//vector de vertices de 3 en 3 desde el indice 0
	glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
	//vector de caras desde el indice 0
	glIndexPointer(GL_UNSIGNED_INT, 0, &caras[0]);

	if(modo == '1' || modo == '2' || modo == '3'){ //dibujar figuras rellenas modo arcoiris
		glColorPointer(3,GL_FLOAT,0,&colores[0]);
		glDrawElements(GL_TRIANGLES,caras.size(),GL_UNSIGNED_INT,&caras[0]);
		glPointSize(5);
		glDrawElements(GL_POINTS,caras.size(),GL_UNSIGNED_INT,&caras[0]);
		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glDrawElements(GL_TRIANGLES,caras.size(),GL_UNSIGNED_INT,&caras[0]);
	}
	else if(modo == 'p'){ //puntos
		glColorPointer(3,GL_FLOAT,0,&colores[0]);
		glPointSize(5);
		glDrawElements(GL_TRIANGLES,caras.size(),GL_UNSIGNED_INT,&caras[0]);
	}
	else if(modo == 'l'){ //lineas
		glColorPointer(3,GL_FLOAT,0,&colores[0]);
		glDrawElements(GL_TRIANGLES,caras.size(),GL_UNSIGNED_INT,&caras[0]);
	}
	else if(modo == 'f'){ //relleno
		glColorPointer(3,GL_FLOAT,0,&colores[0]);
		glDrawElements(GL_TRIANGLES,caras.size(),GL_UNSIGNED_INT,&caras[0]);
	}
	else if(modo == 'c'){ //ajedrez
		 for(int i=0;i<caras.size();i+=3){
		  if(i%2 == 0){
		   indicesPares.push_back(caras[i]);
		   indicesPares.push_back(caras[i+1]);
		   indicesPares.push_back(caras[i+2]);

		   coloresPares.push_back(0);
		   coloresPares.push_back(0);
		   coloresPares.push_back(1);

		   coloresPares.push_back(0);
		   coloresPares.push_back(0);
		   coloresPares.push_back(1);

		   coloresPares.push_back(0);
		   coloresPares.push_back(0);
		   coloresPares.push_back(1);
		  }
		  else{
		   indicesImpares.push_back(caras[i]);
		   indicesImpares.push_back(caras[i+1]);
		   indicesImpares.push_back(caras[i+2]);

		   coloresImpares.push_back(1);
		   coloresImpares.push_back(0);
		   coloresImpares.push_back(0);

		   coloresImpares.push_back(1);
		   coloresImpares.push_back(0);
		   coloresImpares.push_back(0);

		   coloresImpares.push_back(1);
		   coloresImpares.push_back(0);
		   coloresImpares.push_back(0);
		  }
		 } 
		 glColorPointer( 3, GL_FLOAT, 0, coloresPares.data());
  		 glDrawElements(GL_TRIANGLES, caras.size()/2 ,GL_UNSIGNED_BYTE, indicesPares.data() ) ; 
 		 glColorPointer( 3, GL_FLOAT, 0, coloresImpares.data());
 		 glDrawElements(GL_TRIANGLES, caras.size()/2 ,GL_UNSIGNED_BYTE, indicesImpares.data() ) ;
	}

	//deshabilitar la maquina de estado de opengl
	glDisableClientState(GL_INDEX_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

}


