#include <iostream>
using namespace std;
#include "menu.h"
#include "submenu.h"

void menu :: programa(){
    submenu a;
    do{
        cout << "----------------------------------------------" << endl;
        cout << "----------------- TALLER A&A -----------------" << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << "1) --- TRABAJOS --- " << endl;
        cout << "2) --- CLIENTES --- " << endl;
        cout << "3) --- STOCK --- " << endl;
        cout << "4) --- GASTOS E INGRESOS --- " << endl;
        cout << "0) --- SALIR --- " << endl;
        cout << endl;
        cout << "opcion: ";
        cin >> _opcion;
        switch(_opcion){
            case 1:
                system("cls");
                a.subprograma1();
                break;
            case 2:
                system("cls");
                a.subprograma2();
                break;
            case 3:
                system("cls");
                a.subprograma3();
                break;
            case 4:
                system("cls");
                a.subprograma4();
                break;
            case 0:
                system("cls");
                    cout << "PRESIONE CUALQUIER TECLA PARA CERRAR" << endl;
                system("pause");
                system("cls");
                break;
            default:
                system("cls");
                    cout << "OPCION INVALIDA" << endl;
                system("pause");
                system("cls");
                break;
        }
    }
    while(_opcion != 0);
}
