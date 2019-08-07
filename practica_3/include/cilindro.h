/****************************************************************
*	Practica 3  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código del cilindro
*
****************************************************************/
#ifndef _CILINDRO_H_
#define _CILINDRO_H_
#include <iostream>
#include "vertex.h"
#include "objeto_ply.h"

/**
* Clase para crear un objeto revolucionado a partir de un fichero ply 
*/

class Cilindro : public ObjetoPly
{
private:

public:
	Cilindro();
	_vertex3f revEjeZ(_vertex3f vertice, float angulo);
	void revolucionarDesdePerfilAnterior();
	void close();
	void read();
};
#endif