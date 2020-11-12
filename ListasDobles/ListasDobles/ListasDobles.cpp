// ListasDobles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "listaDobleLineal.h"
#include "listaDobleCircular.h"

using namespace std;

int main()
{
    int opcion;
    listaDobleCircular* lista = new listaDobleCircular();
    lista->agregarInicio(2);
    lista->agregarInicio(4);
    lista->agregarInicio(2);
    lista->agregarInicio(15);
    lista->agregarInicio(10);
    lista->desplegar();
    cout << "--------------------------------------------" << endl;
    lista->desplegarMultiplos(2);
    listaDobleCircular* listaClon = lista->listaInvertida();
    cout << "--------------------------------------------" << endl;
    listaClon->desplegar();

    

    /*do {
        cout << "Digite la opcion a utilizar para la lista creada: " << endl;
        cout << "1- Desplegar lista" << endl;
        cout << "2- Agregar un nodo al inicio" << endl;
        cout << "3- Agregar un antes de " << endl;
        cout << "4- Agregar despues de  " << endl;
        cout << "5- Agregar al final  " << endl;
        cout << "6- Valor del indice " << endl;
        cout << "7- Agregar por indice" << endl;
        cout << "8- Nodo por valor" << endl;
        cout << "9- Nodo anterior a un valor" << endl;
        cout << "10- Nodo final" << endl;
        cout << "11- Nodo por indice" << endl;
        cout << "12- Eliminar por indice" << endl;
        cout << "13- Eliminar por valor" << endl;
        int valor;
        int valor2;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "--------------------------------------------" << endl;
            lista->desplegar();
            cout << "--------------------------------------------" << endl;
            break;
        case 2:
            cout << "Digite el valor:" << endl;
            cin >> valor;
            lista->agregarInicio(valor);
            break;
        case 3:
            cout << "Digite el valor de referencia" << endl;
            cin >> valor2;
            cout << "Digite el valor a agregar" << endl;
            cin >> valor;
            lista->agregarAntesDe(valor, valor2);
            break;
        case 4:
            cout << "Digite el valor de referencia" << endl;
            cin >> valor2;
            cout << "Digite el valor a agregar" << endl;
            cin >> valor;
            lista->agregarDespuesDe(valor, valor2);
            break;
        case 5:
            cout << "Digite el valor:" << endl;
            cin >> valor;
            lista->agregarFinal(valor);
            break;
        case 6:
            cout << "Digite el indice:" << endl;
            cin >> valor;
            cout << lista->valorIndice(valor) << endl;
            break;
        case 7:
            cout << "Digite el indice:" << endl;
            cin >> valor;
            cout << "Digite el valor a agregar" << endl;
            cin >> valor2;
            lista->agregarIndice(valor2, valor);
            break;

        case 8:
            cout << "Digite el valor:" << endl;
            cin >> valor;
            cout << lista->dirNodo(valor) << endl;
            break;

        case 9:
            cout << "Digite el valor:" << endl;
            cin >> valor;
            cout << lista->dirAnterior(valor) << endl;
            break;
        case 10:
            cout << lista->dirUltimo() << endl;
            break;
        case 11:
            cout << "Digite el indice:" << endl;
            cin >> valor;
            cout << lista->dirNodoIndice(valor) << endl;
            break;
        case 12:
            cout << "Digite el indice:" << endl;
            cin >> valor;
            lista->eliminarIndice(valor);
            break;
        case 13:
            cout << "Digite el valor:" << endl;
            cin >> valor;
            lista->eliminar(valor);
            break;
        case 14:
            break;
        default:
            cout << "Valor incorrecto" << endl;
            break;
        }
    } while(opcion != 14);*/

}

