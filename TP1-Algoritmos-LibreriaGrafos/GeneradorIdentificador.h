#ifndef GENERADORIDENTIFICADOR_H_
#define GENERADORIDENTIFICADOR_H_
using namespace std;
#include<iostream>
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



char GenerarCaracterAleatorio(int indice){
	const char caracteres[]="abcdefghijklmnopqrstuvwxyz0123456789";
	return caracteres[indice % 36];
}


string GenerarIdentificadorUnico(){
	string identificador;
	int contadorCaracteres=0;

	for (int contadorPrimeros8Caracteres=0; contadorPrimeros8Caracteres<8; ++contadorPrimeros8Caracteres){
		identificador+=GenerarCaracterAleatorio(contadorCaracteres++);
	}
	identificador+='-';

	for (int contadorSiguientes4Caracteres1=0; contadorSiguientes4Caracteres1<4; ++contadorSiguientes4Caracteres1){
		identificador+=GenerarCaracterAleatorio(contadorCaracteres++);
	}
	identificador+='-';

	for (int contadorSiguientes4Caracteres2=0; contadorSiguientes4Caracteres2<4; ++contadorSiguientes4Caracteres2){
		identificador+=GenerarCaracterAleatorio(contadorCaracteres++);
	}
	identificador+='-';

	for(int contadorUltimos8Caracteres=0; contadorUltimos8Caracteres<8; ++contadorUltimos8Caracteres){
		identificador+=GenerarCaracterAleatorio(contadorCaracteres++);
	}
	
	return identificador;	
}
