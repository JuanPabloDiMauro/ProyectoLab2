#pragma once
#include "EstadoEntrega.h"

class ArchivosEstadoEntrega{
public:
	ArchivosEstadoEntrega();
	bool AgregarRegistro(EstadoEntrega obj);
	int ContarRegistros();
	EstadoEntrega LeerRegistro(int pos);
	int buscarPosicion(int id);
	bool EliminarRegistro(int id);
private:
	char _Nombre[15];
};
