#pragma once
#include "ArchivosStock.h"
#include "ArchivoPlacas.h"
#include "ArchivosInsumos.h"
#include "Stock.h"

class StockManager{
public:
	void SobranteDePlacas();
	void EliminarSobrante();
	void AgregarSobrante();
private:

	ArchivosStock _ObjArchiStock;
	ArchivosInsumos _ObjArchiInsumos;
	ArchivosPlacas _ObjArchiPlacas;

	Stock _ObjStock;
};
