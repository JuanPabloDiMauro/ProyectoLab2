#pragma once
#include "InsumosTrabajo.h"

class ArchivosInsumos{
public:
	ArchivosInsumos();
	bool AgregarRegistro(InsumosTrabajo obj);
	int ContarRegistros();
	InsumosTrabajo LeerRegistro(int pos);
	int buscarPosicion(int id);
private:
	char nombre [15];
};
