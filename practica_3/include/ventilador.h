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
#ifndef _VENTILADOR_H
#define _VENTILADOR_H
#include "objeto3D.h"
#include "cubo.h"
#include "cilindro.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>

class Ventilador : public Objeto3D{

private:
	float grado1 ;
	float grado2 ;
	float grado3 ;
	Cubo cubo;
	Cilindro cilindro;
public:
	Ventilador();
	void setGrado1(float grado1);
	void setGrado2(float grado2);
	void setGrado3(float grado3);
	void dibujar();
	void crearBase();
	void crearPalo();
	void otroPalo();
	void crearAspa1();
	void crearAspa2();
	void crearCabeza();
	void setGlEnumPolygon(GLenum elem);
	void colorear();
	void setParchis(bool var);
};
#endif