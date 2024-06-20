#include <iostream>
using namespace std;
#include "trabajosManager.h"
#include "CalcularPlacas.h"
#include "Clientes.h"
#include "presupuesto.h"

void TrabajosManager :: mostrar(){
	int tam, pos, tam2;
	placa ObjPlaca;
	cout << "-----------------------------------------------------" << endl << endl;
	cout << "ID TRABAJO: " << _ObjTrabajos.getIdTrabajo() << endl;
	cout << "DATOS DE CLIENTE: " << endl;
	cout << "NOMBRE: " << _ObjTrabajos.getdatoscliente().getnombre() << endl;
	cout << "APELLIDO: " << _ObjTrabajos.getdatoscliente().getapellido() << endl;
	cout << "CELULAR: " << _ObjTrabajos.getdatoscliente().getcelular() << endl;
	cout << "DIRECCION: " << _ObjTrabajos.getdatoscliente().getDireccion() << endl;
	cout << "FECHA DE ENTREGA: " << _ObjTrabajos.getdatoscliente().getFechaEntrega().getdia() << "/";
	cout << _ObjTrabajos.getdatoscliente().getFechaEntrega().getmes() << "/";
	cout << _ObjTrabajos.getdatoscliente().getFechaEntrega().getanio() << endl;
	cout << "PRECIO OBRA: " << _ObjTrabajos.getPrecioObra() << endl;
	cout << "PRECIO PLACAS: " << _ObjTrabajos.getPrecioPlacas() << endl;

	tam = _ObjArchiInsumos.ContarRegistros();
	tam2=_ObjArchiMedidas.contarRegistro();
	for(int i=0; i<tam; i++){
		_ObjInsumosTrabajo = _ObjArchiInsumos.LeerRegistro(i);
		if(_ObjInsumosTrabajo.getIdTrabajo() == _ObjTrabajos.getIdTrabajo()){
			pos = _ObjArchiPlacas.buscarPosicion(_ObjInsumosTrabajo.getIdPlaca());
			ObjPlaca = _ObjArchiPlacas.LeerRegistro(pos);
			cout << endl;
			cout << "PLACA: " << ObjPlaca.getcolor() << endl;
			cout << "CANTIDAD DE PLACAS: " << _ObjInsumosTrabajo.getCantPlacas() << endl;
			cout << "SOBRANTE: " << _ObjInsumosTrabajo.getSobrante() << endl;
			for(int m=0; m<tam2; m++){
				_ObjMedidas = _ObjArchiMedidas.leerRegistro(m);
				if(_ObjMedidas.getIdTrabajo() == _ObjInsumosTrabajo.getIdTrabajo() && _ObjMedidas.getIdPlaca() == _ObjInsumosTrabajo.getIdPlaca()){
					cout << endl;
					cout << "LARGO: " << _ObjMedidas.getAlturaRecorte() << endl;
					cout << "ANCHO: " << _ObjMedidas.GetAnchoRecorte() << endl;
					cout << "CANTIDAD DE RECCORTES: " << _ObjMedidas.getCantRecortes() << endl;
					cout << endl;
				}
			}
		}
	}

}

placa TrabajosManager :: CargarPlaca(){
	int id, pos;
	placa obj;
	int cont=_ObjArchiPlacas.ContarRegistros();
	for(int i=0; i<cont; i++){
		obj = _ObjArchiPlacas.LeerRegistro(i);
		cout << obj.getcolor() << " -- ID = ";
		cout << obj.getIdPlaca();
		cout << endl;
	}
	cout << endl;
	cout << "ID PLACA A UTILIZAR: ";
	cin >> 	id;

	pos=_ObjArchiPlacas.buscarPosicion(id);
	obj=_ObjArchiPlacas.LeerRegistro(pos);
	_ObjInsumosTrabajo.setIdPlaca(id);
	_ObjInsumosTrabajo.setIdTrabajo(_ObjTrabajos.getIdTrabajo());

	return obj;
}

void TrabajosManager :: CargarMedidas(placa objPlaca, float precio){
	int tam, cantRecortes;
	float medida;
	CalcularPlacas objCalcularPlacas;
	presupuesto objPresupuesto;

	objCalcularPlacas.setSuperficiePlaca(objPlaca);

	cout << "INGRESAR LA CANTIDAD DE MEDIDAS: ";
	cin >> tam;
	cout << endl;

	for(int i=0; i<tam; i++){
		_ObjMedidas.setIdTrabajo(_ObjTrabajos.getIdTrabajo());
		_ObjMedidas.setIdPlaca(objPlaca.getIdPlaca());
		cout << "LARGO: ";
		cin >> medida;
		_ObjMedidas.setAlturaRecorte(medida);
		cout << "ANCHO: ";
		cin >> medida;
		_ObjMedidas.setAnchoRecorte(medida);
		cout << "CANTIDAD DE RECORTES: ";
		cin >> cantRecortes;
		_ObjMedidas.setCantRecortes(cantRecortes);

		objCalcularPlacas.setSuperficieRecortes(_ObjMedidas);

		_ObjArchiMedidas.agregarMedidas(_ObjMedidas);
	}

	objCalcularPlacas.setCantPlacas();

	objPresupuesto.setprecio(objPlaca.getprecio());
	objPresupuesto.setPrecioPlacas(objCalcularPlacas.getCantPlacas());
	objPresupuesto.setmetrocuadrado(objCalcularPlacas.getSuperficieRecortes());
	objPresupuesto.setprecio(precio);
	objPresupuesto.setPrecioObra();

	_ObjTrabajos.setPrecioPlacas(objPresupuesto.getPrecioPlacas());
	_ObjTrabajos.setPrecioObra(objPresupuesto.getPrecioObra());

	_ObjInsumosTrabajo.setCantPlacas(objCalcularPlacas.getCantPlacas());
	_ObjInsumosTrabajo.setSobrante(objCalcularPlacas.getSobrante());

}

