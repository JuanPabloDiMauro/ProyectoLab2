#include "placa.h"
#include <cstring>

placa :: placa (){
	strcpy(_color, "S/C");
	_Largo = 0;
	_Ancho = 0;
	_IdPlaca = 0;
}

void placa :: setIdPlaca(int id){
	_IdPlaca = id;
}

void placa ::  setcolor(std::string color){
    if(color.size() <= 30){
		strcpy(_color, color.c_str());
    }
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

int placa :: getIdPlaca(){
	return _IdPlaca;
}

float placa :: getprecio(){
	return _precio;
}

std::string placa ::  getcolor(){
    return _color;
}

float placa :: getlargo(){
    return _Largo;
}

float placa :: getancho(){
    return _Ancho;
}
