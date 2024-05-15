#pragma once
#include "medidas.h"

class ArchivosMedidas{
public:
	ArchivosMedidas ();
	bool agregarMedidas(medidas obj);
	bool eliminarMedidas(int idTrabajo);
	void listarRegistro(int idMedidas);
	int contarRegistro();

private:
	char nombre[15];
};
