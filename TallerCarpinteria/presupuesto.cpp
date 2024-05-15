#include "presupuesto.h"

presupuesto :: presupuesto (){
    _precio = 0;
}
float presupuesto :: getmetrocuadrado(){
    return _metroCuadrado;
}
float presupuesto :: getprecio(){
    return _precio;
}
float presupuesto :: getPrecioTotal(){
	return _PrecioTotal;
}
void presupuesto :: setmetrocuadrado(float metrocuadrado){
    _metroCuadrado = metrocuadrado;
}
void presupuesto :: setprecio(float precio){
    if(precio > 0){
		_precio = precio;
    }
}
void presupuesto :: setPrecioTotal(){
	_PrecioTotal = _metroCuadrado * _precio;
}


