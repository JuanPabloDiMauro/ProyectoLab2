#pragma once

class placa{
    public:
        placa();

        void setcolor(const char * color);
        void setlargo(float largo);
        void setancho(float ancho);
        void setprecio(float precio);
        void setestado();

        const char * getcolor();
        float getlargo();
        float getancho();
        float getprecio();
        bool getestado();

    private:
        char _color[10];
        float _Largo, _precio, _Ancho;
        bool _Estado;
};

/// TERMINADOOOO
