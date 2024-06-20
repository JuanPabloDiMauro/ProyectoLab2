#pragma once
#include "trabajos.h"
#include "ArchivosTrabajos.h"
#include "medidas.h"
#include "ArchivosMedidas.h"
#include "placa.h"
#include "ArchivoPlacas.h"
#include "InsumosTrabajo.h"
#include "ArchivosInsumos.h"

class TrabajosManager{
public:
	void CargarTrabajos();
	void TrabajosEnEjecucion();
	void TrabajosFinalizados();
	void BorrarTrabajo();
	void ModificarTrabajo();

private:
	placa CargarPlaca();
	void CargarMedidas(placa obj, float precio);
	void CargarCliente();
	void mostrar();

	trabajos _ObjTrabajos;
	medidas _ObjMedidas;
	InsumosTrabajo _ObjInsumosTrabajo;

	ArchivosTrabajos _ObjArchiTrabajos;
	ArchivosMedidas _ObjArchiMedidas;
	ArchivosPlacas _ObjArchiPlacas;
	ArchivosInsumos _ObjArchiInsumos;
};
