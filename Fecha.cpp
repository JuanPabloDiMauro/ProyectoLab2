#include "Fecha.h"
#include <ctime>
fecha :: fecha(int dia, int mes, int anio){
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
    }else{
		_Dia = 1;
    }
}
void fecha :: setmes(int mes){
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        _Mes = mes;
        if(_Dia > 31){
			_Dia = 31;
        }
    }
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        _Mes = mes;
        if(_Dia > 30){
			_Dia = 30;
        }
    }
    if(mes == 2){
        _Mes = mes;
        if(_Dia > 29){
			_Dia = 29;
        }
    }
}
void fecha :: setanio(int anio){
    _Anio = anio;
    float aux, aux2;
    if(anio>2020 && anio < 2040){
		_Anio = anio;
    }
    else{
		_Anio=2024;
    }
    if(_Dia==29 && _Mes==2){
        aux = anio % 4;
        if(aux==0){
            aux = anio % 100;
            aux2 = anio % 400;
            if(aux == 0 && aux2 != 0){
                _Dia = 28;
                _Mes = 2;
                _Anio = anio;
            }else{
				_Anio = anio;
            }
		}else{
			_Dia = 28;
			_Mes = 2;
			_Anio = anio;
		}
	}
}
