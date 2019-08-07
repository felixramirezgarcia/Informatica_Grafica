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
#ifndef _PIRAMIDE_H
#define _PIRAMIDE_H
#include "objeto3D.h"

class Piramide : public Objeto3D
{
	public:
		Piramide();
		Piramide(int tam);
		void createArrayData(int tam);
};
#endif