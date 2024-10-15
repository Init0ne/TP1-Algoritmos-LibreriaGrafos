#ifndef GENERADORIDENTIFICADOR_H_
#define GENERADORIDENTIFICADOR_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::string;

namespace URGGeneradorIdentificador{
    /*
     * Precondicion: -
     * Postcondicion: Devuelve un string unico que tiene el siguiente formato
     * ########-####-####-########
     * Donde # puede ser
     * - cualquier caracter del alfabeto espa�ol en minuscula
     * - cualquier numero del 0 al 9
     * donde cada valor del identificador debe tener una probabilidad uniforme de aparecer.
     */
    string GenerarIdentificadorUnico();

	string GenerarIdentificadorUnico(){
		const char caracteres[] = "abcdefghijklmnopqrstuvwxyz0123456789";
		int longitud = sizeof(caracteres) - 1; 
		std::string id_formato = "########-####-####-########";
		std::string identificador;

		srand(time(0));

		for (int i= 0; i<id_formato.length(); i++){
			 if (id_formato[i] == '#') {
				identificador += caracteres[rand() % longitud];
			}else{
				identificador += id_formato[i];
			}
		
		}

		return identificador;  

		
		    std::string id = GenerarIdentificadorUnico();
    		std::cout << "Identificador generado: " << id << std::endl;
	}
}

#endif