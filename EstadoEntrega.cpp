#include "EstadoEntrega.h"

EstadoEntrega :: EstadoEntrega(){
	_Dias=0;
	_ObjCliente = Clientes();
	_IdTrabajo=0;
	_Estado = true;
}

void EstadoEntrega :: setCliente(Clientes obj){
	_ObjCliente = obj;
}

void EstadoEntrega :: setIdTrabajo(int id){
	if(id>0){
		_IdTrabajo = id;
	}
}

void EstadoEntrega :: setEstado(bool estado){
	_Estado = estado;
}

bool EstadoEntrega :: getEstado(){
	return _Estado;
}

Clientes EstadoEntrega :: getCliente(){
	return _ObjCliente;
}

int EstadoEntrega :: getTiempoFinalizacion(){
	return _Dias;
}

fecha EstadoEntrega :: getFechaFinalizacion(){
	return _FechaFinalizacion;
}

int EstadoEntrega :: getIdTrabajo(){
	return _IdTrabajo;
}

void EstadoEntrega :: setTiempoFinalizacion(){
	bool val;
	/// setear la fecha para completar el archivo
	/*_FechaFinalizacion.setdia(11);
	_FechaFinalizacion.setmes(6);
	_FechaFinalizacion.setanio(2024); */
	fecha objEstimado=_ObjCliente.getFechaEntrega();
	if(_ObjCliente.getFechaEntrega().getanio() > _FechaFinalizacion.getanio()){
		val=true;
	}else{
		val=false;
	}
	if(_ObjCliente.getFechaEntrega().getanio() == _FechaFinalizacion.getanio()){
		if(_ObjCliente.getFechaEntrega().getmes() > _FechaFinalizacion.getmes()){
			val = true;
		}
		else{
			if(_ObjCliente.getFechaEntrega().getmes() < _FechaFinalizacion.getmes()){
				val=false;
			}else{
				if(_ObjCliente.getFechaEntrega().getdia() > _FechaFinalizacion.getdia()){
					val = true;
				}
				else{
					val = false;
				}
			}
		}
	}
	if(val==true){
		while(objEstimado.getdia() != _FechaFinalizacion.getdia() || objEstimado.getmes() != _FechaFinalizacion.getmes() || objEstimado.getanio() != _FechaFinalizacion.getanio()){
		if(objEstimado.getdia() > 1){
			objEstimado.setdia(objEstimado.getdia()-1);
			_Dias--;
		}else{
			if(objEstimado.getmes() > 1){
				objEstimado.setdia(31);
				objEstimado.setmes(objEstimado.getmes()-1);
				_Dias--;
			}
			else{
				objEstimado.setdia(31);
				objEstimado.setmes(12);
				objEstimado.setanio(objEstimado.getanio()-1);
				_Dias--;
			}
		}
	}
	}else{
	while(objEstimado.getdia() != _FechaFinalizacion.getdia() || objEstimado.getmes() != _FechaFinalizacion.getmes() || objEstimado.getanio() != _FechaFinalizacion.getanio()){
		if(objEstimado.getmes() == 1 || objEstimado.getmes() == 3 || objEstimado.getmes() == 5 || objEstimado.getmes() == 7 || objEstimado.getmes() == 8 || objEstimado.getmes() == 10 || objEstimado.getmes() == 12){
			if(objEstimado.getdia() < 31){
				objEstimado.setdia(objEstimado.getdia()+1);
				_Dias++;
			}else{
				if(objEstimado.getmes() == 12){
					objEstimado.setdia(1);
					objEstimado.setmes(1);
					objEstimado.setanio(objEstimado.getanio()+1);
					_Dias++;
				}
				else{
					objEstimado.setdia(1);
					objEstimado.setmes(objEstimado.getmes()+1);
					_Dias++;
				}
			}
		}
		if(objEstimado.getmes() == 4 || objEstimado.getmes() == 6 || objEstimado.getmes() == 9 || objEstimado.getmes() == 11){
			if(objEstimado.getdia() < 30){
				objEstimado.setdia(objEstimado.getdia()+1);
				_Dias++;
			}else{
				objEstimado.setdia(1);
				objEstimado.setmes(objEstimado.getmes()+1);
				_Dias++;
				}
			}
		if(objEstimado.getmes() == 2){
			if(objEstimado.getdia() < 28){
				objEstimado.setdia(objEstimado.getdia()+1);
				_Dias++;
			}else{
				objEstimado.setdia(1);
				objEstimado.setmes(objEstimado.getmes()+1);
				_Dias++;
				}
			}
		}
		}
}


