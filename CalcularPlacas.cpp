#include "CalcularPlacas.h"

CalcularPlacas :: CalcularPlacas(){
	_Sobrante = 0;
	_superficiePlaca = 0;
	_SuperficieRecortes = 0;
	_CantPlacas = 1;
}

void CalcularPlacas :: setSuperficiePlaca(placa obj){
	if(obj.getlargo() > 0 && obj.getancho() > 0){
		_superficiePlaca = (obj.getlargo()/100) * (obj.getancho()/100);
	}
}

void CalcularPlacas :: setSuperficieRecortes(medidas obj){
	if(obj.getAlturaRecorte()>0 && obj.GetAnchoRecorte() > 0 && obj.getCantRecortes()>0){
		_SuperficieRecortes += (obj.getAlturaRecorte()/100) * (obj.GetAnchoRecorte()/100) * obj.getCantRecortes();
	}
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



