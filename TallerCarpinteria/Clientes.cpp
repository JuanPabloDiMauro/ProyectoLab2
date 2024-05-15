#include <iostream>
#include "Clientes.h"
#include "funcionesGlobales.h"

Clientes::Clientes(){
}
void Clientes :: cargar(){
	std::cout << "INGRESAR DATOS DEL CLIENTE";
	std::cout << std::endl;
	persona::cargarPersona();
	std::cout << "Direccion: ";
	cargarCadena(_Direccion, 15);
	std::cout << "Fecha de Entrega: " << std::endl;
	_FechaEntrega.Cargar();
	_Estado=true;
}
void Clientes :: mostrar(){
	std::cout << "DATOS DEL CLIENTE: ";
	std::cout << std::endl;
	persona::mostrarPersona();
	std::cout << "Direccion: " << getDireccion() << std::endl;
	std::cout << "Fecha de Entrega: ";
	_FechaEntrega.mostrar();
}

void Clientes :: setDireccion(const char * direccion){
	cargarCadena(_Direccion, 15);
}
void Clientes :: setFechaEntrega(){
	_FechaEntrega.Cargar();
}
void Clientes :: setEstado(bool estado){
	_Estado=estado;
}

const char * Clientes :: getDireccion(){
	return _Direccion;
}
void Clientes :: getFechaEntrega(){
	_FechaEntrega.mostrar();
}

