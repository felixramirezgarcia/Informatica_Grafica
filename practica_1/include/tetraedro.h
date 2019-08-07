/****************************************************************
*	Practica 1  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código del tetraedro
*
****************************************************************/
#ifndef _TETRAEDRO_H
#define _TETRAEDRO_H
#include "objeto3D.h"

class Tetraedro : public Objeto3D
{
	public:
		Tetraedro();
		Tetraedro(int tam);
		void createArrayData(int tam);
};
#endif