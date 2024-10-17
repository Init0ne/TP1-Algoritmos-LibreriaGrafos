#include "Grafo.h"
#include "GeneradorIdentificador.h"

using namespace URGGeneradorIdentificador;

namespace URGGrafo {
	struct Grafo {
		string id;
		string nombre;
		int cantidadVertices = 0;
		vector<list<int>> listaAdyacencia;
		TipoGrafo tipo = DIRIGIDO;
	};
	/*
	* Precondicion: -
	* Postcondicion: Si @cantidad de vertices es un numero mayor o igual que cero
	* devuelve un grafo dirigido de nombre @nombre al cual se le asocia un identificador unico.
	* Si @cantidad de vertices es menor que cero devueleve NULL
	*/
	Grafo* CrearGrafoDirigido(string nombre, int cantidadVertices) {
		if (cantidadVertices < 0) {
			return nullptr;
		}
		else {
			Grafo* grafo = new Grafo;
			grafo->nombre = nombre;
			grafo->id = GenerarIdentificadorUnico();
			grafo->tipo = DIRIGIDO;
			grafo->listaAdyacencia.resize(cantidadVertices);
			return grafo;
		}
	}

	/*
	* Precondicion: -
	* Postcondicion: Si @cantidad de vertices es un numero mayor o igual que cero
	* devuelve un grafo no dirigido de nombre @nombre al cual se le asocia un identificador unico.
	* Si @cantidad de vertices es menor que cero devuelve NULL
	*/
	Grafo* CrearGrafoNoDirigido(string nombre, int cantidadVertices) {
		if (cantidadVertices < 0) {
			return nullptr;
		}
		else {
			Grafo* grafo = new Grafo;
			grafo->nombre = nombre;
			grafo->id = GenerarIdentificadorUnico();
			grafo->tipo = NODIRIGIDO;
			grafo->listaAdyacencia.resize(cantidadVertices);
			return grafo;
		}
	}

	/*
	* Precondicion: @grafo es una instancia valida creada con alguna de las primitivas creacionales
	* Postcondicion: Devuelve el nombre de @grafo
	*/
	string ObtenerNombre(const Grafo* grafo) {
		return grafo->nombre;
	}

	/*
	* Precondicion: @grafo es una instancia valida creada con alguna de las primitivas creacionales
	* Postcondicion: Devuelve el identificador unico de @grafo
	*/
	string ObtenerIdentificador(const Grafo* grafo) {
		return grafo->id;
	}

	/*
	* Precondicion: @grafo es una instancia valida creada con alguna de las primitivas creacionales
	* Postcondicion: Si @grafo es un grafo no dirigido, se agrega una relacion de adyacencia conmutativa entre @verticeOrigen y @verticeDestino (@verticeOrigen es adyacente a @verticeDestino y viceversa).
	* Si @grafo es un grafo dirigido, se agrega una relacion de adyacencia de @verticeOrigen y @verticeDestino (@verticeOrigen es adyacente a @vertice destino)
	* Si @verticeOrigen o @verticeDestino no pertenece al grafo no realiza ninguna accion
	*/
	void Conectar(Grafo* grafo, int verticeOrigen, int verticeDestino) {
		if (verticeOrigen >= 0 && verticeDestino >= 0 &&
			verticeOrigen < grafo->cantidadVertices && verticeDestino < grafo->cantidadVertices) {
			if (grafo->tipo == DIRIGIDO) {
				grafo->listaAdyacencia[verticeOrigen].push_back(verticeDestino);
			}
			else {
				grafo->listaAdyacencia[verticeOrigen].push_back(verticeDestino);
				grafo->listaAdyacencia[verticeDestino].push_back(verticeOrigen);
			}
		}
	}

	/*
	* Precondicion: @grafo es una instancia valida creada con alguna de las primitivas creacionales
	* Postcondicion: Devuelve true si @verticeOrigen es adyacente a @verticeDestino. Caso contrario devuelve false
	*/
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

	/*
	* Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
	* Postcondiciones: Devuelve los vertices en un registro en formato CSV donde cada campo es un vertice
	*/
	string ObtenerVertices(const Grafo* grafo) {
		if (grafo == nullptr || grafo->cantidadVertices == 0) {
			return "";
		}

		string resultado;
		for (int i = 0; i < grafo->cantidadVertices; ++i) {
			resultado += std::to_string(i);
			if (i < grafo->cantidadVertices - 1) {
				resultado += ",";
			}
		}
		return resultado;
	}

	/*
	* Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
	* Postcondiciones: Devuelve las aristas en formato de etiquetas.
	* El formato de etiquetas para un grafo no dirigido es el siguiente: 1-4 2-3 0-1
	* Donde nos dice que el conjunto E del grafo es: {(1,4), (2,3), (0,1)}
	* El formato de etiquetas para un grafo dirigido es el siguiente: 1-4 2-3 4-1
	* Donde nos dice que el conjunto E del grafo es: {(1,4), (2,3), (0,1), (4,1)}
	*
	* Vemos que en ambos casos son las adyacencias separadas por espacio.
	* Para el caso de los grafos no dirigidos no hay que duplicar las relaciones conmutativas
	*/
	string ObtenerAristas(const Grafo* grafo) {
		if (grafo == nullptr || grafo->cantidadVertices == 0) {
			return "";
		}

		string resultado;
		vector<vector<bool>> visitado(grafo->cantidadVertices, vector<bool>(grafo->cantidadVertices, false));

		for (int i = 0; i < grafo->cantidadVertices; ++i) {
			for (int vecino : grafo->listaAdyacencia[i]) {
				if (grafo->tipo == DIRIGIDO) {
					resultado += std::to_string(i) + "-" + std::to_string(vecino) + " ";
				}
				else {
					if (!visitado[i][vecino]) {
						resultado += std::to_string(i) + "-" + std::to_string(vecino) + " ";
						visitado[i][vecino] = visitado[vecino][i] = true;
					}
				}
			}
		}

		// Eliminar el espacio final si existe
		if (!resultado.empty() && resultado.back() == ' ') {
			resultado.pop_back();
		}

		return resultado;
	}

	/*
	* Precondiciones: @grafo es una instancia valida creada con alguna de las primitivas creacionales
	* Postcondiciones: Libera todos los recursos asociados a @grafo
	*/
	void DestruirGrafo(Grafo* grafo) {
		if (grafo == nullptr) {
			return;
		}
		grafo->listaAdyacencia.clear();
		delete grafo;
	}
}