#include "Escritor.h"

namespace URGEscritor {

    Escritor* CrearEscritorArchivo(string nombreArchivo) {
        Escritor* escritor = new Escritor;
        escritor->tipo = ARCHIVO;
        escritor->archivo.open(nombreArchivo);

        if (!escritor->archivo.is_open()) {
            delete escritor;
            return nullptr;
        }
        return escritor;
    }

    Escritor* CrearEscritorConsola() {
        Escritor* escritor = new Escritor;
        escritor->tipo = CONSOLA;
        return escritor;
    }

    void Escribir(Escritor* escritor, string texto) {
        if (escritor->tipo == CONSOLA) {
            std::cout << texto << std::endl;
        }
        else if (escritor->tipo == ARCHIVO) {
            escritor->archivo << texto << std::endl;
        }
    }

    void Destruir(Escritor* escritor) {
        if (escritor->tipo == ARCHIVO) {
            escritor->archivo.close();
        }
        delete escritor;
    }

}
