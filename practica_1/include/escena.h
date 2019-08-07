/****************************************************************
*	Practica 1  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código de la escena , proporcionado por FJMelero
*
****************************************************************/
#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "objeto3D.h"
#include "cubo.h"
#include "piramide.h"
#include "tetraedro.h"
#include "file_ply_stl.h"
#include "vertex.h"

class Escena {

public:
char modo;

private:
// tamaño de los ejes
#define AXIS_SIZE 5000
Ejes ejes;

//Aqui se guarda la figura cargada
Objeto3D *objeto = new Objeto3D();
Cubo *cubo = new Cubo(30);
Tetraedro *tetraedro = new Tetraedro(30);
Piramide *piramide = new Piramide(30);



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

//Transformación de cámara
	void change_projection();
	void change_observer();


public:
     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
};
#endif
