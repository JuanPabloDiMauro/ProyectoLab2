#pragma once
#include "placa.h"


class medidas{
    public:
        medidas();

		void setAnchoRecorte(float a);
		void setAlturaRecorte(float a);
		void setCantRecortes(int cant);
		void setIdTrabajo(int id);
		void setIdPlaca(int id);

		int getIdPlaca();
		int getIdTrabajo();
		float GetAnchoRecorte();
		float getAlturaRecorte();
		int getCantRecortes();
    private:
        float _largoRecorte, _anchoRecorte;
        int _cantRecortes, _IdTrabajo, _IdPlaca;
};


