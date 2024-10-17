#include "Grafo.h"
#include "GeneradorIdentificador.h"

using namespace URGGrafo;
using namespace URGGeneradorIdentificador;

Grafo* CrearGrafo(string nombre, int cantidadVertices, TipoGrafo tipo) {
    if (cantidadVertices < 0) {
        return nullptr;
    }
    Grafo* grafo = new Grafo;
    grafo->nombre = nombre;
    grafo->id = GenerarIdentificadorUnico();
    grafo->tipo = tipo;
    grafo->listaAdyacencia.resize(cantidadVertices);
    grafo->cantidadVertices = cantidadVertices;
    return grafo;
}

Grafo* CrearGrafoDirigido(string nombre, int cantidadVertices) {
    return CrearGrafo(nombre, cantidadVertices, DIRIGIDO);
}

Grafo* CrearGrafoNoDirigido(string nombre, int cantidadVertices) {
    return CrearGrafo(nombre, cantidadVertices, NODIRIGIDO);
}

string ObtenerNombre(const Grafo* grafo) {
    return grafo->nombre;
}

string ObtenerIdentificador(const Grafo* grafo) {
    return grafo->id;
}

void Conectar(Grafo* grafo, int verticeOrigen, int verticeDestino) {
    if (verticeOrigen >= 0 && verticeDestino >= 0 && 
        verticeOrigen < grafo->cantidadVertices && verticeDestino < grafo->cantidadVertices) {
        if (grafo->tipo == DIRIGIDO) {
            grafo->listaAdyacencia[verticeOrigen].push_back(verticeDestino);
        } else {
            grafo->listaAdyacencia[verticeOrigen].push_back(verticeDestino);
            grafo->listaAdyacencia[verticeDestino].push_back(verticeOrigen);
        }
    }
}

bool SonAdyacentes(const Grafo* grafo, int verticeOrigen, int verticeDestino) {
    if (verticeOrigen >= 0 && verticeOrigen < grafo->cantidadVertices &&
        verticeDestino >= 0 && verticeDestino < grafo->cantidadVertices) {
        for (int vertice : grafo->listaAdyacencia[verticeOrigen]) {
            if (vertice == verticeDestino) {
                return true;
            }
        }
    }
    return false;
}

string ObtenerVertices(const Grafo* grafo) {
    std::stringstream verticesStream;
    for (int vertice = 0; vertice < grafo->cantidadVertices; vertice++) {
        verticesStream << vertice;
        if (vertice < grafo->cantidadVertices - 1) {
            verticesStream << ",";
        }
    }
    return verticesStream.str();
}

string ObtenerAristas(const Grafo* grafo) {
    if (grafo == nullptr) {
        return "";
    }

    std::stringstream aristasStream;
    vector<vector<bool>> aristaVisitada(grafo->cantidadVertices, vector<bool>(grafo->cantidadVertices, false));

    for (int verticeOrigen = 0; verticeOrigen < grafo->cantidadVertices; ++verticeOrigen) {
        for (int verticeDestino : grafo->listaAdyacencia[verticeOrigen]) {
            if (grafo->tipo == DIRIGIDO) {
                aristasStream << verticeOrigen << "-" << verticeDestino << " ";
            } else {
                if (!aristaVisitada[verticeOrigen][verticeDestino]) {
                    aristasStream << verticeOrigen << "-" << verticeDestino << " ";
                    aristaVisitada[verticeOrigen][verticeDestino] = true;
                    aristaVisitada[verticeDestino][verticeOrigen] = true;
                }
            }
        }
    }

    return aristasStream.str();
}

void DestruirGrafo(Grafo* grafo) {
    if (grafo == nullptr) {
        return;
    }
    grafo->listaAdyacencia.clear();
    delete grafo;
}
