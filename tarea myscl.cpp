#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"



using namespace std;

class estuadiante  {
private: string codigo;
	   int id = 0;
	  
public:
	estudiante() {
	}
	estudiante(string nom, string ape, string dir, int tel, string fn, string n,int i) :  {
		codigo = n;
		id = i;
	}


	void setId(int i) { id = i; }
	void setCodigo(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
	
	int getId() { return id; }
	string getCodigo() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }

	void borrar () {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string ii = to_string(id);
		if (cn.getConectar()) {
			string  borrar =
				"delete from estudiante  where id_estudiante = " + ii + "";
			const char* i = borrar.c_str();
			
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void actualizar () {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		string ii = to_string(id);
		if (cn.getConectar()) {
			string  actualizar =
				"update estudiante set codigo = '" + codigo + "', nombres='" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono =" + t + ", fecha_nacimiento='" + fecha_nacimiento + "' where id_estudiante = " + ii +"";
			const char* i = actualizar.c_str();
		
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
		string  insertar = 
			"INSERT INTO estudiante(codigo,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES ('" + codigo + "','" + nombres + "','" + apellidos + "','" + direccion + "',"+ t +",'" + fecha_nacimiento + "')";
		const char* i = insertar.c_str();
		
		q_estado = mysql_query(cn.getConectar(), i);
		if (!q_estado) {
			cout << "Ingreso Exitoso ..." << endl;
		}
		else {
			cout << " xxx Error al Ingresar  xxx" << endl;
		}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		
		if (cn.getConectar()) {
			
			cout << "------------ Datos de estudiante ------------" << endl;
			string consulta = "select * from estudiante";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5]<<"," << fila[6] <<endl;
				}
				
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};
