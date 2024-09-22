#pragma once

class InsumosTrabajo{
public:
	InsumosTrabajo();

	void setIdPlaca(int id);
	void setIdTrabajo(int id);
	void setCantPlacas(int cant);
	void setSobrante(float sobrante);

	int getIdPlaca();
	int getIdTrabajo();
	int getCantPlacas();
	float getSobrante();

private:
	int _IdTrabajo, _IdPlaca, _CantPlacas;
	float _Sobrante;
};
