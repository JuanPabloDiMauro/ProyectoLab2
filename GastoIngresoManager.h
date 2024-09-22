#pragma once
#include "GastoIngreso.h"

class GastoIngresoManager{
public:
	void BalanceMensual();
	void BalanceAnual();
private:
	GastoIngreso _ObjGastoIngreso;
};
