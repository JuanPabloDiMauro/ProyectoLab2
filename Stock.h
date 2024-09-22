#pragma once
#include <string>

class Stock{
public:
	Stock();

	void setIdPlaca(int id);
	void setColor(std::string color);
	void setSobrante(float sobrante);
	void EliminarSobrante(float sobrante);

	int getIdPlaca();
	std::string getColor();
	float getSobrante();
private:
	int _IdPlaca;
	char _Color[30];
	float _Sobrante;
};
