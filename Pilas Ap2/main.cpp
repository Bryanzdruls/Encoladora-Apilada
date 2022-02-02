#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <wchar.h>
#include"pila.h"
//LISTA DOBLEMENTE LIGADA CIRCULAR.

using namespace std;
void menuPilas();
void menuPrincipal();
pila_lista* principal(int, pila_lista*, pila_lista*, pila_lista*);
int main()
{
	setlocale(LC_ALL, "");
	//Instancia.
	
	pila_lista* p;
	int opc = 0, dato = 0, n = 0;

	
	cout << "Ingrese el tamaño de la pila" << endl;
	cin >> n;
	pila_lista* p1 = new pila_lista(n);
	pila_lista* p2 = new pila_lista(n);
	pila_lista* p3 = new pila_lista(n);
	
	do
	{
		p = principal(n, p1, p2, p3);
		menuPilas();
		cin >> opc;
		switch (opc)
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
			if(!p->pilaVacia())
			{
				cout << "Se desapilo el ultimo dato: " <<p->desapilar()<< endl;
			}
			else
			{
				cout << "La pila esta vacia." << endl;
			}
			cin.get();
			break;
		case 3://Encolar.
			cin.get();
		
		case 4://Desencolar.
			cin.get();

			break;
		case 5: // Mostrar pila.
			if (!p->pilaVacia())
			{
				p->mostrarPila();
			}
			else
			{
				cout << "No hay ningun dato" << endl;
			}
			cin.get();
			break;
		case 6:
			cin.get();
			break;
		case 7://Invertir pila
			if (!p->pilaVacia())
			{
				p->invertirPila();
				cout << "La pila se ha invertido correctamente" << endl;
				cin.get();
			}
			else
			{
				cout << "No hay datos en la pila." << endl;
			}
			break;
		case 8:
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
		case 9:
			p = principal(n, p1, p2, p3);
			break;
		default:
			break;
		}
		cin.get();
		system("cls");
	} while (opc != 10);

	return 0;
}

pila_lista* principal(int tam, pila_lista* pila1, pila_lista* pila2, pila_lista* pila3)
{
	int opt;
	
	menuPrincipal();
	do
	{
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "Usted ha escogido trabajar sobre la pila 1.";
			cin.get();
			return pila1;
			break;
		case 2:
			cout << "Usted ha escogido trabajar sobre la pila 2.";
			cin.get();
			return pila2;
			break;
		case 3:
			pila3->sumarPilas(pila1, pila2);
			cout << "La suma debe haber sido realizada correctamente."<<endl;
			break;
		case 4:
			if (!pila3->pilaVacia())
			{
				pila3->mostrarPila();
			}
			else
			{
				cout << "No hay ningun dato" << endl;
			}
			cin.get();
			break;
		case 5:
			cout << "Gracias por utilizar mi programa." << endl;
			exit(1);
			break;			
		default:
				cout << "Opcion incorrecta." << endl;
				cin.get();
				break;
		}
		cin.get();
	} while (opt != 5);
	
}
void menuPilas()
{
	cout << "\n \t Pilas y colas.\n\n";
	cout << "\n \t Menu trabajo\n\n";
	cout << "1. Apilar. " << endl;
	cout << "2. Desapilar. " << endl;
	cout << "3. Encolar " << endl;
	cout << "4. Desencolar. " << endl;
	cout << "5. Mostrar pila. " << endl;
	cout << "6. Mostrar cola." << endl;
	cout << "7. Invertir Pila." << endl;
	cout << "8. Apilar Ordenado" << endl;
	cout << "9. volver" << endl;
	cout << "10. salir" << endl;


	cout << "\tIngresar opcion.\n";
}

void menuPrincipal()
{
	cout << "\n \t Pilas y colas.\n\n";
	cout << "\n \t Menu Principal.\n\n";
	cout << "1. Trabajar pila 1. " << endl;
	cout << "2. Trabajar pila 2." << endl;
	cout << "3. Sumar pila 1 y 2." << endl;
	cout << "4. Mostrar pila/cola 3 " << endl;
	cout << "5. Salir del programa. " << endl;
}