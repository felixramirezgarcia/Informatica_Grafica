/****************************************************************
* Practica 2  Informática Gráfica
*
* Grado en Ingeniería Informática
*
* 2017 - Félix Ramírez García <felixramirezgarcia@correo.ugr.es>
*
* Código del objeto_revolucionado
*
****************************************************************/
#ifdef _WIN32
#include <windows.h>
#endif
#include "../include/objetorevolucionado.h"
#include <vector>
#include <iostream>


using namespace std;

/**
* Constructor
*/
ObjetoRevolucionado::ObjetoRevolucionado(){
    tapas=true;
    hacerHueco=0;
}

void ObjetoRevolucionado::changeTapas(){
  if(tapas==true){
    tapas=false;
  }else if(tapas == false){
    tapas=true;
  }
}


void ObjetoRevolucionado::setHueco(){
  hacerHueco++;
}

/**
 * Pasado un vertice _vertex3f devuelve otro que le corresponde en un barrido por revolución en el eje Y 
**/
_vertex3f ObjetoRevolucionado::revEjeY(_vertex3f vertice, float angulo){
    //cout << vertice.x << endl;
    _vertex3f auxvert;
    auxvert.x = cos(angulo) * vertice.x + sin(angulo) * vertice.z;
    auxvert.y = vertice.y;
    auxvert.z = -sin(angulo) * vertice.x + cos(angulo) * vertice.z;
    //cout << auxvert.x;
    return auxvert;
}

/**
* Lee un fichero PLY y carga la información en los vectores de Objeto3D
*/
void ObjetoRevolucionado::revolucionarDesdePerfilAnterior(){
  float divisiones = 30.0;
  int size = Objeto3D::getVertices().size();
  float circunferenciaRadianes = 2.0 * M_PI ;
  float angulo = circunferenciaRadianes / divisiones;

  for(unsigned int ciclo = 0; ciclo < divisiones; ciclo++){
    vector<_vertex3f> sig_perfil;
    unsigned int perfilInicio, perfilFinal;

    perfilInicio = ciclo * size;
    perfilFinal = perfilInicio + size;
    for(int i = perfilInicio; i < perfilFinal; i++){
      //rellenar el siguiente perfil con los puntos rotados
      sig_perfil.push_back(revEjeY(Objeto3D::getVertice(i),angulo));
    }
    Objeto3D::getVertices().insert(Objeto3D::getVertices().end(),sig_perfil.begin(),sig_perfil.end());  //insertar siguiente perfil
    sig_perfil.clear();

    // Pintar los triangulos mapeando en el array las posiciones
    for (unsigned int i = perfilInicio+1, k = perfilFinal+1; i < perfilFinal; i++, k++){
      Objeto3D::setIndice(_vertex3i(i-1,k-1,k));
      Objeto3D::setIndice(_vertex3i(i-1,k,i));
    }
  } 

  	//codigo del examen de la practica 2
    /*for (int i = 0; i < hacerHueco; ++i)
    {
    	Objeto3D::getVertices().erase(Objeto3D::getVertices().begin(),Objeto3D::getVertices().begin()+size);
  		Objeto3D::getIndices().erase(Objeto3D::getIndices().begin(),Objeto3D::getIndices().begin()+((size)*2));
  		Objeto3D::getIndices().erase(Objeto3D::getIndices().end()-((size-1)*2),Objeto3D::getIndices().end());
    }*/
    	
  	
  	
      if(tapas == true){
      // tapa de abajo
      // Agregamos el punto central, aunque no es necesario porque solo pintamos las caras
      _vertex3f puntoCentralAbajo(0.0, Objeto3D::getVertices().front().y , 0.0);
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
      _vertex3f puntoCentralArriba(0.0, Objeto3D::getVertice(size-1).y , 0.0);
      Objeto3D::setVertice(puntoCentralArriba);
      int puntoComunArriba = Objeto3D::getVertices().size()-1;
      for (unsigned int ciclo = 0; ciclo < divisiones; ciclo++)
      {
          int perfilInicio = (ciclo+1) * size-1;
          int siguientePerfil = perfilInicio + size;
          Objeto3D::setIndice(_vertex3i(puntoComunArriba, perfilInicio , siguientePerfil));
      }
      }
}




void ObjetoRevolucionado::revolucionarDesdePerfilInicial(){
  float divisiones = 100.0;
  int size = Objeto3D::getVertices().size();
  float circunferenciaRadianes = 2.0 * M_PI ;
  float angulo = circunferenciaRadianes / divisiones;
  float angulonuevo = angulo;
  int i = 1;
  for(unsigned int ciclo = 0; ciclo < divisiones; ciclo++){
    vector<_vertex3f> sig_perfil;
    unsigned int perfilInicio, perfilFinal;

    perfilInicio = ciclo * size;
    perfilFinal = perfilInicio + size;
    for(int i = 0; i < size; i++){
      //rellenar el siguiente perfil con los puntos rotados
      sig_perfil.push_back(revEjeY(Objeto3D::getVertice(i),angulonuevo));
    }
    //Aumento el angulo 
    angulonuevo = angulonuevo * i;
    i++ ;
    Objeto3D::getVertices().insert(Objeto3D::getVertices().end(),sig_perfil.begin(),sig_perfil.end());  //insertar siguiente perfil
    sig_perfil.clear();
    // Pintar los triangulos mapeando en el array las posiciones
    for (unsigned int i = perfilInicio+1, k = perfilFinal+1; i < perfilFinal; i++, k++){
      Objeto3D::setIndice(_vertex3i(i-1,k-1,k));
      Objeto3D::setIndice(_vertex3i(i-1,k,i));
    }
  }
  if(tapas == true){
      // tapa de abajo
      // Agregamos el punto central, aunque no es necesario porque solo pintamos las caras
      _vertex3f puntoCentralAbajo(0.0, Objeto3D::getVertices().front().y , 0.0);
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
      _vertex3f puntoCentralArriba(0.0, Objeto3D::getVertice(size-1).y , 0.0);
      Objeto3D::setVertice(puntoCentralArriba);
      int puntoComunArriba = Objeto3D::getVertices().size()-1;
      for (unsigned int ciclo = 0; ciclo < divisiones; ciclo++)
      {
          int perfilInicio = (ciclo+1) * size-1;
          int siguientePerfil = perfilInicio + size;
          Objeto3D::setIndice(_vertex3i(puntoComunArriba, siguientePerfil, perfilInicio));
      }
      }
}


/**
* Lee un fichero PLY y carga la información en los vectores 
*/
void ObjetoRevolucionado::read(const string & path){
  ObjetoPly::leerFichero(path);
}

/**
* Destructor
*/
void ObjetoRevolucionado::close(){
  ObjetoPly::closeFile();
}