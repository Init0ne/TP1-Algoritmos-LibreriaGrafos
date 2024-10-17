// archivo GeneradorIdentificador.cpp
#include "GeneradorIdentificador.h"
#include <cstdlib>
#include <ctime>

namespace URGGeneradorIdentificador {
    string GenerarIdentificadorUnico() {
        const char caracteres[] = "abcdefghijklmnopqrstuvwxyz0123456789";
        int longitud = sizeof(caracteres) - 1;
        std::string id_formato = "########-####-####-########";
        std::string identificador;

        for (unsigned int i = 0; i < id_formato.length(); i++) {
            if (id_formato[i] == '#') {
                identificador += caracteres[rand() % longitud];
            } else {
                identificador += id_formato[i];
            }
        }

        return identificador;
    }
}
