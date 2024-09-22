#pragma once
#include "placa.h"

class ArchivosPlacas{
public:
	ArchivosPlacas();
	bool AgregarRegistro(placa obj);
	int ContarRegistros();
	placa LeerRegistro(int pos);
	int buscarPosicion(int id);

private:
	char nombre [15];
};
