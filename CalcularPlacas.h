#pragma once
#include "placa.h"
#include "medidas.h"

class CalcularPlacas{
public:
	CalcularPlacas();

	void setSuperficiePlaca(placa obj);
	void setSuperficieRecortes(medidas obj);
	void setCantPlacas();

	float getSuperficieRecortes();
	float getSobrante();
	int getCantPlacas();

private:
	float _superficiePlaca;
	float _SuperficieRecortes;
	int _CantPlacas;
	float _Sobrante;

};

/// TERMINADOOOO
