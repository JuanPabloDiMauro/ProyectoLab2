#include "Clientes.h"
#include <cstring>

Clientes::Clientes(){
	persona();
	strcpy(_Direccion, "S/D");
	fecha();
	_Estado=true;
}
void Clientes :: setDireccion(std::string direccion){
	if(direccion.size() <= 30){
		strcpy(_Direccion, direccion.c_str());
	}
}
void Clientes :: setFechaEntrega(int dia, int mes, int anio){
	_FechaEntrega.setdia(dia);
	_FechaEntrega.setmes(mes);
	_FechaEntrega.setanio(anio);
}
void Clientes :: setEstado(bool estado){
	_Estado=estado;
}

std::string Clientes :: getDireccion(){
	return _Direccion;
}
fecha Clientes :: getFechaEntrega(){
	return _FechaEntrega;
}

