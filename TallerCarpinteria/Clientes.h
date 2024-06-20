#pragma once
#include "Fecha.h"
#include "persona.h"
#include <string>

class Clientes : public persona {
public:
	Clientes();

	void setDireccion(std::string direccion);
	void setFechaEntrega(int dia, int mes, int anio);
	void setEstado(bool estado);

	std::string getDireccion();
	fecha getFechaEntrega();

private:
	char _Direccion[30];
	fecha _FechaEntrega;
	bool _Estado;

};
