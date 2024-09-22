#pragma once
#include "EstadoEntrega.h"
#include "ArchivoEstadoEntrega.h"

class ClientesManager{
public:
	void ClientesSinEntregar();
	void ClientesEntregaRealizada();
	void FinalizarEntrega();
	void EliminarCliente();
private:
	EstadoEntrega _ObjEstadoEntrega;
	ArchivosEstadoEntrega _ObjArchiEstadoEntrega;
};
