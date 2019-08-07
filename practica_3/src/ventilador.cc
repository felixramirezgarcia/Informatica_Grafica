/****************************************************************
*	Practica 3  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código del ventilador
*
****************************************************************/
#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/ventilador.h"
#include <vector>
#include <iostream>

using namespace std;

/**
* Constructor
*/
Ventilador::Ventilador(){
	grado1 = 0;
	grado2 = 0;
};

void Ventilador::setGrado1(float grado1){
	this->grado1 = grado1;
};

void Ventilador::setGrado2(float grado2){
	this->grado2 = grado2;
};

void Ventilador::setGrado3(float grado3){
	this->grado3 = grado3;
};

void Ventilador::setGlEnumPolygon(GLenum elem){ 
	cubo.setGlEnumPolygon(elem);
	cilindro.setGlEnumPolygon(elem);
};

void Ventilador::colorear(){
	cubo.colorear();
	cubo.colorearChess();
	cilindro.colorear();
	cilindro.colorearChess();
};

void Ventilador::setParchis(bool var){
	cubo.setChess(var);
	cilindro.setChess(var);
};

void Ventilador::crearBase(){
	glPushMatrix();
	glTranslatef(0,5,0);
	glScalef(1,0.1,1);
	cubo.dibujar();
	glPopMatrix();
};

void Ventilador::crearPalo(){
	glPushMatrix();
	glTranslatef(0,45,0);
	glScalef(0.1,0.7,0.1);
	cubo.dibujar();
	glPopMatrix();
};

void Ventilador::otroPalo(){
	glPushMatrix();
	glTranslatef(0,80-grado1*50,0);
	glScalef(0.1,0.0-grado1,0.1);
	cubo.dibujar();
	glPopMatrix();
};

void Ventilador::crearCabeza(){
	glPushMatrix();
	glTranslatef(0,110-(grado1*100),0);
	glScalef(0.5,1,0.2);
	cilindro.dibujar();
	glPopMatrix();
};

void Ventilador::crearAspa1(){
	glPushMatrix();
	glTranslatef(0,110-(grado1*100),20);
	glRotatef(90.0+grado3,0.0,0.0,1.0);
	glScalef(0.1,1,0.1);
	cubo.dibujar();
	glPopMatrix();
};

void Ventilador::crearAspa2(){
	glPushMatrix();
	glTranslatef(0,110-(grado1*100),20);
	glRotatef(0.0+grado3,0.0,0.0,1.0);
	glScalef(0.1,1,0.1);
	cubo.dibujar();
	glPopMatrix();
};


void Ventilador::dibujar(){
	//colorear();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
			crearBase();
			glPushMatrix();
				crearPalo();
				otroPalo();
			glPopMatrix();
			glPushMatrix();
				glRotatef(grado2,0.0,1.0,0.0);
				crearCabeza();
				glPushMatrix();
					crearAspa1();
					crearAspa2();
				glPopMatrix();		
			glPopMatrix();	
	glPopMatrix();
};




