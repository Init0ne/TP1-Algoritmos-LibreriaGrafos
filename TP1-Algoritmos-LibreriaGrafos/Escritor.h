#ifndef ESCRITOR_H_
#define ESCRITOR_H_

#include <string>
#include <fstream>
#include <iostream>
using std::string;

namespace URGEscritor {

    enum TipoEscritor { ARCHIVO, CONSOLA };

    struct Escritor {
        TipoEscritor tipo;
        std::ofstream archivo;
    };

    Escritor* CrearEscritorArchivo(string nombreArchivo);
    Escritor* CrearEscritorConsola();
    void Escribir(Escritor* escritor, string texto);
    void Destruir(Escritor* escritor);

}

#endif
