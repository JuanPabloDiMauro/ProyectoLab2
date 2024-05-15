#include "CalcularPlacas.h"

CalcularPlacas :: CalcularPlacas(){
	_SuperficieRecortes = 0;
	_CantPlacas = 1;
}

void CalcularPlacas :: setSuperficiePlaca(placa obj){
	_superficiePlaca = (obj.getlargo()/100) * (obj.getancho()/100);
}

void CalcularPlacas :: setSuperficieRecortes(medidas obj){
	_SuperficieRecortes += (obj.getAlturaRecorte()/100) * (obj.GetAnchoRecorte()/100) * obj.getCantRecortes();
}

void CalcularPlacas :: setCantPlacas(){
	bool bandera=true;
	float aux=_superficiePlaca;
    while(bandera == true){
    if(_superficiePlaca > _SuperficieRecortes){
        bandera = false;
        _Sobrante = _superficiePlaca - _SuperficieRecortes;
    }
    else{
        _CantPlacas ++;
        _superficiePlaca = aux * _CantPlacas;
    }
    }
}

float CalcularPlacas :: getSuperficieRecortes(){
	return _SuperficieRecortes;
}

float CalcularPlacas :: getSobrante(){
	return _Sobrante;
}

int CalcularPlacas :: getCantPlacas(){
	return _CantPlacas;
}

/// TERMINADOOOO

