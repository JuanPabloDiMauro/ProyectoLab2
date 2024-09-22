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
		std::cout << "ERROR DE APERTURA DE ARCHIVO 13" << std::endl;
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
		std::cout << "ERROR DE APERTURA DE ARCHIVO 14" << std::endl;
		return false;
	}
	int pos=buscarPosicion(idTrabajo);
	if(pos < 0){
		fclose(p);
		return false;
	}
	obj=leerRegistro(pos);
	if(obj.getestado() == true){
	std::cout << "ID TRABAJO: " <<obj.getIdTrabajo() << std::endl;
	std::cout << std::endl;
	std::cout << "DATOS CLIENTE: ";
	std::cout << std::endl << std::endl;
	std::cout << "APELLIDO: " << obj.getdatoscliente().getapellido() << std::endl;
	std::cout << "NOMBRE: " << obj.getdatoscliente().getnombre() << std::endl;
	std::cout << "CELULAR: " << obj.getdatoscliente().getcelular() << std::endl;
	std::cout << "DIRECCION: " << obj.getdatoscliente().getDireccion() << std::endl;
	std::cout << "FECHA DE ENTREGA: " << obj.getdatoscliente().getFechaEntrega().getdia() << "/";
	std::cout << obj.getdatoscliente().getFechaEntrega().getmes() << "/";
	std::cout << obj.getdatoscliente().getFechaEntrega().getanio() << std::endl;
	std::cout << std::endl << "PRESUPUESTO DE OBRA: " << std::endl;
	std::cout << "PRECIO DE OBRA: $ " << obj.getPrecioObra() << std::endl;
	std::cout << "PRECIO DE PLACAS: $ " << obj.getPrecioPlacas() << std::endl;
	std::cout << std::endl;
	std::cout << "ELIMINAR LA OBRA DEL PROGRAMA? " << std::endl;
	std::cout << "1 - SI: " << std::endl;
	std::cout << "0 - NO: " << std::endl;
	std::cout << "OPCION: ";
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
	}else{
		fclose(p);
		return true;
	}
}

trabajos ArchivosTrabajos :: leerRegistro(int pos){
	trabajos obj;
	FILE *p;
	p=fopen(Nombre, "rb");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 15" << std::endl;
		return obj;
	}
	fseek(p, sizeof obj * pos, 0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}

int ArchivosTrabajos :: contarRegistro(){
	FILE *p;
	p=fopen(Nombre, "rb");
	if(p==nullptr){
		return 0;
	}
	fseek(p, 0, 2);
	int cant=ftell(p) / sizeof (trabajos);
	fclose(p);
	return cant;
}

int ArchivosTrabajos :: buscarPosicion(int idTrabajo){
	trabajos obj;
	FILE *p;
	p=fopen(Nombre, "rb");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 16" << std::endl;
		return -1;
	}
	int cont=contarRegistro();
	for(int i=0; i<cont; i++){
		obj = leerRegistro(i);
		if(idTrabajo == obj.getIdTrabajo()){
			fclose(p);
			return i;
		}
	}
	fclose(p);
	return -1;
}

int ArchivosTrabajos :: NuevoIdTrabajo(){
	int cont=contarRegistro();
	if(cont == 0){
		return 1;
	}
	trabajos obj=leerRegistro(cont - 1);
	return obj.getIdTrabajo() + 1;
}

bool ArchivosTrabajos :: ModificarTrabajo(int idtrabajo){
	trabajos obj;
	bool opcion;
	FILE *p;
	p=fopen(Nombre, "rb+");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 17" << std::endl;
		return false;
	}
	int pos=buscarPosicion(idtrabajo);
	if(pos==-1){
		std::cout << std::endl << "NO EXISTE EL ID DE TRABAJO" << std::endl;
		fclose(p);
		return false;
	}
	obj=leerRegistro(pos);
	if(obj.getEstadoDeEjecucion() == true){
	std::cout << "ID TRABAJO: " <<obj.getIdTrabajo() << std::endl;
	std::cout << std::endl;
	std::cout << "DATOS CLIENTE: ";
	std::cout << std::endl << std::endl;
	std::cout << "APELLIDO: " << obj.getdatoscliente().getapellido() << std::endl;
	std::cout << "NOMBRE: " << obj.getdatoscliente().getnombre() << std::endl;
	std::cout << "CELULAR: " << obj.getdatoscliente().getcelular() << std::endl;
	std::cout << "DIRECCION: " << obj.getdatoscliente().getDireccion() << std::endl;
	std::cout << "FECHA DE ENTREGA: " << obj.getdatoscliente().getFechaEntrega().getdia() << "/";
	std::cout << obj.getdatoscliente().getFechaEntrega().getmes() << "/";
	std::cout << obj.getdatoscliente().getFechaEntrega().getanio() << std::endl;
	std::cout << std::endl << "PRESUPUESTO DE OBRA: " << std::endl;
	std::cout << "PRECIO DE OBRA: $ " << obj.getPrecioObra() << std::endl;
	std::cout << "PRECIO DE PLACAS: $ " << obj.getPrecioPlacas() << std::endl;
	std::cout << std::endl;
	std::cout << "LA OBRA FUE FINALIZADA? ";
	std::cout << std::endl;
	std::cout << "1 - SI: " << std::endl;
	std::cout << "0 - NO: " << std::endl;
	std::cout << "OPCION: ";
	std::cin >> opcion;
	if(opcion == true){
		fseek(p, sizeof obj * pos, 0);
		obj.setEstadoDeEjecucion(false);
		fwrite(&obj, sizeof obj, 1, p);
		fclose(p);
		return true;
	}
	fclose(p);
	return false;
	}else{
		fclose(p);
		return false;
	}
}

