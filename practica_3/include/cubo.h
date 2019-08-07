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
#ifndef _CUBO_H
#define _CUBO_H
#include "objeto3D.h"

class Cubo : public Objeto3D
{
	private:
		float tam;
	public:
		Cubo();
		Cubo(float val);
		void createArrayData();
		void setTam(float data){ tam = data; };
};
#endif
