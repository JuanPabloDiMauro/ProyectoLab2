#include <iostream>
using namespace std;
#include "medidas.h"
#include "presupuesto.h"
#include "Clientes.h"
#include "trabajos.h"
#include "CalcularPlacas.h"
#include "ArchivosTrabajos.h"
#include "ArchivosMedidas.h"

///CARGAS DE DATOS
void cargarCadena(char *palabra, int tamano){

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++){

        palabra[i]=cin.get();

        if (palabra[i]=='\n'){

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);

}

placa cargarPlaca(){
	placa objPlaca;
	char color[10];
	float parametro;
	cout << "DATOS DE LA PLACA A UTILIZAR" << endl;
	cout << "COLOR: ";
	cargarCadena(color, 10);
	objPlaca.setcolor(color);
	cout << "LARGO: ";
	cin >> parametro;
	objPlaca.setlargo(parametro);
	cout << "ANCHO: ";
	cin >> parametro;
	objPlaca.setancho(parametro);
	cout << "PRECIO: ";
	cin >> parametro;
	objPlaca.setprecio(parametro);

	return objPlaca;
}

///GENERAR ID
int NuevoIdTrabajo(){
	ArchivosTrabajos obj;
	int id=obj.NuevoIdTrabajo();
	return id;
}

///MODULO TRABAJOS
void nuevoTrabajo(){
	/// CUANDO ESTE LA CLASE STOCK ENVIAR EL SOBRANTE QUE ESTA EN CALCULAR PLACAS
	ArchivosTrabajos objArchiTrabajos;
	ArchivosMedidas objArchiMedidas;
	trabajos objTrabajo;
	objTrabajo.setIdTrabajo(NuevoIdTrabajo());
	CalcularPlacas objCalcularPlacas;
	presupuesto objPresupuesto;
	medidas *objMedidas;
	int n;
	float precio;
	objMedidas = new medidas [n];

	cout << "ID TRABAJO: " << objTrabajo.getIdTrabajo() << endl << endl;
	objTrabajo.setdatoscliente();
	cout << endl;
	objTrabajo.setplaca(cargarPlaca());
	objCalcularPlacas.setSuperficiePlaca(objTrabajo.getplaca());
	cout << endl;
	cout << "Cuantas medidas se van a ingresar?" << endl;
	cout << "cantidad: ";
	cin >> n;
	cout << endl;
	for(int i=0; i<n; i++){
		objMedidas[i].setIdMedidas(objTrabajo.getIdTrabajo());
		objMedidas[i].cargar();
		objCalcularPlacas.setSuperficieRecortes(objMedidas[i]);
		cout << endl;
	}

	objCalcularPlacas.setCantPlacas();

	cout << endl;
	cout << "PRECIO DEL METRO CUADRADO: ";
	cin >> precio;
	cout << endl;
	/// PRESUPUESTO
	objPresupuesto.setprecio(precio);
	objPresupuesto.setmetrocuadrado(objCalcularPlacas.getSuperficieRecortes());
	objPresupuesto.setPrecioTotal();
	/// CARGAR TRABAJO
	objTrabajo.setCantPlacas(objCalcularPlacas.getCantPlacas());
	objTrabajo.setPrecioPlacas(objTrabajo.getplaca().getprecio() * objTrabajo.getCantPlaca());
	objTrabajo.setPrecioObra(objPresupuesto.getPrecioTotal());
	objTrabajo.setEstado(true);
	objTrabajo.setEstadoDeEjecucion(1);
	system("pause");
	system("cls");
	bool val=objArchiTrabajos.agregarTrabajo(objTrabajo);
	for(int i=0; i<n; i++){
		bool val2=objArchiMedidas.agregarMedidas(objMedidas[i]);
		if(val2==false){
			val=false;
		}
	}
	if(val==true){
		cout << "REGISTRO GUARDADO CORRECTAMENTE" << endl;
	}
	for(int i=0; i<n; i++){
		objMedidas[i].~medidas();
	}
}

void TrabajosEnEjecucion(){
	ArchivosTrabajos objArchiTrabajos;
	ArchivosMedidas objArchiMedidas;
	trabajos objTrabajos;

	int cont=objArchiTrabajos.contarRegistro();
	for(int i=0; i<cont; i++){
		objTrabajos=objArchiTrabajos.leerRegistro(i);
		if(objTrabajos.getEstadoDeEjecucion()==1 && objTrabajos.getestado() == true){
			objTrabajos.mostrar();
			objArchiMedidas.listarRegistro(objTrabajos.getIdTrabajo());
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << std::endl;
		}
	}
}

void TrabajosFinalizados(){
	ArchivosTrabajos objArchiTrabajos;
	ArchivosMedidas objArchiMedidas;
	trabajos objTrabajos;

	int cont=objArchiTrabajos.contarRegistro();
	for(int i=0; i<cont; i++){
		objTrabajos=objArchiTrabajos.leerRegistro(i);
		if(objTrabajos.getEstadoDeEjecucion()==2&& objTrabajos.getestado() == true){
			objTrabajos.mostrar();
			objArchiMedidas.listarRegistro(objTrabajos.getIdTrabajo());
			std::cout << "---------------------------------------------------" << std::endl;
			std::cout << std::endl;
		}
	}
}

void BorrarTrabajo(){
	ArchivosTrabajos objArchiTrabajos;
	ArchivosMedidas objArchiMedidas;
	int id;
	bool val, val2;

	cout << "QUE REGISTRO DESEA ELIMINAR? " << endl;
	cout << "INGRESE EL ID: ";
	cin >> id;

	val=objArchiTrabajos.eliminarTrabajo(id);
	val2=objArchiMedidas.eliminarMedidas(id);

	if(val==true && val2==true){
		cout << "SE ELIMINO EL RESGISTRO CORRECTAMENTE" << endl;
	}else{
		cout << "SE CANCELO LA ELIMINACION DE REGISTROS" << endl;
	}
}

void ModificarTrabajo(){
	ArchivosTrabajos objArchiTrabajos;
	int id;
	bool val;

	cout << "ID DE LA OBRA A FINALIZAR" << endl;
	cout << "INGRESE EL ID: ";
	cin >> id;

	val=objArchiTrabajos.ModificarTrabajo(id);

	if(val==true){
		cout << "OBRA FINALIZADA" << endl;
	}else{
		cout << "LA MODIFICACION FUE CANCELADA" << endl;
	}
}



