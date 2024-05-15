#include <iostream>
#include "persona.h"
#include <cstring>
#include "funcionesGlobales.h"

persona :: persona(){

}
const char * persona :: getapellido(){
    return _Apellido;
}
const char * persona :: getnombre(){
    return _Nombre;
}
const char * persona :: getcelular(){
	return _Celular;
}

void persona :: setcelular(const char * celular){
    strcpy(_Celular, celular);
}
void persona :: setapellido(const char * apellido){
    strcpy(_Apellido , apellido);
}
void persona :: setnombre(const char * nombre){
    strcpy(_Nombre , nombre);
}
void persona :: cargarPersona(){
	std::cout << "Nombre: ";
	cargarCadena(_Nombre, 15);
	std::cout << "Apellido: ";
	cargarCadena(_Apellido, 15);
	std::cout << "Celular: ";
	cargarCadena(_Celular, 15);
}
void persona :: mostrarPersona(){
	std::cout << "Nombre completo: " << _Apellido << " , " << _Nombre << std::endl;
	std::cout << "Celular: " <<  _Celular << std::endl;
}

/// terminadooo
