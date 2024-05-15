#pragma once

class persona{
    public:
        persona();

        void setapellido(const char * apellido);
        void setnombre(const char * nombre);
        void setcelular(const char * celular);

        const char * getapellido();
        const char * getnombre();
		const char * getcelular();

		void cargarPersona();
		void mostrarPersona();

    protected:
        char _Nombre[15], _Apellido[15], _Celular [15];
};
