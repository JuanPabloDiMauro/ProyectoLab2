#include "trabajos.h"

trabajos :: trabajos(){
	_PrecioObra = 0;
	_PrecioPlacas = 0;
	_EstadoDeEjecucion = true;
	_DatosCliente=Clientes();
	_estado=true;
}
void trabajos :: setIdTrabajo(int idTrabajo){
	if(idTrabajo>0){
		_idTrabajo = idTrabajo;
	}
}

void trabajos :: setdatoscliente(Clientes DatosCliente){
	_DatosCliente = DatosCliente;
}
void trabajos :: setEstadoDeEjecucion(bool estado){
	_EstadoDeEjecucion = estado;
}

void trabajos :: setPrecioPlacas(float PrecioPlacas){
	if(PrecioPlacas>0){
		_PrecioPlacas += PrecioPlacas;
	}
}
void trabajos :: setPrecioObra(float PrecioObra){
	if(PrecioObra>0){
		_PrecioObra += PrecioObra;
	}
}

void trabajos :: setEstado(bool estado){
	_estado = estado;
}

float trabajos :: getPrecioPlacas(){
	return _PrecioPlacas;
}
float trabajos :: getPrecioObra(){
	return _PrecioObra;
}

Clientes trabajos :: getdatoscliente(){
	return _DatosCliente;
}

int trabajos :: getIdTrabajo(){
	return _idTrabajo;
}

bool trabajos :: getEstadoDeEjecucion(){
	return _EstadoDeEjecucion;
}
bool trabajos :: getestado(){
	return _estado;
}
