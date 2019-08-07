/****************************************************************
*	Practica 2  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código de la escena
*
****************************************************************/
#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "../include/escena.h"


Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
    
}

void Escena::inicializar(int UI_window_width,int UI_window_height, const string &path) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);
	path_ply=path;
}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
	objeto.dibujar();
}

void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {
	GLenum modePolygon;
	if (toupper(Tecla1)=='Q') {objeto.clear(); return 1;}
	else if (toupper(Tecla1)=='P') {   objeto.setChess(false); objeto.colorear(); objeto.setGlEnumPolygon(GL_POINT); return 0; }
	else if (toupper(Tecla1)=='L') {   objeto.setChess(false); objeto.colorear(); objeto.setGlEnumPolygon(GL_LINE); return 0; }
	else if (toupper(Tecla1)=='F') {   objeto.setChess(false); objeto.colorear(); objeto.setGlEnumPolygon(GL_FILL); return 0; }
	else if (toupper(Tecla1)=='C') {   objeto.setChess(true); objeto.colorearChess(); objeto.setGlEnumPolygon(GL_FILL); return 0; }
	else if (toupper(Tecla1)=='2') {   objeto.clear(); objeto = cubo; return 0; }
	else if (toupper(Tecla1)=='1') {   objeto.clear(); objeto = tetraedro; return 0; }
	else if (toupper(Tecla1)=='5') {   objeto.clear(); objeto = piramide; return 0; }
	else if (toupper(Tecla1)=='3') {   
		objeto.setChess(false); 
		objeto.clear();
		objetoPly.leerFichero(path_ply);
   		objeto = objetoPly;
   		if (toupper(Tecla1)=='3') {
   			objetoPly.closeFile();
	 	}
	 	return 0;
	}
	else if (toupper(Tecla1)=='4') {   
		cout << "REVOLUCION!!!" << endl;
		objeto.setChess(false);
		objeto.clear();
		objetoRevolucionado.read(path_ply);
		objetoRevolucionado.changeTapas();
		cout << "a revolucionar" << endl;
		objetoRevolucionado.revolucionarDesdePerfilAnterior();
		cout << "fin de revolucionado" << endl;
   		objeto = objetoRevolucionado;
   		if (toupper(Tecla1)=='4') {
   			objetoRevolucionado.close();
	 	}
	 	return 0;
	}
	else if (toupper(Tecla1)=='T') { 

	 	return 0;
	}
	else return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
	change_projection();
	Width=newWidth/10;
	Height=newHeight/10;
	glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {
	// posicion del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-Observer_distance);
	glRotatef(Observer_angle_x,1,0,0);
	glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
	ejes.draw();
}




