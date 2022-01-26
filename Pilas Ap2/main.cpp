#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <wchar.h>
#include"pila.h"
//LISTA DOBLEMENTE LIGADA CIRCULAR.

using namespace std;
void menuPilas();

int main()
{
	setlocale(LC_ALL, "");
	//Instancia.
	pila* p1;
	int opc = 0, dato = 0, n = 0;

	cout << "Ingrese el tamaño de la pila" << endl;
	cin >> n;
	p1 = new pila(n);
	do
	{
		menuPilas();
		cin >> opc;
		switch (opc)
		{
		case 1:// Apilar.
			cout << "Ingrese un dato: " << endl;
			cin >> dato;
			if (!p1->pilaLlena())
			{
				p1->apilar(dato);
			}
			else
			{
				cout << "La pila esta llena." << endl;
			}
			break;
		case 2://Desapilar.			
			if(!p1->pilaVacia())
			{
				p1->desapilar();
				cout << "Se desapilo el ultimo dato." << endl;
			}
			else
			{
				cout << "La pila esta vacia." << endl;
			}
			break;
		case 3://Pilallena
			
			if (p1->pilaLlena())
			{
				cout << "La pila esta llena." << endl;
			}
			else
			{
				cout << "la pila no esta llena." << endl;
			}
			break;
		case 4://Pilavacia
			if (p1->pilaVacia())
			{
				cout << "La pila esta vacia." << endl;
			}
			else
			{
				cout << "la pila no esta vacia." << endl;
			}
			break;
		case 5: // Mostrar pila.
			p1->mostrarPila();
			break;
		default:
			break;
		}
		cin.get();
		cin.get();
		system("cls");
	} while (opc != 6);

	return 0;
}

void menuPilas()
{
	cout << "\n \t Pilas\n\n";
	cout << "1. Apilar. " << endl;
	cout << "2. Desapilar. " << endl;
	cout << "3. Pila llena. " << endl;
	cout << "4. Pila Vacia. " << endl;
	cout << "5. Mostrar pila. " << endl;
	cout << "\t ¿Qué desea hacer?\n";
}