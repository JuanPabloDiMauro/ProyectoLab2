#include <iostream>
#include "trabajos.h"
#include "funcionesGlobales.h"

trabajos :: trabajos(){
	_EstadoDeEjecucion = 1;
}
void trabajos :: setIdTrabajo(int idTrabajo){
	_idTrabajo = idTrabajo;
}
void trabajos :: setplaca(placa Tplaca){
	_TipoPlaca = Tplaca;
}
void trabajos :: setCantPlacas(int cant){
	_CantPlacas = cant;
}
void trabajos :: setPrecioPlacas(float precio){
	_PrecioPlacas = precio;
}
void trabajos :: setPrecioObra(float precio){
	_PrecioObra = precio;
}
void trabajos :: setEstado(bool estado){
	_estado = estado;
}
void trabajos :: setdatoscliente(){
	_DatosCliente.cargar();
}
void trabajos :: setEstadoDeEjecucion(int estado){
	if(estado == 1 || estado == 2){
		_EstadoDeEjecucion = estado;
	}
}

Clientes trabajos :: getdatoscliente(){
	return _DatosCliente;
}
placa trabajos :: getplaca(){
	return _TipoPlaca;
}
int trabajos :: getCantPlaca(){
	return _CantPlacas;
}
int trabajos :: getIdTrabajo(){
	return _idTrabajo;
}
float trabajos :: getPrecioPlacas(){
	return _PrecioPlacas;
}
float trabajos :: getPrecioObra(){
	return _PrecioObra;
}
int trabajos :: getEstadoDeEjecucion(){
	return _EstadoDeEjecucion;
}
bool trabajos :: getestado(){
	return _estado;
}

void trabajos :: mostrar(){
	if(_estado==true){
		std::cout << "Id Trabajo: " << _idTrabajo << std::endl << std::endl;
		_DatosCliente.mostrar();
		std::cout << std::endl;
		std::cout << "DATOS DE PLACAS: " << std::endl;
		std::cout << "placa: " << _TipoPlaca.getcolor() << std::endl;
		std::cout << "Cantidad de Placas: " << _CantPlacas << std::endl;
		std::cout << std::endl;
		std::cout << "PRESUPUESTOS: " << std::endl;
		std::cout << "Precio de Placas: $ " << _PrecioPlacas << std::endl;
		std::cout << "Presupuesto final de obra: $ " << _PrecioObra << std::endl;
		std::cout << std::endl;
		if(_EstadoDeEjecucion == 1){
			std::cout << "OBRA EN PROCESO" << std::endl;
		}
		else{
			std::cout << "OBRA FINALIZADA" << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "MEDIDAS DE LA OBRA: " << std::endl;
	}
}

