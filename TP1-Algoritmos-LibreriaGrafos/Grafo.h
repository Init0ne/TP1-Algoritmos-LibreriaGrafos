#ifndef GRAFO_H_
#define GRAFO_H_

#include <sstream>
#include <string>
#include <list>
#include <vector>
#include "GeneradorIdentificador.h"
using std::string;
using std::vector;
using std::list;

enum TipoGrafo { DIRIGIDO, NODIRIGIDO };

namespace URGGrafo {

    struct Grafo;

    Grafo* CrearGrafoDirigido(string nombre, int cantidadVertices);
    Grafo* CrearGrafoNoDirigido(string nombre, int cantidadVertices);
    string ObtenerNombre(const Grafo* grafo);
    string ObtenerIdentificador(const Grafo* grafo);
    void Conectar(Grafo* grafo, int verticeOrigen, int verticeDestino);
    bool SonAdyacentes(const Grafo* grafo, int verticeOrigen, int verticeDestino);
    string ObtenerVertices(const Grafo* grafo);
    string ObtenerAristas(const Grafo* grafo);
    void DestruirGrafo(Grafo* grafo);

}

#endif