#pragma once

class presupuesto{
    public:
        presupuesto();

        void setmetrocuadrado(float metrocuadrado);
        void setprecio(float precio);
        void setPrecioPlacas(int CantPlacas);
		void setPrecioObra();

        float getPrecioPlacas();
		float getPrecioObra();

    private:
        float _metroCuadrado, _precio;
        float _PrecioPlaca, _PrecioObra;
};
