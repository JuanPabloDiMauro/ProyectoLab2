#include "placa.h"
#include <cstring>

placa :: placa (){
    _Largo = 260;
    _Ancho = 183;
    strcpy(_color, "blanco");
    _precio = 0;
}

void placa ::  setcolor(const char * color){
    strcpy(_color, color);
}

void placa :: setlargo(float largo){
    if(largo>0 && largo<=366){
        _Largo = largo;
    }
}

void placa :: setancho (float ancho){
    if(ancho > 0 &&ancho <= 183){
        _Ancho = ancho;
    }
}

void placa :: setprecio(float precio){
    if(precio > 0){
        _precio = precio;
    }
}
float placa :: getprecio(){
	return _precio;
}

const char * placa ::  getcolor(){
    return _color;
}

float placa :: getlargo(){
    return _Largo;
}

float placa :: getancho(){
    return _Ancho;
}

/// TERMINADOOOO
