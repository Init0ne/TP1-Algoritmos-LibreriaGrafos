#include "GeneradorIdentificador.h"
#include "Escritor.h"
#include "Grafo.h"

using namespace URGEscritor;
using namespace URGGrafo;
using namespace URGGeneradorIdentificador;

void GenerarIdentificadores();
void ProbarGrafos();

void ImprimirGrafo(Grafo* grafo, Escritor* escritor);
void PersistirGrafos(Grafo *grafoA, Grafo * grafoB);

void CargarGrafoDirigido(Grafo* grafo);
void CargarGrafoNoDirigido(Grafo* grafo);

int main() {
	GenerarIdentificadores();
	ProbarGrafos();

	return 0;
}

void GenerarIdentificadores(){
	// Utilizamos el escritor en modo consola para mostrar
	// 10 identificadores unicos (deben ser unicos)
	Escritor* consola = CrearEscritorConsola();
	Escribir(consola, "Generando 10 identificadores unicos...");
	for(int i=0; i<10; i++){
		Escribir(consola, GenerarIdentificadorUnico());
	}
	Escribir(consola, "Fin");
	Destruir(consola);
}

void ProbarGrafos(){
	// Cargamos los grafos del enunciado. Luego los mostramos y los guardamos en archivos
	Grafo* grafoA = CrearGrafoNoDirigido("GrafoA", 6);
	Grafo* grafoB = CrearGrafoDirigido("GrafoB", 6);
    CargarGrafoNoDirigido(grafoA);
    CargarGrafoDirigido(grafoB);
    PersistirGrafos(grafoA, grafoB);
	DestruirGrafo(grafoA);
	DestruirGrafo(grafoB);
}

void CargarGrafoDirigido(Grafo* grafo){
	Conectar(grafo, 0,2);
	Conectar(grafo, 2,0);
	Conectar(grafo, 1,2);
	Conectar(grafo, 2,1);
	Conectar(grafo, 3,0);
	Conectar(grafo, 0,3);
	Conectar(grafo, 2,4);
	Conectar(grafo, 4,2);
	Conectar(grafo, 3,4);
	Conectar(grafo, 4,3);
}

void CargarGrafoNoDirigido(Grafo* grafo){
	Conectar(grafo, 0,2);
	Conectar(grafo, 1,2);
	Conectar(grafo, 3,0);
	Conectar(grafo, 2,4);
	Conectar(grafo, 3,4);
}

void ImprimirGrafo(Grafo* grafo, Escritor* escritor){
	string identificador = ObtenerIdentificador(grafo);
	string nombre = ObtenerNombre(grafo);
	Escribir(escritor, "#" + identificador);
	Escribir(escritor, "#" + nombre);
	Escribir(escritor, ObtenerVertices(grafo));
	Escribir(escritor, ObtenerAristas(grafo));
}

void PersistirGrafos(Grafo *grafoA, Grafo * grafoB)
{
    Escritor *consola = CrearEscritorConsola();
    Escritor *archivoGrafoA = CrearEscritorArchivo("grafoA.txt");
    Escritor *archivoGrafoB = CrearEscritorArchivo("grafoB.txt");
    Escribir(consola, "Mostrando los grafos A y B...");
    ImprimirGrafo(grafoA, consola);
    ImprimirGrafo(grafoB, consola);
    Escribir(consola, "Persistiendo los grafos en archivos");
    ImprimirGrafo(grafoA, archivoGrafoA);
    ImprimirGrafo(grafoB, archivoGrafoB);
    Destruir(consola);
    Destruir(archivoGrafoA);
    Destruir(archivoGrafoB);
}
