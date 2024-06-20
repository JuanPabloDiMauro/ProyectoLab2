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
		std::cout << "ERROR DE APERTURA DE ARCHIVO 7" << std::endl;
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
bool ArchivosMedidas :: eliminarMedidas(int idTrabajo){
	medidas obj;
	FILE *p;
	p=fopen(nombre, "rb+");
	if(p==nullptr){
		return false;
	}
	bool bandera=false;
	int cont=contarRegistro();
	for(int i=0; i<cont; i++){
		obj = leerRegistro(i);
		fread(&obj, sizeof obj, 1, p);
		if(obj.getIdTrabajo() == idTrabajo){
			fseek(p, sizeof obj * i, 0);
			fwrite(&obj, sizeof obj, 1, p);
			bandera = true;
		}
	}
	fclose(p);
	return bandera;
}
medidas ArchivosMedidas :: leerRegistro(int pos){
	medidas obj;
	obj.setIdTrabajo(-1);
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 9" << std::endl;
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
		std::cout << "ERROR DE APERTURA DE ARCHIVO 7" << std::endl;
		return -1;
	}
	fseek(p, 0, 2);
	int cant=ftell(p) / sizeof (medidas);
	fclose(p);
	return cant;
}
