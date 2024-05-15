#pragma once
#include "Fecha.h"
#include "persona.h"

class Clientes : public persona {
public:
	Clientes();

	void cargar();
	void mostrar();

	void setDireccion(const char * direccion);
	void setFechaEntrega();
	void setEstado(bool estado);

	const char * getDireccion();
	void getFechaEntrega();

private:
	char _Direccion[30];
	fecha _FechaEntrega;
	bool _Estado;

};
