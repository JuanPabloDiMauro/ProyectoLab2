#pragma once
#include <string>

class persona{
    public:
        persona();

        void setapellido(std::string apellido);
        void setnombre(std::string nombre);
        void setcelular(std::string celular);

        std::string getapellido();
        std::string getnombre();
		std::string getcelular();

    protected:
        char _Nombre[30], _Apellido[30], _Celular [15];
};
