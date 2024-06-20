#include "InsumosTrabajo.h"

InsumosTrabajo :: InsumosTrabajo(){
	_IdTrabajo = 0;
	_IdPlaca = 0;
	_CantPlacas = 1;
	_Sobrante = 0;
}

void InsumosTrabajo :: setIdTrabajo(int id){
	if(id>0){
		_IdTrabajo = id;
	}
}
void InsumosTrabajo :: setIdPlaca(int id){
	if(id>0){
		_IdPlaca = id;
	}
}
void InsumosTrabajo :: setCantPlacas(int cant){
	if(_CantPlacas > 0){
		_CantPlacas = cant;
	}
}
void InsumosTrabajo :: setSobrante(float sobrante){
	if(sobrante >= 0){
		_Sobrante = sobrante;
	}
}

int InsumosTrabajo :: getIdTrabajo(){
	return _IdTrabajo;
}
int InsumosTrabajo :: getIdPlaca(){
	return _IdPlaca;
}
int InsumosTrabajo :: getCantPlacas(){
	return _CantPlacas;
}
float InsumosTrabajo :: getSobrante(){
	return _Sobrante;
}

