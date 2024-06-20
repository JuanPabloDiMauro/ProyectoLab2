#include "medidas.h"


medidas :: medidas(){
    _IdTrabajo = 0;
	_IdPlaca = 0;
	_anchoRecorte = 0;
	_largoRecorte = 0;
}
void medidas :: setAnchoRecorte(float a){
	if(a>0){
		_anchoRecorte = a;
	}
}
void medidas :: setAlturaRecorte(float a){
	if(a>0){
		_largoRecorte = a;
	}
}
void medidas :: setCantRecortes(int cant){
	if(cant>0){
		_cantRecortes = cant;
	}
}

void medidas :: setIdTrabajo(int id){
	if(id>0){
		_IdTrabajo = id;
	}
}

void medidas :: setIdPlaca(int id){
	if(id>0){
		_IdPlaca = id;
	}
}

int medidas :: getIdPlaca(){
	return _IdPlaca;
}

int medidas :: getIdTrabajo(){
	return _IdTrabajo;
}
float medidas :: GetAnchoRecorte(){
	return _anchoRecorte;
}
float medidas :: getAlturaRecorte(){
	return _largoRecorte;
}
int medidas :: getCantRecortes(){
	return _cantRecortes;
}


