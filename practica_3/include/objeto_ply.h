/****************************************************************
*	Practica 2  Informática Gráfica
*
*	Grado en Ingeniería Informática
*
*	2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
*	Código del objeto_ply
*
****************************************************************/
#ifndef _OBJETO_PLY_H_
#define _OBJETO_PLY_H_
#include "objeto3D.h"
#include <iostream>
#include "file_ply_stl.h"
#include "vertex.h"

/**
* Clase para gestionar los ficheros ply
*/

class ObjetoPly : public Objeto3D
{
private:
	_file_ply File_ply;
public:
	ObjetoPly();
	void leerFichero(const string &File_name);
	void closeFile();

};
#endif
