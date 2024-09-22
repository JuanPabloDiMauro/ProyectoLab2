#pragma once
#include <string>

class placa{
    public:
        placa();

        void setIdPlaca(int id);
        void setcolor(std::string color);
        void setlargo(float largo);
        void setancho(float ancho);
        void setprecio(float precio);

        int getIdPlaca();
        std::string getcolor();
        float getlargo();
        float getancho();
        float getprecio();

    private:
        int _IdPlaca;
        char _color[30];
        float _Largo, _precio, _Ancho;
};
