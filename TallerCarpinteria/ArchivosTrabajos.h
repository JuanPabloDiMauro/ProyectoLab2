#pragma once
#include "trabajos.h"

class ArchivosTrabajos{
public:
	ArchivosTrabajos();
	bool agregarTrabajo(trabajos obj);
	bool eliminarTrabajo(int idTrabajo);
	trabajos leerRegistro(int pos);
	int contarRegistro();
	int buscarPosicion(int idTrabajo);
	int NuevoIdTrabajo();
	bool ModificarTrabajo(int idtrabajo);

private:
	char Nombre[15];
};
