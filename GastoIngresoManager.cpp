#include <iostream>
#include <locale.h>
#include "GastoIngresoManager.h"
#include "ArchivosTrabajos.h"
#include "ArchivoEstadoEntrega.h"
#include "EstadoEntrega.h"
#include "trabajos.h"

void GastoIngresoManager :: BalanceMensual(){
	_ObjGastoIngreso = GastoIngreso();
	ArchivosEstadoEntrega objArchi;
	EstadoEntrega objEstadoEntrega;
	ArchivosTrabajos objArchiTrabajos;
	trabajos objTrabajos;
	int mes, anio;

	int cont = objArchi.ContarRegistros();
	int cont2 = objArchiTrabajos.contarRegistro();

	setlocale(LC_CTYPE, "spanish");
	std::cout << "REALIZAR BALANCE DEL MES Y AÑO: " << std::endl;
	std::cout << "MES: ";
	std::cin >> mes;
	if(mes<1){
		mes=1;
	}
	if(mes>12){
		mes=12;
	}
	std::cout << "AÑO: ";
	std::cin >> anio;

	for(int i=0; i<cont; i++){
		objEstadoEntrega = objArchi.LeerRegistro(i);
		if(mes==objEstadoEntrega.getFechaFinalizacion().getmes() && anio == objEstadoEntrega.getFechaFinalizacion().getanio()){
			for(int m=0; m<cont2; m++){
				objTrabajos = objArchiTrabajos.leerRegistro(m);
				if(objTrabajos.getIdTrabajo()==objEstadoEntrega.getIdTrabajo() && objTrabajos.getestado() == true){
					_ObjGastoIngreso.setPrecioPlacas(objTrabajos.getPrecioPlacas());
					_ObjGastoIngreso.setPrecioObra(objTrabajos.getPrecioObra());
				}
			}
		}
	}
	_ObjGastoIngreso.setBalance();

	system("pause");
	system("cls");

	if(_ObjGastoIngreso.getBalance() != 0){
		std::cout << "GASTO DE: $ " << _ObjGastoIngreso.getPrecioPlacas();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "INGRESO DE: $ " << _ObjGastoIngreso.getPrecioObra();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "EL MES " << mes << " DEL AÑO " << anio  << " TUVO UN BALANCE DE $ " << _ObjGastoIngreso.getBalance() << std::endl;
		std::cout << std::endl;
	}else{
		std::cout << std::endl;
		std::cout << "NO EXISTEN OBRAS REALIZADAS EN LA FECHA: " << mes << "/" << anio << std::endl;
		std::cout << std::endl;
	}
}

void GastoIngresoManager :: BalanceAnual(){
	_ObjGastoIngreso = GastoIngreso();
	ArchivosEstadoEntrega objArchi;
	EstadoEntrega objEstadoEntrega;
	ArchivosTrabajos objArchiTrabajos;
	trabajos objTrabajos;
	int anio;

	int cont = objArchi.ContarRegistros();
	int cont2 = objArchiTrabajos.contarRegistro();

	setlocale(LC_CTYPE, "spanish");
	std::cout << "REALIZAR BALANCE DEL AÑO: " << std::endl;
	std::cout << "AÑO: ";
	std::cin >> anio;

	for(int i=0; i<cont; i++){
		objEstadoEntrega = objArchi.LeerRegistro(i);
		if(anio == objEstadoEntrega.getFechaFinalizacion().getanio()){
			for(int m=0; m<cont2; m++){
				objTrabajos = objArchiTrabajos.leerRegistro(m);
				if(objTrabajos.getIdTrabajo()==objEstadoEntrega.getIdTrabajo() && objTrabajos.getestado() == true){
					_ObjGastoIngreso.setPrecioPlacas(objTrabajos.getPrecioPlacas());
					_ObjGastoIngreso.setPrecioObra(objTrabajos.getPrecioObra());
				}
			}
		}
	}
	_ObjGastoIngreso.setBalance();

	system("pause");
	system("cls");

	if(_ObjGastoIngreso.getBalance() != 0){
		std::cout << "GASTO DE: $ " << _ObjGastoIngreso.getPrecioPlacas();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "INGRESO DE: $ " << _ObjGastoIngreso.getPrecioObra();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "EL AÑO " << anio  << " TUVO UN BALANCE DE $ " << _ObjGastoIngreso.getBalance() << std::endl;
		std::cout << std::endl;
	}else{
		std::cout << std::endl;
		std::cout << "NO EXISTEN OBRAS REALIZADAS EN EL AÑO: " << anio << std::endl;
		std::cout << std::endl;
	}
}
