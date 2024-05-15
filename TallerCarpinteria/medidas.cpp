#include <iostream>
#include "medidas.h"
#include "funcionesGlobales.h"

medidas :: medidas(){

}

void medidas :: cargar(){
	float largo, ancho;
	int cant;
	std::cout << "Largo: ";
	std::cin >> largo;
	setAlturaRecorte(largo);
	std::cout << "Ancho: ";
	std::cin >> ancho;
	setAnchoRecorte(ancho);
	std::cout << "Cantidad de Recortes: ";
	std::cin >> cant;
	setCantRecortes(cant);
	setEstado(true);
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
void medidas :: setEstado(bool estado){
	_Estado = estado;
}

void medidas :: setIdMedidas(int idMedidas){
	_IdMedidas=idMedidas;
}

int medidas :: getIdMedidas(){
	return _IdMedidas;
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
void medidas :: mostrar(){
	if(_Estado==true){
		std::cout << "Largo: " << getAlturaRecorte() << std::endl;
		std::cout << "Ancho: " << GetAnchoRecorte() << std::endl;
		std::cout << "Cantidad de Recortes: " << getCantRecortes() << std::endl;
		std::cout << std::endl;
	}
}
medidas :: ~medidas(){

}
