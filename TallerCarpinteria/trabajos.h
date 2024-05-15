#pragma once
#include "Clientes.h"
#include "placa.h"

class trabajos{
    public:
        trabajos();

		void mostrar();
		void setIdTrabajo(int idTrabajo);
		void setplaca(placa Tplaca);
		void setCantPlacas(int cant);
		void setPrecioPlacas(float precio);
		void setPrecioObra(float precio);
		void setdatoscliente();
		void setEstadoDeEjecucion(int estado);
		void setEstado(bool estado);

		Clientes getdatoscliente();
		placa getplaca();
		int getCantPlaca();
		int getIdTrabajo();
		float getPrecioPlacas();
		float getPrecioObra();
		int getEstadoDeEjecucion();
		bool getestado();

    private:
        int _idTrabajo;
		Clientes _DatosCliente;
		placa _TipoPlaca;
		int _CantPlacas;
		float _PrecioPlacas;
		float _PrecioObra;
		int _EstadoDeEjecucion; /// 1-en obra 2-Terminada
		bool _estado;
};

/// TERMINADOOOO
