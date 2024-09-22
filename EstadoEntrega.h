#pragma once
#include "Clientes.h"
#include "Fecha.h"

class EstadoEntrega{
public:
	EstadoEntrega();

	void setCliente(Clientes obj);
	void setTiempoFinalizacion();
	void setIdTrabajo(int id);
	void setEstado(bool estado);

	bool getEstado();
	Clientes getCliente();
	int getTiempoFinalizacion();
	fecha getFechaFinalizacion();
	int getIdTrabajo();
private:
	int _IdTrabajo;
	Clientes _ObjCliente;
	int _Dias;
	fecha _FechaFinalizacion;
	bool _Estado;
};
