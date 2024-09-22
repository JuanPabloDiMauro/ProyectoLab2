#include <iostream>
#include "ArchivoEstadoEntrega.h"
#include <cstring>

ArchivosEstadoEntrega :: ArchivosEstadoEntrega(){
	strcpy(_Nombre , "Clientes.dat");
}

bool ArchivosEstadoEntrega :: AgregarRegistro(EstadoEntrega obj){
	FILE *p;
	p=fopen(_Nombre, "ab");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 3" << std::endl;
		return false;
	}
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

int ArchivosEstadoEntrega :: ContarRegistros(){
	FILE *p;
	p=fopen(_Nombre, "rb");
	if(p==nullptr){
		return -1;
	}
	fseek(p, 0, 2);
	int cant=ftell(p) / sizeof (EstadoEntrega);
	fclose(p);
	return cant;
}

EstadoEntrega ArchivosEstadoEntrega :: LeerRegistro(int pos){
	EstadoEntrega obj;
	FILE *p;
	p=fopen(_Nombre, "rb");
	if(p==nullptr){
		return obj;
	}
	fseek(p, sizeof obj * pos, 0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}

int ArchivosEstadoEntrega :: buscarPosicion(int id){
	int pos=-1;
	EstadoEntrega obj;
	FILE *p;
	p=fopen(_Nombre, "rb");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 6" << std::endl;
		return -1;
	}
	int tam=ContarRegistros();
	for(int i=0; i<tam; i++){
		obj = LeerRegistro(i);
		if(obj.getIdTrabajo() == id){
			fclose(p);
			return i;
		}
	}
	fclose(p);
	return pos;
}

bool ArchivosEstadoEntrega :: EliminarRegistro(int id){
	EstadoEntrega obj;
	bool opcion;
	FILE *p;
	p=fopen(_Nombre, "rb+");
	if(p==nullptr){
		return false;
	}
	int pos = buscarPosicion(id);
	if(pos==-1){
		return false;
	}
	obj = LeerRegistro(pos);
	if(obj.getEstado()==true){
		std::cout << "ID TRABAJO: " <<obj.getIdTrabajo() << std::endl;
		std::cout << std::endl;
		std::cout << "APELLIDO: " << obj.getCliente().getapellido() << std::endl;
		std::cout << "NOMBRE: " << obj.getCliente().getnombre() << std::endl;
		std::cout << "CELULAR: " << obj.getCliente().getcelular() << std::endl;
		std::cout << "DIRECCION: " << obj.getCliente().getDireccion() << std::endl;
		std::cout << "FECHA DE ENTREGA: " << obj.getFechaFinalizacion().getdia() << "/";
		std::cout << obj.getFechaFinalizacion().getmes() << "/";
		std::cout << obj.getFechaFinalizacion().getanio() << std::endl;
		std::cout << std::endl;
		std::cout << "ELIMINAR CLIENTE DEL PROGRAMA? " << std::endl;
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
		bool escribio=fwrite(&obj, sizeof obj, 1, p);
		fclose(p);
		return escribio;
	}else{
		fclose(p);
		return false;
	}
}

