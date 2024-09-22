#pragma once
#include "medidas.h"

class ArchivosMedidas{
public:
	ArchivosMedidas ();
	bool agregarMedidas(medidas obj);
	int contarRegistro();
	medidas leerRegistro(int pos);

private:
	char nombre[15];
};
