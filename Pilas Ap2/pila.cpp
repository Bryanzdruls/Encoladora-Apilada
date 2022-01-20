#include "pila.h"
#include<iostream>
using namespace std;
pila::pila(int n)
{
	limite = n;
	tope = -1;
	vec = new int[n];
};
void pila::apilar(int dato)
{
	tope++;
	vec[tope] = dato;
}

int pila::desapilar()
{
	int r= vec[tope];
	tope--;
	return r;
}

bool pila::pilaVacia()
{
	bool r= false;
	if (tope == -1)
	{
		r = true;
	}
	return r;
}

bool pila::pilaLlena()
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
	pila * aux= NULL;
	while (pilaVacia() == false)
	{
		r = desapilar();
		cout << "dato:"<<r<< endl;
		aux->apilar(r);
	}
	llenarPila(aux);
}
