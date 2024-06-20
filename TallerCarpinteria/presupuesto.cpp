#include "presupuesto.h"

presupuesto :: presupuesto (){
    _precio = 0;
    _PrecioObra = 0;
    _PrecioPlaca = 0;
    _metroCuadrado = 0;
}

void presupuesto :: setmetrocuadrado(float metrocuadrado){
	if(metrocuadrado > 0){
		_metroCuadrado = metrocuadrado;
	}
}
void presupuesto :: setprecio(float precio){
	if(precio > 0){
		_precio = precio;
	}
}
void presupuesto :: setPrecioPlacas(int CantPlacas){
	_PrecioPlaca += CantPlacas * _precio;
}
void presupuesto :: setPrecioObra(){
	_PrecioObra += _metroCuadrado * _precio;
}

float presupuesto :: getPrecioPlacas(){
	return _PrecioPlaca;
}
float presupuesto :: getPrecioObra(){
	return _PrecioObra;
}


