#include <iostream>
using namespace std;
#include "submenu.h"

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
				_ObjTrabajosManager.CargarTrabajos();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
				_ObjTrabajosManager.TrabajosEnEjecucion();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
				_ObjTrabajosManager.TrabajosFinalizados();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
				_ObjTrabajosManager.BorrarTrabajo();
                system("pause");
                system("cls");
                break;
			case 5:
				system("cls");
				_ObjTrabajosManager.ModificarTrabajo();
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
        cout << "2) --- MODIFICAR CLIENTE --- " << endl;
        cout << "3) --- NUEVO CLIENTE --- " << endl;
        cout << "4) --- BORRAR CLIENTE --- " << endl;
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

void submenu :: subprograma4(){
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
