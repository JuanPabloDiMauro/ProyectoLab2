#include<iostream>
#include "ArchivosStock.h"
#include <cstring>

ArchivosStock :: ArchivosStock(){
	strcpy(nombre ,"Stock.dat");
}


int ArchivosStock :: buscarPosicion(int id){
	int pos=-1;
	Stock obj;
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		return -1;
	}
	int tam=ContarRegistros();
	for(int i=0; i<tam; i++){
		obj=LeerRegistro(i);
		if(obj.getIdPlaca() == id){
			fclose(p);
			return i;
		}
	}
	fclose(p);
	return pos;
}

bool ArchivosStock :: AgregarRegistro(Stock obj){
	FILE *p;
	p=fopen(nombre, "ab");
	if(p==nullptr){
		std::cout << "ERROR DE APERTURA DE ARCHIVO 8" << std::endl;
		return false;
	}
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

int ArchivosStock :: ContarRegistros(){
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		return -1;
	}
	fseek(p, 0, 2);
	int cant=ftell(p) / sizeof (Stock);
	fclose(p);
	return cant;
}


Stock ArchivosStock :: LeerRegistro(int pos){
	Stock obj;
	obj.setIdPlaca(-1);
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

void ArchivosStock :: ModificarStock(int idPlaca){
	Stock obj;
	float opcion;
	FILE *p;
	p=fopen(nombre, "rb+");
	if(p==nullptr){
		return;
	}
	int pos=buscarPosicion(idPlaca);
	if(pos==-1){
		std::cout << "NO EXISTE LA PLACA EN EL ARCHIVO " << std::endl;
		fclose(p);
		return;
	}
	obj=LeerRegistro(pos);
	std::cout <<  std::endl;
	std::cout << "COLOR: " << obj.getColor() << std::endl;
	std::cout << "SOBRANTE: " << obj.getSobrante() << std::endl;
	std::cout <<  std::endl;
	std::cout << "INGRESAR EL SOBRANTE A ELIMINAR:";
	std::cout << std::endl;
	std::cout << "CANTIDAD: ";
	std::cin >> opcion;
	fseek(p, sizeof obj * pos, 0);
	obj.EliminarSobrante(opcion);
	fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return;
}

bool ArchivosStock :: AgregarSobrante (int idPlaca, float sobrante){
	Stock obj;
	FILE *p;
	p=fopen(nombre, "rb+");
	if(p==nullptr){
		return false;
	}
	int pos=buscarPosicion(idPlaca);
	if(pos==-1){
		std::cout << "NO EXISTE LA PLACA EN EL ARCHIVO " << std::endl;
		fclose(p);
		return false;
	}
	obj=LeerRegistro(pos);
	fseek(p, sizeof obj * pos, 0);
	if(sobrante>0){
		obj.setSobrante(sobrante);
	}
	fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return true;
}



