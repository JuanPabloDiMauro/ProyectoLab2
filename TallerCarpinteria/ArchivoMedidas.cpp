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
		fread(&obj, sizeof obj, 1, p);
		if(obj.getIdMedidas() == idTrabajo){
			obj.setEstado(false);
			fseek(p, sizeof obj * i, 0);
			fwrite(&obj, sizeof obj, 1, p);
			bandera = true;
		}
	}
	fclose(p);
	if(bandera == true){
		return true;
	}
	return false;
}
void ArchivosMedidas :: listarRegistro(int idMedidas){
	medidas obj;
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		return;
	}
	int cont = contarRegistro();
	for(int i=0; i<cont; i++){
		fread(&obj, sizeof obj, 1, p);
		if(obj.getIdMedidas() == idMedidas){
			obj.mostrar();
		}
	}
	fclose(p);
	return;
}
int ArchivosMedidas :: contarRegistro(){
	medidas obj;
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		return -1;
	}
	int i=0;
	while(fread(&obj, sizeof obj, 1, p)){
		i++;
	}
	fclose(p);
	return i;
}
