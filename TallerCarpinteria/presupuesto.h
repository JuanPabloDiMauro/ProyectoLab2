#pragma once

class presupuesto{
    public:
        presupuesto();

        void setmetrocuadrado(float metrocuadrado);
        void setprecio(float precio);
        void setPrecioTotal();

        float getPrecioTotal();
        float getmetrocuadrado();
        float getprecio();

    private:
        float _metroCuadrado, _precio, _PrecioTotal;
};
