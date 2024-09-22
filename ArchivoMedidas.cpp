#include <iostream>
#include "ArchivosMedidas.h"
#include <cstring>

ArchivosMedidas :: ArchivosMedidas (){
	strcpy(nombre, "Medidas.dat");
}
bool ArchivosMedidas :: agregarMedidas(medidas obj){
	FILE *p;
	p=fopen(nombre, "ab");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 1" << std::endl;
		return false;
	}
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	if(escribio == true){
		fclose(p);
		return true;
	}
	fclose(p);
	return false;
}

medidas ArchivosMedidas :: leerRegistro(int pos){
	medidas obj;
	obj.setIdTrabajo(-1);
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 2" << std::endl;
		return obj;
	}
	fseek(p, sizeof obj * pos, 0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}
int ArchivosMedidas :: contarRegistro(){
	medidas obj;
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		return -1;
	}
	fseek(p, 0, 2);
	int cant=ftell(p) / sizeof (medidas);
	fclose(p);
	return cant;
}
