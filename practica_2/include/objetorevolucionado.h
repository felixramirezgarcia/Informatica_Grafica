/****************************************************************
*	Practica 2  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código del objeto_revolucionado
*
****************************************************************/
#ifndef _REVOLUCION_H_
#define _REVOLUCION_H_
#include <iostream>
#include "vertex.h"
#include "objeto_ply.h"

/**
* Clase para crear un objeto revolucionado a partir de un fichero ply 
*/

class ObjetoRevolucionado : public ObjetoPly
{
private:

public:
	bool tapas;
	ObjetoRevolucionado();
	_vertex3f revEjeY(_vertex3f vertice, float angulo);
	void changeTapas();
	void revolucionarDesdePerfilAnterior();
	void revolucionarDesdePerfilInicial();
	void close();
	void read(const string & path);
};
#endif