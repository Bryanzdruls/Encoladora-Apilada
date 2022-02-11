#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <wchar.h>
#include"pila.h"
#include"Cola.h"
//LISTA DOBLEMENTE LIGADA CIRCULAR.

using namespace std;
void menuPilas();
void menuColas();
void menuPrincipal();

int main()
{
	int opt = 0, optP=0, optC=0, dato = 0, n = 0, m = 0;
	setlocale(LC_ALL, "");
	cout << "Ingrese el tamaño de la pila" << endl;
	cin >> n;
	cout << "Ingrese el tamaño de la cola" << endl;
	cin >> m;
	//Instancia.

	pila_lista* p= new pila_lista(n);
	cola* c = new cola(m);
	cola* cSuma;
	
	do
	{
		menuPrincipal();
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "Usted ha escogido trabajar sobre pilas";
			cin.get();
			do
			{
				menuPilas();
				cin >> optP;
				switch (optP)
				{
				case 1:// Apilar.
					if (!p->pilaLlena())
					{
						cout << "Ingrese un dato: " << endl;
						cin >> dato;
						p->apilar(dato);
					}
					else
					{
						cout << "La pila esta llena." << endl;
						cin.get();
					}
					break;
				case 2://Desapilar.			
					if (!p->pilaVacia())
					{
						cout << "Se desapilo el ultimo dato: " << p->desapilar() << endl;
				
					}
					else
					{
						cout << "La pila esta vacia." << endl;
					}
					cin.get();
					break;
				case 3://Ordenar Pila.
					if (!p->pilaVacia())
					{
						p->ordenarPila();
						
						cin.get();
					}
					else
					{
						cout << "No hay ningun dato" << endl;
						cin.get();
					}
					break;
				case 4://Mostrar pila.
					if (!p->pilaVacia())
					{
						p->mostrarPila();
						cin.get();
					}
					else
					{
						cout << "No hay ningun dato" << endl;
						cin.get();
					}
					break;
				case 5://Apilar Ordenado
					if (!p->pilaLlena())
					{
						cout << "Ingrese el dato: " << endl;
						cin >> dato;
						p->apilarOrdenado(dato);
					}
					else
					{
						cout << "La pila esta llena." << endl;
						cin.get();
					}
					break;
				case 6://Salir
					cout << "Gracias por utilizar nuestro programa." << endl;
					break;
				default:
					break;
				}
				cin.get();
				system("cls");
			} while (optP != 6);
			break;
		case 2:
			cout << "Usted ha escogido trabajar sobre colas";
			cin.get();
			do
			{
				menuColas();
				cin >> optC;
				switch (optC)
				{
				case 1://Encolar.					
					if (!c->ColaLlena())
					{
						cout << "Ingrese un dato: " << endl;
						cin >> dato;
						c->encolar(dato);
						cout << "El dato se ha encolado correctamente." << endl;
					}
					else
					{
						cout << "La cola esta llena." << endl;
						cin.get();
					}
					break;
				case 2://Desencolar.
					if (!c->ColaVacia())
					{
						cout << "El dato: " << c->desencolar() << " se ha desencolado correctamente." << endl;
					}
					else
					{
						cout << "La cola esta vacia." << endl;
						cin.get();
					}
					break;
				case 3://Ordenar Cola
					if (!c->ColaVacia())
					{
						c->ordenarCola();
						cin.get();
					}
					else
					{
						cout << "No hay datos en la pila." << endl;
					}
					break;
				case 4://Mostrar cola.
					if (!c->ColaVacia())
					{
						c->MostrarCola();
						cin.get();
					}
					else
					{
						cout << "No hay ningun dato" << endl;
						cin.get();
					}
					break;
				case 5://Encolar ordenado.
					if (!c->ColaLlena())
					{
						cout << "Ingrese el dato: " << endl;
						cin >> dato;
						c->encolarOrdenado(dato);
					}
					else
					{
						cout << "La pila esta llena." << endl;
						cin.get();
					}
					break;
				case 6:
					cout << "Gracias por utilizar nuestro programa." << endl;
					break;
				default:
					break;
				}
				cin.get();
				system("cls");
			} while (optC != 6);
			break;
		case 3:
			if (n<m)
			{
				cSuma = new cola(m);
				
			}
			else
			{
				cSuma = new cola(n);
			}
			exit(1);
			break;
		case 4:
			cout << "Gracias por utilizar mi programa." << endl;
			exit(1);
			break;
		default:
			cout << "Opcion incorrecta." << endl;
			cin.get();
			break;
		}
	} while (opt != 3);
}

void menuPilas()
{
	cout << "\n \t Pilas y colas.\n\n";
	cout << "\n \t Menu trabajo\n\n";
	cout << "1. Apilar. " << endl;
	cout << "2. Desapilar. " << endl;
	cout << "3. Ordenar Pila" << endl;
	cout << "4. Mostrar pila. " << endl;
	cout << "5. Apilar Ordenado" << endl;
	cout << "6. salir" << endl;

	cout << "\tIngresar opcion.\n";
}
void menuColas()
{
	cout << "\n \t Pilas y colas.\n\n";
	cout << "\n \t Menu trabajo\n\n";
	cout << "1. Encolar " << endl;
	cout << "2. Desencolar. " << endl;
	cout << "3. Ordenar Cola" << endl;
	cout << "4. Mostrar Cola." << endl;
	cout << "5. Encolar Ordenado" << endl;
	cout << "6. salir" << endl;

	cout << "\tIngresar opcion.\n";
}

void menuPrincipal()
{
	cout << "\n \t Pilas y colas.\n\n";
	cout << "\n \t Menu Principal.\n\n";
	cout << "1. Trabajar Pilas. " << endl;
	cout << "2. Trabajar Colas" << endl;
	cout << "3. Sumar Pilas y colas." << endl;
	cout << "4. Salir." << endl;
}