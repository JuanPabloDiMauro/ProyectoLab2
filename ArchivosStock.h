#pragma once
#include "Stock.h"

class ArchivosStock{
public:
	ArchivosStock();
	bool AgregarRegistro(Stock obj);
	int ContarRegistros();
	Stock LeerRegistro(int pos);
	int buscarPosicion(int id);
	void ModificarStock(int idPlaca);
	bool AgregarSobrante (int idPlaca, float sobrante);

private:
	char nombre [15];
};
