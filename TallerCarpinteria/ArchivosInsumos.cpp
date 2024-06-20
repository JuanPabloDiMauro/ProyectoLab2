#include<iostream>
using namespace std;
#include "ArchivosInsumos.h"
#include <cstring>

ArchivosInsumos :: ArchivosInsumos(){
	strcpy(nombre ,"InsumosTrabajos.dat");
}
bool ArchivosInsumos :: AgregarRegistro(InsumosTrabajo obj){
	FILE *p;
	p=fopen(nombre, "ab");
	if(p==nullptr){
		cout << "ERROR DE APERTURA DE ARCHIVO 1" << endl;
		return false;
	}
	bool escribio=fwrite(&obj, sizeof obj, 1, p);
	fclose(p);
	return escribio;
}

int ArchivosInsumos :: buscarPosicion(int id){
	FILE *p;
	InsumosTrabajo obj;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		cout << "ERROR DE APERTURA DE ARCHIVO 2" << endl;
		return -1;
	}
	int cont = ContarRegistros();
	for(int i=0; i<cont; i++){
		obj = LeerRegistro(i);
		fread(&obj, sizeof obj, 1, p);
		if(obj.getIdPlaca()==id){
			fclose(p);
			return i;
		}
	}
	fclose(p);
	return -1;
}

int ArchivosInsumos :: ContarRegistros(){
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		cout << "ERROR DE APERTURA DE ARCHIVO 3" << endl;
		return 0;
	}
	fseek(p, 0, 2);
	int cant=ftell(p) / sizeof (InsumosTrabajo);
	fclose(p);
	return cant;
}


InsumosTrabajo ArchivosInsumos :: LeerRegistro(int pos){
	InsumosTrabajo obj;
	obj.setIdTrabajo(-1);
	FILE *p;
	p=fopen(nombre, "rb");
	if(p==nullptr){
		return obj;
	}
	fseek(p, sizeof obj * pos, 0);
	fread(&obj, sizeof obj, 1, p);
	fclose(p);
	return obj;
}

