#pragma once
#include "Clientes.h"
#include "InsumosTrabajo.h"

class trabajos{
    public:
        trabajos();

		void setIdTrabajo(int idTrabajo);
		void setdatoscliente(Clientes DatosCliente);
		void setEstadoDeEjecucion(bool estado);
		void setEstado(bool estado);
		void setPrecioPlacas(float PrecioPlacas);
		void setPrecioObra(float PrecioObra);

		float getPrecioPlacas();
		float getPrecioObra();
		Clientes getdatoscliente();
		int getIdTrabajo();
		bool getEstadoDeEjecucion();
		bool getestado();

    private:
        int _idTrabajo;
        float _PrecioPlacas, _PrecioObra;
		Clientes _DatosCliente;
		bool _EstadoDeEjecucion; /// true-en obra false-Terminada
		bool _estado;
};
