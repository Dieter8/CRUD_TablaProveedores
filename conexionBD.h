#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class conexionBD
{
private:
	MYSQL* conectar;
public:
	conexionBD(){};
	void abrirConexionDB() {
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "bdmysql", "dbempresa", 3306, NULL, 0);
	}
	MYSQL* getConectar() {
		return conectar;
	}
	void cerrarConexionDB() {
		mysql_close(conectar);
	}
};