void TrabajosManager :: CargarCliente(){
	Clientes ObjClientes;
	string datos;
	int dia, mes, anio;
	cout << "--CLIENTE--" << endl << endl;
	cout << "NOMBRE: ";
	cin.ignore();
	getline(cin, datos);
	ObjClientes.setnombre(datos);
	cout << "APELLIDO: ";
	getline(cin, datos);
	ObjClientes.setapellido(datos);
	cout << "CELULAR: ";
	getline(cin, datos);
	ObjClientes.setcelular(datos);
	cout << "DIRECCION: ";
	getline(cin, datos);
	ObjClientes.setDireccion(datos);
	cout << endl << "--FECHA DE ENTREGA--" << endl << endl;
	cout << "DIA: ";
	cin >> dia;
	cout << "MES: ";
	cin >> mes;
	cout << "AÑO: ";
	cin >> anio;
	ObjClientes.setFechaEntrega(dia, mes, anio);
	ObjClientes.setEstado(true);

	_ObjTrabajos.setdatoscliente(ObjClientes);
}

void TrabajosManager :: CargarTrabajos(){
	placa objPlaca;
	int tam;
	float precio;

	_ObjTrabajos.setIdTrabajo(_ObjArchiTrabajos.NuevoIdTrabajo());

	cout << "ID TRABAJO: " << _ObjTrabajos.getIdTrabajo() << endl;

	cout << endl;
	CargarCliente();
	cout << endl;
	system("pause");
	system("cls");

	cout << "CANTIDAD DE COLORES DE PLACA SOLICITADA: ";
	cin >> tam;
	system("pause");
	system("cls");

	for(int i=0; i<tam; i++){

		objPlaca = CargarPlaca();
		system("pause");
		system("cls");
		cout << objPlaca.getcolor() << " --- $ ";
		cout << objPlaca.getprecio();
		cout << endl;
		cout << endl;
		cout << "VALOR DEL METRO CUADRADO: $ ";
		cin >> precio;
		cout << endl;
		CargarMedidas(objPlaca, precio);
		cout << endl;
		_ObjArchiInsumos.AgregarRegistro(_ObjInsumosTrabajo);
		system("pause");
		system("cls");
	}

	_ObjArchiTrabajos.agregarTrabajo(_ObjTrabajos);

}

void TrabajosManager :: TrabajosEnEjecucion(){
	int cont=_ObjArchiTrabajos.contarRegistro();

	for(int i=0; i<cont; i++){
		_ObjTrabajos = _ObjArchiTrabajos.leerRegistro(i);
		if(_ObjTrabajos.getEstadoDeEjecucion() == true && _ObjTrabajos.getestado() == true){
			mostrar();
		}
	}
}

void TrabajosManager :: TrabajosFinalizados(){
	int cont=_ObjArchiTrabajos.contarRegistro();

	for(int i=0; i<cont; i++){
		_ObjTrabajos = _ObjArchiTrabajos.leerRegistro(i);
		if(_ObjTrabajos.getEstadoDeEjecucion() == false && _ObjTrabajos.getestado() == true){
			mostrar();
		}
	}
}

void TrabajosManager :: BorrarTrabajo(){
	int id;
	bool val;
	cout << "INGRESE EL ID TRABAJO A BORRAR: ";
	cin >> id;
	val=_ObjArchiTrabajos.eliminarTrabajo(id);
	if(val==true){
		cout << "TRABAJO ELIMINADO DEL PROGRAMA" << endl;
	}
	else{
		cout << "NO SE ELIMINO EL TRABAJO DEL PROGRAMA" << endl;
	}
}

void TrabajosManager :: ModificarTrabajo(){
	int id;
	bool val;
	cout << "INGRESAR ID TRABAJO: ";
	cin >> id;
	val=_ObjArchiTrabajos.ModificarTrabajo(id);
	if(val==true){
		cout << endl;
		cout << "OBRA FINALIZADA !";
		cout << endl;
	}else{
		cout << endl;
		cout << "OBRA NO FINALIZADA";
		cout << endl;
	}
}

