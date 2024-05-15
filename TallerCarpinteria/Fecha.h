#pragma once

class fecha {

    public:

        void Cargar();
        void mostrar();

        int getdia();
        int getmes();
        int getanio();

        void setdia(int dia);
        void setmes(int mes);
        void setanio(int anio);

        fecha(int dia, int mes, int anio);
        fecha();
    private:
        int _Dia, _Mes, _Anio;

};
