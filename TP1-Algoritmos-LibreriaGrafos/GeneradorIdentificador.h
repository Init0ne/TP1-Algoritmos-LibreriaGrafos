#ifndef GENERADORIDENTIFICADOR_H_
#define GENERADORIDENTIFICADOR_H_

#include <string>

using std::string;

namespace URGGeneradorIdentificador{
	/*
	 * Precondicion: -
	 * Postcondicion: Devuelve un string unico que tiene el siguiente formato
	 * ########-####-####-########
	 * Donde # puede ser
	 * - cualquier caracter del alfabeto español en minuscula
	 * - cualquier numero del 0 al 9
	 * donde cada valor del identificador debe tener una probabilidad uniforme de aparecer.
	 */
	string GenerarIdentificadorUnico();
}

#endif
