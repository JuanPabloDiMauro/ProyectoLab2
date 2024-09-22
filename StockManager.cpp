#include <iostream>
#include "StockManager.h"
#include "InsumosTrabajo.h"
#include "placa.h"

void StockManager :: SobranteDePlacas(){
	int cont = _ObjArchiStock.ContarRegistros();

	for(int i=0; i<cont; i++){
		_ObjStock = _ObjArchiStock.LeerRegistro(i);

		if(_ObjStock.getSobrante() > 0){
			std::cout << "ID PLACA: " << _ObjStock.getIdPlaca() << std::endl;
			std::cout << "COLOR: " << _ObjStock.getColor() << std::endl;
			std::cout << "SOBRANTE: " << _ObjStock.getSobrante() << std::endl;
			std::cout << "----------------------" << std::endl;
		}
	}
}

void StockManager :: EliminarSobrante(){
	std::cout << "ELIMINAR SOBRANTE DE LA PLACA..." << std::endl;
	std::cout << "INGRESAR ID: ";
	int id;
	std::cin >> id;
	_ObjArchiStock.ModificarStock(id);
}

void StockManager :: AgregarSobrante(){
	int cont = _ObjArchiInsumos.ContarRegistros();
	int cant=_ObjArchiPlacas.ContarRegistros();

	InsumosTrabajo obj;
	placa objPlaca;

	obj = _ObjArchiInsumos.LeerRegistro(cont - 1);
	int id = obj.getIdTrabajo();

	float *vec;
	vec = new float [cant];

	if(vec==nullptr){
		std::cout << "ERROR DE MEMORIA" << std::endl;
		return;
	}

	for(int i=0; i<cant; i++){
		vec[i] = 0;
	}

	for(int i=0; i<cont; i++){
		obj=_ObjArchiInsumos.LeerRegistro(i);

		if(obj.getIdTrabajo() == id){
			vec[obj.getIdPlaca()-1] += obj.getSobrante();
		}
	}

	for(int i=0; i<cant; i++){
		if(vec[i] > 0){
			_ObjArchiStock.AgregarSobrante(i+1, vec[i]);
	}
	}

	delete [] vec;
}

