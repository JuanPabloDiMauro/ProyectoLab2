#include "persona.h"
#include <cstring>

persona :: persona(){
	strcpy(_Nombre, "SIN NOMBRE");
	strcpy(_Apellido, "SIN APELLIDO");
	strcpy(_Celular, "SIN NUMERO");
}
std::string persona :: getapellido(){
    return _Apellido;
}
std::string persona :: getnombre(){
    return _Nombre;
}
std::string persona :: getcelular(){
	return _Celular;
}

void persona :: setcelular(std::string celular){
    if(celular.size() <= 30){
		strcpy(_Celular, celular.c_str());
    }
}
void persona :: setapellido(std::string apellido){
    if(apellido.size() <= 30){
		strcpy(_Apellido, apellido.c_str());
    }
}
void persona :: setnombre(std::string nombre){
    if(nombre.size() <= 15){
		strcpy(_Nombre, nombre.c_str());
    }
}
