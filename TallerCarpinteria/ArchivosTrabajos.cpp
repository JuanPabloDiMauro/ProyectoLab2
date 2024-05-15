#include <iostream>
#include "ArchivosTrabajos.h"
#include <cstring>

ArchivosTrabajos :: ArchivosTrabajos(){
	strcpy(Nombre ,"Trabajos.dat");
}
bool ArchivosTrabajos :: agregarTrabajo(trabajos obj){
	FILE *p;
	p=fopen(Nombre, "ab");
	if(p==nullptr){
		return false;
	}
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	if(escribio==true){
		fclose(p);
		return true;
	}
	fclose(p);
	return false;
}
bool ArchivosTrabajos :: eliminarTrabajo(int idTrabajo){
	trabajos obj;
	bool opcion;
	FILE *p;
	p=fopen(Nombre, "rb+");
	if(p==nullptr){
		return false;
	}
	int pos=buscarPosicion(idTrabajo);
	if(pos < 0){
		return false;
	}
	obj=leerRegistro(pos);
	obj.mostrar();
	std::cout << "desea eliminar este registro? "<< std::endl;
	std::cout << "SI = 1 " << std::endl;
	std::cout << "NO = 0" << std::endl;
	std::cout << "opcion: ";
	std::cin >> opcion;
	if(opcion == false){
		fclose(p);
		return false;
	}
	fseek(p, sizeof obj * pos, 0);
	obj.setEstado(false);
	fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return true;
}
void ArchivosTrabajos :: listarTrabajo(int estadoEjecucion){
	trabajos obj;
	FILE *p;
	p=fopen(Nombre, "rb");
	if(p==nullptr){
		return;
	}
	int cont=contarRegistro();
	for(int i=0; i<cont; i++){
		if(obj.getEstadoDeEjecucion()==estadoEjecucion){
			obj.mostrar();
			std::cout << std::endl;
		}
	}
	fclose(p);
}
trabajos ArchivosTrabajos :: leerRegistro(int pos){
	trabajos obj;
	FILE *p;
	p=fopen(Nombre, "rb");
	if(p==nullptr){
		return obj;
	}
	fseek(p, sizeof obj * pos, 0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}
int ArchivosTrabajos :: contarRegistro(){
	trabajos obj;
	FILE *p;
	p=fopen(Nombre, "rb");
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
int ArchivosTrabajos :: buscarPosicion(int idTrabajo){
	trabajos obj;
	FILE *p;
	p=fopen(Nombre, "rb");
	if(p==nullptr){
		return -1;
	}
	int m=0;
	int cont=contarRegistro();
	for(int i=0; i<cont; i++){
		fread(&obj, sizeof obj, 1, p);
		if(idTrabajo == obj.getIdTrabajo()){
			break;
		}else{
			m++;
		}
	}
	fclose(p);
	return m;
}

int ArchivosTrabajos :: NuevoIdTrabajo(){
	int cont=contarRegistro();
	if(cont < 0){
		return 1;
	}
	trabajos obj=leerRegistro(cont - 1);
	return obj.getIdTrabajo() + 1;
}

bool ArchivosTrabajos :: ModificarTrabajo(int idtrabajo){
	trabajos obj;
	int opcion;
	FILE *p;
	p=fopen(Nombre, "rb+");
	if(p==nullptr){
		return false;
	}
	int pos=buscarPosicion(idtrabajo);
	if(pos==-1){
		return false;
	}
	obj=leerRegistro(pos);
	obj.mostrar();
	std::cout << "LA OBRA FUE FINALIZADA? ";
	std::cout << "1 - SI: " << std::endl;
	std::cout << "2 - NO: " << std::endl;
	std::cout << "OPCION: ";
	std::cin >> opcion;
	if(opcion == 1){
		fseek(p, sizeof obj * pos, 0);
		obj.setEstadoDeEjecucion(2);
		fwrite(&obj, sizeof obj, 1, p);
		fclose(p);
		return true;
	}
	fclose(p);
	return false;
}

