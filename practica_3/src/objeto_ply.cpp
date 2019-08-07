/****************************************************************
* Practica 2  Informática Gráfica
*
* Grado en Ingeniería Informática
*
* 2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
* Código del objeto_ply
*
****************************************************************/
#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/objeto_ply.h"
#include <vector>
#include <iostream>

using namespace std;

/**
* Constructor
*/
ObjetoPly::ObjetoPly(){

}

/**
* Lee un fichero PLY y carga la información en los vectores de Objeto3D
*/
void ObjetoPly::leerFichero(const string &File_name){
  if (File_ply.open(File_name)){
  	vector<_vertex3f> auxvertices;
    vector<_vertex3i> auxindices;

    File_ply.read(Objeto3D::getVertices(),Objeto3D::getIndices());
    cout << "auxvertices" << auxvertices.size() << endl;
    for(int i=0;i<Objeto3D::getVertices().size();i++){
        Objeto3D::getVertices()[i].x = 15*Objeto3D::getVertices()[i].x;
        Objeto3D::getVertices()[i].y = 15*Objeto3D::getVertices()[i].y;
        Objeto3D::getVertices()[i].z = 15*Objeto3D::getVertices()[i].z;
    }
    std::cout << "File read correctly" << getVertices().size() << std::endl;
    Objeto3D::colorear();
  }
  else std::cout << "File can't be opened" << std::endl;
}


/**
* Cierra un fichero PLY
*/
void ObjetoPly::closeFile(){
  File_ply.close();
}


