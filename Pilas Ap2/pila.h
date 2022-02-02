#pragma once
#include "Nodo.h"
class pila_lista	
{
private:
	//Atributos.
	Nodo* punta;
	int limite, tope;

	//Metodos.
public:
	pila_lista(int);//Constructor.
	void apilar(int);//Set.
	void apilarOrdenado(int);
	int desapilar(); //Get.
	bool pilaVacia();
	bool pilaLlena();
	void llenarPila(pila_lista*);//Pasar datos, de pila llena a pila vacia.
	void insertarInicio(int);
	void invertirPila();
	void mostrarPila();
	void sumarPilas(pila_lista*, pila_lista*);
	void ordenarPilas();
	

};

