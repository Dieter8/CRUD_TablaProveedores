#include <mysql.h>
#include <iostream>
#include <string>
#include "Proveedor.h"
using namespace std;
void menuOpciones() {
    cout << "-------------------Bienvenido de al sistema gestor de la tabla Proveedores -------------------" << endl;
    cout << "1. Insertar nuevos datos" << endl;
    cout << "2. Visualizar los datos" << endl;
    cout << "3. Actualizar datos" << endl;
    cout << "4. Borrar datos" << endl;
    cout << "5. Salir" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "Ingrese el número de la accion que desea realizar: ";
};
int main()
{
    char cont;
    do
    {
    system("cls");
    int opcion;
    menuOpciones();
    cin >> opcion;
    system("cls");    
    switch (opcion)
    {
    case 1:
    {
        string nombreProveedor, nit,direccion, telefono;
        cin.ignore();
        cout << "-------------Insertar Proveedor-----------" << endl;
        cout << "Ingrese el nombre del proveedor: ";
        getline(cin, nombreProveedor);
        cout << "Ingrese el nit del proveedor: ";
        getline(cin, nit);
        cout << "Ingrese la direccion del proveedor: ";
        getline(cin, direccion);
        cout << "Ingrese el telefono del proveedor: ";
        getline(cin, telefono);
        Proveedor prov = Proveedor(nombreProveedor, nit, direccion, telefono);
        prov.insertarProveedor();
        system("pause");
        prov.~Proveedor();
    }
        break;
    case 2:
        {
        Proveedor prov = Proveedor();
        prov.leerProveedor();
        system("pause");
        prov.~Proveedor();
    }
        break;
    case 3:
    {
        int id;
        string nombreProveedor, nit, direccion, telefono;
        cin.ignore();
        cout << "-------------Actualizar Proveedor-----------" << endl;
        cout << "Ingrese id del proveedor a modificar: ";
        cin >> id;
        cin.ignore();
        cout << "Ingrese el nuevo nombre del proveedor: ";
        getline(cin, nombreProveedor);
        cout << "Ingrese el nuevo nit del proveedor: ";
        getline(cin, nit);
        cout << "Ingrese la nuevo direccion del proveedor: ";
        getline(cin, direccion);
        cout << "Ingrese el nuevo telefono del proveedor: ";
        getline(cin, telefono);
        Proveedor prov = Proveedor(nombreProveedor, nit, direccion, telefono);
        prov.actualizarProveedor(id);
        system("pause");
        prov.~Proveedor();
       
    }
        break;
    case 4:
    {
        int id;
        Proveedor prov = Proveedor();
        prov.leerProveedor();
        cout << "----------------------------------------------------------------------" << endl;
        cout << "----------------------------------------------------------------------" << endl;

        cout << "-------------Eliminar Proveedor-----------" << endl;
        cout << "Inserte el Id del proveedor que desea eliminar: ";
        cin >> id;
        cin.ignore();
        cout << endl;
        prov.eliminarProveedor(id);
        system("pause");
        prov.~Proveedor();
    }
        break;
    default:
        break;
    }
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Desea regresar al menu principal? S/N: ";
    cin >> cont;
    } while ((cont == 's') || (cont == 'S'));

    return 0;
}