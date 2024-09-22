#include<iostream>
#include "ArchivoPlacas.h"
#include <cstring>

ArchivosPlacas :: ArchivosPlacas(){
	strcpy(nombre ,"placas.dat");
}


int ArchivosPlacas :: buscarPosicion(int id){
	int pos=-1;
	placa obj;
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 6" << std::endl;
		return -1;
	}
	int tam=ContarRegistros();
	for(int i=0; i<tam; i++){
		fread(&obj, sizeof obj, 1, p);
		if(obj.getIdPlaca() == id){
			fclose(p);
			return i;
		}
	}
	fclose(p);
	return pos;
}

bool ArchivosPlacas :: AgregarRegistro(placa obj){
	FILE *p;
	p=fopen(nombre, "ab");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 5" << std::endl;
		return false;
	}
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

int ArchivosPlacas :: ContarRegistros(){
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		return -1;
	}
	fseek(p, 0, 2);
	int cant=ftell(p) / sizeof (placa);
	fclose(p);
	return cant;
}


placa ArchivosPlacas :: LeerRegistro(int pos){
	placa obj;
	obj.setIdPlaca(-1);
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 6" << std::endl;
		return obj;
	}
	fseek(p, sizeof obj * pos, 0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}
