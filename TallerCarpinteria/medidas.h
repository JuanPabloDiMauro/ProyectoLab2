#pragma once
#include "placa.h"

class medidas{
    public:
        medidas();

        void cargar();
		void mostrar();
		void setAnchoRecorte(float a);
		void setAlturaRecorte(float a);
		void setCantRecortes(int cant);
		void setIdMedidas(int idmedidas);
		void setEstado(bool estado);

		int getIdMedidas();
		float GetAnchoRecorte();
		float getAlturaRecorte();
		int getCantRecortes();

		~medidas();
    private:
        float _largoRecorte, _anchoRecorte;
        int _cantRecortes, _IdMedidas;
        bool _Estado;
};

/// TERMINADOOOO
