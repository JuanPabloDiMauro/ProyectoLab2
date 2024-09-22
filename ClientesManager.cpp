#include <iostream>
#include "ClientesManager.h"
#include "ArchivoEstadoEntrega.h"
#include "ArchivosTrabajos.h"
#include "trabajos.h"

void ClientesManager :: ClientesSinEntregar(){
	ArchivosTrabajos objArchi;
	trabajos objTrabajos;
	int cont=objArchi.contarRegistro();
	for(int i=0; i<cont; i++){
		objTrabajos = objArchi.leerRegistro(i);
		if(objTrabajos.getEstadoDeEjecucion()==true && objTrabajos.getestado() == true){
			std::cout << "ID TRABAJO: " << objTrabajos.getIdTrabajo() << std::endl;
			std::cout << "NOMBRE: " << objTrabajos.getdatoscliente().getnombre() << " , " << objTrabajos.getdatoscliente().getapellido() << std::endl;
			std::cout << "DIRECCION: " << objTrabajos.getdatoscliente().getDireccion() << std::endl;
			std::cout << "FECHA DE ENTREGA: " << objTrabajos.getdatoscliente().getFechaEntrega().getdia() << "/";
			std::cout << objTrabajos.getdatoscliente().getFechaEntrega().getmes() << "/";
			std::cout << objTrabajos.getdatoscliente().getFechaEntrega().getanio() << std::endl;
			std::cout << "NUMERO: " << objTrabajos.getdatoscliente().getcelular() << std::endl;
			std::cout << "--------------------------------------------------------------" << std::endl;
		}
	}
}

void ClientesManager :: ClientesEntregaRealizada(){
	int cont = _ObjArchiEstadoEntrega.ContarRegistros();
	for(int i=0; i<cont; i++){
		_ObjEstadoEntrega=_ObjArchiEstadoEntrega.LeerRegistro(i);
		if(_ObjEstadoEntrega.getEstado() == true){
		std::cout << "ID TRABAJO: " << _ObjEstadoEntrega.getIdTrabajo() << std::endl;
		std::cout << "NOMBRE: " << _ObjEstadoEntrega.getCliente().getnombre() << " , " << _ObjEstadoEntrega.getCliente().getapellido() << std::endl;
		std::cout << "DIRECCION: " << _ObjEstadoEntrega.getCliente().getDireccion() << std::endl;
		std::cout << "FECHA DE ENTREGA ESTIMADA: " << _ObjEstadoEntrega.getCliente().getFechaEntrega().getdia() << "/";
		std::cout << _ObjEstadoEntrega.getCliente().getFechaEntrega().getmes() << "/";
		std::cout << _ObjEstadoEntrega.getCliente().getFechaEntrega().getanio() << std::endl;
		std::cout << std::endl;
		std::cout << "FECHA DE ENTREGA REALIZADA: " << _ObjEstadoEntrega.getFechaFinalizacion().getdia() << "/";
		std::cout << _ObjEstadoEntrega.getFechaFinalizacion().getmes() << "/";
		std::cout << _ObjEstadoEntrega.getFechaFinalizacion().getanio() << std::endl;
		std::cout << std::endl;
		if(_ObjEstadoEntrega.getTiempoFinalizacion()==0){
			std::cout << "SE REALIZO LA ENTREGA EN EL TIEMPO PACTADO" << std::endl;
		}else{
			if(_ObjEstadoEntrega.getTiempoFinalizacion() > 0){
				std::cout << "SE REALIZO LA ENTREGA FUERA DE TIEMPO" << std::endl;
				std::cout << "ATRASO DE " << _ObjEstadoEntrega.getTiempoFinalizacion() << " DIAS" << std::endl;
			}
			else{
				std::cout << "SE REALIZO LA ENTREGA ANTES DE TIEMPO" << std::endl;
				std::cout << "ADELANTO DE " << _ObjEstadoEntrega.getTiempoFinalizacion() * -1 << " DIAS" << std::endl;
			}
		}

		std::cout << "--------------------------------------------------------------" << std::endl;
		}
	}
}

void ClientesManager :: FinalizarEntrega(){
	ArchivosTrabajos objArchi;
	trabajos objTrabajos;
	bool val;

	int cont=objArchi.contarRegistro();
	int cant = _ObjArchiEstadoEntrega.ContarRegistros();

	for(int i=0; i<cont; i++){
		val=false;
		objTrabajos = objArchi.leerRegistro(i);
		if(objTrabajos.getEstadoDeEjecucion()==false){
			if(cant<1){
				_ObjEstadoEntrega.setIdTrabajo(objTrabajos.getIdTrabajo());
				_ObjEstadoEntrega.setCliente(objTrabajos.getdatoscliente());
				_ObjEstadoEntrega.setTiempoFinalizacion();

				_ObjArchiEstadoEntrega.AgregarRegistro(_ObjEstadoEntrega);
			}else{
				for(int m=0; m<cant; m++){
					_ObjEstadoEntrega = _ObjArchiEstadoEntrega.LeerRegistro(i);
					if(_ObjEstadoEntrega.getIdTrabajo() == objTrabajos.getIdTrabajo()){
						val=true;
					}
				}
				if(val==false){
					_ObjEstadoEntrega.setIdTrabajo(objTrabajos.getIdTrabajo());
					_ObjEstadoEntrega.setCliente(objTrabajos.getdatoscliente());
					_ObjEstadoEntrega.setTiempoFinalizacion();

					_ObjArchiEstadoEntrega.AgregarRegistro(_ObjEstadoEntrega);
				}
			}
		}
	}
}

void ClientesManager :: EliminarCliente(){
	int id;
	bool val;
	std::cout << "ELIMINAR CLIENTE DEL PROGRAMA: " << std::endl;
	std::cout << "INGRESAR ID: ";
	std::cin >> id;
	val=_ObjArchiEstadoEntrega.EliminarRegistro(id);
	if(val==true){
		std::cout << "SE ELIMINO EL REGISTRO ! " << std::endl;
	}else{
		std::cout << "NO SE ELIMINO EL REGISTRO - o - REGISTRO ELIMINADO ANTERIORMENTE" << std::endl;
	}
}
