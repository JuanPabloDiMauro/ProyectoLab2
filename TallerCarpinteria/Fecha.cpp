#include "Fecha.h"
#include <ctime>

int fecha :: getdia(){
    return _Dia;
}
int fecha :: getmes(){
    return _Mes;
}
int fecha :: getanio(){
    return _Anio;
}
void fecha :: setdia(int dia){
    if(dia > 0 && dia < 32){
        _Dia = dia;
    }
}
void fecha :: setmes(int mes){
    if(mes > 0 && mes < 13){
        _Mes = mes;
    }
}
void fecha :: setanio(int anio){
    _Anio = anio;
}
fecha :: fecha (int dia, int mes, int anio){
    setdia(dia);
    setmes(mes);
    setanio(anio);
}
fecha :: fecha (){
time_t t= time(NULL);
struct tm *f = localtime (&t);
_Dia = f-> tm_mday;
_Mes = f-> tm_mon+1;
_Anio = f-> tm_year + 1900;
}
