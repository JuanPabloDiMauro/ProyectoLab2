#pragma once

class GastoIngreso{
public:
	GastoIngreso();

	void setPrecioPlacas(float precio);
	void setPrecioObra(float precio);
	void setBalance();

	float getPrecioPlacas();
	float getPrecioObra();
	float getBalance();
private:
	float _PrecioPlacas, _PrecioObra, _Balance;
};
