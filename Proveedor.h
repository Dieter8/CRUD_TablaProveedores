#pragma once
#include <iostream>
#include <mysql.h>
#include <string>
#include "conexionBD.h"
using namespace std;
class Proveedor
{
private:
	string idProveedor,nombreProveedor,nit,direccion,telefono;
public:
	Proveedor(){};
	Proveedor(string _nombrProveedor, string _nit, string _direccion, string _telefono) {
		nombreProveedor = _nombrProveedor;
		nit = _nit;
		direccion = _direccion;
		telefono = _telefono;
	};
	~Proveedor(){};
	void insertarProveedor() {
		int q_estado;
		conexionBD conect = conexionBD();
		conect.abrirConexionDB();
		if (conect.getConectar()) {
			string insert = "INSERT INTO proveedores(proveedor, nit, direccion, telefono)VALUES('" + nombreProveedor + "','" + nit + "','" + direccion + "','" + telefono + "' );";
			const char* i = insert.c_str();
			q_estado = mysql_query(conect.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso" << endl;
			}
			else {
				cout << "Fallo al ingresar" << endl;
			}
		}
		else
		{
			cout << "No se pudo accesar a la información, reinicie." << endl;
		}
		conect.cerrarConexionDB();
	};
	void leerProveedor() {
		int q_estado;
		conexionBD conect = conexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		conect.abrirConexionDB();
		if (conect.getConectar()) {
				string  consulta = "select * from proveedores;";
				const char* c = consulta.c_str();
				q_estado = mysql_query(conect.getConectar(), c);
				if (!q_estado) {
					resultado = mysql_store_result(conect.getConectar());
					cout << "ID PROV.   |   PROVEEDOR   |      NIT      |   DIRECCION   |   TELEFONO" << endl;
					while (fila = mysql_fetch_row(resultado))
					{
						cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << endl;
					}
				}
				else {
					cout << "No se pudo accesar a la información, reinicie." << endl;
				}
		}
		else {
			cout << "-----------Ha ocurrido un error en la conexion-----------" << endl;
		}
		conect.cerrarConexionDB();

	};
	void eliminarProveedor(int _id) {
		int q_estado;
		conexionBD conect = conexionBD();
		conect.abrirConexionDB();
		if (conect.getConectar()) {
			string idP = to_string(_id);
			string  consulta = "delete from proveedores where (idProveedores = " + idP + ");";
			const char* c = consulta.c_str();
			q_estado = mysql_query(conect.getConectar(), c);
			if (!q_estado) {
				cout << "Informacion eliminada satisfactoriamente"<<endl;
			}
			else {
				cout << "No se pudo accesar a la información, reinicie." << endl;
			}
		}
		else {
			cout << "-----------Ha ocurrido un error en la conexion-----------" << endl;
		}
		conect.cerrarConexionDB();
	};
	void actualizarProveedor(int _id) {
		int q_estado;
		conexionBD conect = conexionBD();
		conect.abrirConexionDB();
		if (conect.getConectar()) {
			string update = "UPDATE proveedores SET proveedor = '" + nombreProveedor + "', nit = '" + nit + "', direccion = '" + direccion + "', telefono = '" + telefono + "' WHERE (idProveedores='"+ to_string(_id) + "');";
			const char* i = update.c_str();
			q_estado = mysql_query(conect.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso" << endl;
			}
			else {
				cout << "Fallo al ingresar" << endl;
			}
		}
		else
		{
			cout << "No se pudo accesar a la información, reinicie." << endl;
		}
		conect.cerrarConexionDB();
	};

};