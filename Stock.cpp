#include "Stock.h"
#include <cstring>

Stock :: Stock(){
	_Sobrante = 0;
}

void Stock :: setIdPlaca(int id){
	if(id>0){
		_IdPlaca = id;
	}
}

void Stock :: setColor(std::string color){
	if(color.size() <= 30){
		strcpy(_Color, color.c_str());
    }
}

void Stock :: setSobrante(float sobrante){
	if(sobrante>-1){
		_Sobrante += sobrante;
	}
}

void Stock :: EliminarSobrante(float sobrante){
	if(sobrante > _Sobrante){
		_Sobrante = 0;
	}else{
		_Sobrante = _Sobrante - sobrante;
	}
}

std::string Stock :: getColor(){
	return _Color;
}

float Stock :: getSobrante(){
	return _Sobrante;
}

int Stock :: getIdPlaca(){
	return _IdPlaca;
}

