#include "GastoIngreso.h"

GastoIngreso :: GastoIngreso(){
	_PrecioObra=0;
	_PrecioPlacas=0;
}

void GastoIngreso :: setPrecioPlacas(float precio){
	if(precio>0){
		_PrecioPlacas += precio;
	}
}

void GastoIngreso :: setPrecioObra(float precio){
	if(precio>0){
		_PrecioObra += precio;
	}
}

void GastoIngreso :: setBalance(){
	_Balance = _PrecioObra - _PrecioPlacas;
}

float GastoIngreso :: getPrecioPlacas(){
	return _PrecioPlacas;
}

float GastoIngreso :: getPrecioObra(){
	return _PrecioObra;
}

float GastoIngreso :: getBalance(){
	return _Balance;
}
