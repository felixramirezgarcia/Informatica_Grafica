/****************************************************************
* Practica 2  Informática Gráfica
*
* Grado en Ingeniería Informática
*
* 2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
* Código del cilindro
*
****************************************************************/
#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/cilindro.h"
#include <vector>
#include <iostream>

using namespace std;

/**
* Constructor
*/
Cilindro::Cilindro(){
    read();
    revolucionarDesdePerfilAnterior();
}


/**
 * Pasado un vertice _vertex3f devuelve otro que le corresponde en un barrido por revolución en el eje Z 
**/
_vertex3f Cilindro::revEjeZ(_vertex3f vertice, float angulo){
    //cout << vertice.x << endl;
    _vertex3f auxvert;
    auxvert.x = cos(angulo) * vertice.x - sin(angulo) * vertice.y;
    auxvert.y = sin(angulo) * vertice.x + cos(angulo) * vertice.y;
    auxvert.z = vertice.z; 
    //cout << auxvert.x;
    return auxvert;
}

/**
* Lee un fichero PLY y carga la información en los vectores de Objeto3D
*/
void Cilindro::revolucionarDesdePerfilAnterior(){
  float divisiones = 30.0;
  int size = Objeto3D::getVertices().size();
  float circunferenciaRadianes = 2.0 * M_PI ;
  float angulo = circunferenciaRadianes / divisiones;

  for(unsigned int ciclo = 0; ciclo < divisiones; ciclo++){
    vector<_vertex3f> sig_perfil;
    unsigned int perfilInicio, perfilFinal;

    perfilInicio = ciclo * size;
    perfilFinal = perfilInicio + size;
    for(int i = perfilInicio; i < perfilFinal; i++)
      //rellenar el siguiente perfil con los puntos rotados
      sig_perfil.push_back(revEjeZ(Objeto3D::getVertice(i),angulo));
    Objeto3D::getVertices().insert(Objeto3D::getVertices().end(),sig_perfil.begin(),sig_perfil.end());  //insertar siguiente perfil
    sig_perfil.clear();
    // Pintar los triangulos mapeando en el array las posiciones
    for (unsigned int i = perfilInicio+1, k = perfilFinal+1; i < perfilFinal; i++, k++){
      Objeto3D::setIndice(_vertex3i(i-1,k-1,k));
      Objeto3D::setIndice(_vertex3i(i-1,k,i));
    }
  } 
      
      // tapa de abajo
      // Agregamos el punto central, aunque no es necesario porque solo pintamos las caras
      _vertex3f puntoCentralAbajo(Objeto3D::getVertices().front().x/25 ,0.0, Objeto3D::getVertices().front().z);
      Objeto3D::setVertice(puntoCentralAbajo);
      int puntoComunAbajo = Objeto3D::getVertices().size()-1;
      for (unsigned int ciclo = 0; ciclo < divisiones; ciclo++)
      {
          int perfilInicio = ciclo * size;
          int siguientePerfil = perfilInicio + size;
          Objeto3D::setIndice(_vertex3i(puntoComunAbajo, siguientePerfil, perfilInicio));

      }

      // tapa de arriba
      // Agregamos el punto central, aunque no es necesario porque solo pintamos las caras
      _vertex3f puntoCentralArriba(Objeto3D::getVertice(size-1).x/25 , 0.0 , Objeto3D::getVertice(size-1).z);
      Objeto3D::setVertice(puntoCentralArriba);
      int puntoComunArriba = Objeto3D::getVertices().size()-1;
      for (unsigned int ciclo = 0; ciclo < divisiones; ciclo++)
      {
          int perfilInicio = (ciclo+1) * size-1;
          int siguientePerfil = perfilInicio + size;
          Objeto3D::setIndice(_vertex3i(puntoComunArriba, perfilInicio , siguientePerfil));
      }
      
}

/**
* Lee un fichero PLY y carga la información en los vectores 
*/
void Cilindro::read(){
  const string path1 = "./ply/cilindro.ply";
  ObjetoPly::leerFichero(path1);
}

/**
* Destructor
*/
void Cilindro::close(){
  ObjetoPly::closeFile();
}


