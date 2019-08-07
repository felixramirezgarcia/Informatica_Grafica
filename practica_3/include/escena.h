/****************************************************************
*	Practica 2  Inform�tica Gr�fica
*
*	Grado en Ingenier�a Inform�tica
*
*	2017 - F�lix Ram�rez Garc�a <felixramirezgarcia@correo.ugr.es>
*
*	C�digo de la escena
*
****************************************************************/
#ifndef _ESCENA_H
#define _ESCENA_H

#include <iostream>
#include "ejes.h"
#include "objeto3D.h"
#include "cubo.h"
#include "tetraedro.h"
#include "piramide.h"
#include "objeto_ply.h"
#include "ventilador.h"
#include "objetorevolucionado.h"
#include "cilindro.h"


class Escena {
private:
// tama�o de los ejes
#define AXIS_SIZE 5000
Ejes ejes;
// Clases creadas
Objeto3D objeto;
Cubo cubo;
Tetraedro tetraedro;
Piramide piramide;
ObjetoPly objetoPly;
string path_ply;

ObjetoRevolucionado objetoRevolucionado;

Ventilador ventilador;
float grado1 = 0.0;
float grado2 = 0.0;
float grado3 = 0.0;
bool isventilador = false;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformaci�n de c�mara
	void change_projection();
	void change_observer();

public:
    Escena();
	void inicializar(int UI_window_width,int UI_window_height, const string &path_ply);
	void redimensionar(int newWidth,int newHeight) ;
	// Dibujar
	void dibujar() ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
};
#endif
