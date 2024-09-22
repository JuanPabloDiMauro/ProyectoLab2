#include <iostream>
using namespace std;
#include <locale.h>
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
	cout << "PRECIO OBRA: $ " << _ObjTrabajos.getPrecioObra() << endl;
	cout << "PRECIO PLACAS: $ " << _ObjTrabajos.getPrecioPlacas() << endl;

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
			cout << endl;
			for(int m=0; m<tam2; m++){
				_ObjMedidas = _ObjArchiMedidas.leerRegistro(m);
				if(_ObjMedidas.getIdTrabajo() == _ObjInsumosTrabajo.getIdTrabajo() && _ObjMedidas.getIdPlaca() == _ObjInsumosTrabajo.getIdPlaca() && _ObjTrabajos.getEstadoDeEjecucion() == true){
					//cout << endl;
					cout << "\tLARGO: " << _ObjMedidas.getAlturaRecorte() << endl;
					cout << "\tANCHO: " << _ObjMedidas.GetAnchoRecorte() << endl;
					cout << "\tCANTIDAD DE RECCORTES: " << _ObjMedidas.getCantRecortes() << endl;
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
	if(id<1 || id>cont-1){
		id=1;
	}

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
	if(tam<0){
		tam=1;
	}
	cout << endl;

	for(int i=0; i<tam; i++){
		_ObjMedidas.setIdTrabajo(_ObjTrabajos.getIdTrabajo());
		_ObjMedidas.setIdPlaca(objPlaca.getIdPlaca());
		cout << "LARGO: ";
		cin >> medida;
		if(medida>objPlaca.getlargo()){
			medida=objPlaca.getlargo();
		}
		_ObjMedidas.setAlturaRecorte(medida);
		cout << "ANCHO: ";
		cin >> medida;
		if(medida>objPlaca.getancho()){
			medida=objPlaca.getancho();
		}
		_ObjMedidas.setAnchoRecorte(medida);
		cout << "CANTIDAD DE RECORTES: ";
		cin >> cantRecortes;
		_ObjMedidas.setCantRecortes(cantRecortes);

		objCalcularPlacas.setSuperficieRecortes(_ObjMedidas);

		_ObjArchiMedidas.agregarMedidas(_ObjMedidas);
		cout << endl;
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
	setlocale(LC_CTYPE, "spanish");
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
	_ObjTrabajos.setEstado(true);
	_ObjTrabajos.setEstadoDeEjecucion(true);

	cout << "ID TRABAJO: " << _ObjTrabajos.getIdTrabajo() << endl;

	cout << endl;
	CargarCliente();
	cout << endl;
	system("pause");
	system("cls");

	cout << "CANTIDAD DE COLORES DE PLACA SOLICITADA: ";
	cin >> tam;
	if(tam<1){
		tam=1;
	}
	if(tam>10){
		tam=10;
	}
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
		if(precio<1){
			precio = objPlaca.getprecio() / 2;
		}
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

bool TrabajosManager :: ModificarTrabajo(){
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
		cout << "OBRA NO FINALIZADA - O - OBRA FINALIZADA ANTERIORMENTE";
		cout << endl;
	}

	return val;
}

