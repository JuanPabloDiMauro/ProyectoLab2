#include <iostream>
using namespace std;
#include "submenu.h"
#include "funcionesGlobales.h"

void submenu :: subprograma1(){
    do{
        cout << "1) --- NUEVO TRABAJO --- " << endl;
        cout << "2) --- TRABAJOS EN EJECUCION --- " << endl;
        cout << "3) --- TRABAJOS FINALIZADOS --- " << endl;
        cout << "4) --- BORRAR TRABAJO --- " << endl;
        cout << "5) --- FINALIZAR OBRA --- " << endl;
        cout << "0) --- VOLVER --- " << endl;
        cout << endl;
        cout << "opcion: ";
        cin >> _opcion;
        switch(_opcion){
            case 1:
                system("cls");
				nuevoTrabajo();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
				TrabajosEnEjecucion();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
				TrabajosFinalizados();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
				BorrarTrabajo();
                system("pause");
                system("cls");
                break;
			case 5:
				system("cls");
				ModificarTrabajo();
                system("pause");
                system("cls");
                break;
            case 0:
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

void submenu :: subprograma2(){
    do{
        cout << "1) --- LISTAR CLIENTES --- " << endl;
        cout << "1) --- MODIFICAR CLIENTE --- " << endl;
        cout << "2) --- NUEVO CLIENTE --- " << endl;
        cout << "3) --- BORRAR CLIENTE --- " << endl;
        cout << "0) --- VOLVER --- " << endl;
        cout << endl;
        cout << "opcion: ";
        cin >> _opcion;
        switch(_opcion){
            case 1:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 0:
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

void submenu :: subprograma3(){
    do{
        cout << "1) --- INGRESAR HORA Y PAGO --- " << endl;
        cout << "2) --- MOSTRAR SUELDOS --- " << endl;
        cout << "3) --- AGREGAR EMPLEADOS --- " << endl;
        cout << "4) --- ELIMINAR EMPLEADOS --- " << endl;
        cout << "0) --- VOLVER --- " << endl;
		cout << endl;
        cout << "opcion: ";
        cin >> _opcion;
        switch(_opcion){
            case 1:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 0:
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

void submenu :: subprograma4(){
    do{
        cout << "1) --- SOBRANTE DE PLACAS --- " << endl;
        cout << "2) --- ELIMINAR SOBRANTE --- " << endl;
        cout << "0) --- VOLVER --- " << endl;
        cout << endl;
        cout << "opcion: ";
        cin >> _opcion;
        switch(_opcion){
            case 1:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 0:
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

void submenu :: subprograma5(){
    do{
        cout << "1) --- BALANCE MENSUAL --- " << endl;
        cout << "2) --- INGRESOS --- " << endl;
        cout << "3) --- GASTOS --- " << endl;
        cout << "4) --- ELIMINAR MES --- " << endl;
        cout << "0) --- VOLVER --- " << endl;
        cout << endl;
        cout << "opcion: ";
        cin >> _opcion;
        switch(_opcion){
            case 1:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");

                system("pause");
                system("cls");
                break;
            case 0:
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
