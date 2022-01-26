#include "pila.h"
#include<iostream>
using namespace std;
pila::pila(int n)
{
	limite = n-1;
	tope = -1;
	vec = new int[n];
};

void pila::apilar(int dato)//Similar al Set.
{
	tope++;
	vec[tope] = dato;
}

int pila::desapilar()//Similar al Get.
{
	int r= vec[tope];
	tope--;
	return r;
}

bool pila::pilaVacia()//Validacion vacia.
{
	bool r= false;
	if (tope == -1)
	{
		r = true;
	}
	return r;
}

bool pila::pilaLlena()//Validacion llena(true = llena).
{
	if (tope == limite) 
	{
		return true;
	}
	else
	{
		return false;
	}	
}

void pila::llenarPila(pila* a)
{
	while(a->pilaVacia() == false)
	{
		apilar(a->desapilar());
	}
}

void pila::mostrarPila()
{
	int r= 0;
	pila * aux=new pila(limite);
	while (pilaVacia() == false)
	{
		r = desapilar(); //Se vacia la pila principal.
		cout << "Posición "<<tope+1<<": "<< r << endl;
		aux->apilar(r);
	}
	llenarPila(aux); //Se llena la pila auxiliar.
}
