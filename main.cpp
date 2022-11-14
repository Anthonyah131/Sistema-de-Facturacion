#include <iostream>
#include <conio.h>
#include "Contenedor.h"

using namespace std;

int main(int argc, char** argv) {
	Contenedor *contenedor = new Contenedor();
	int op;
	contenedor->recuperar();
	do
	{
		cout<<"*******************	Menu principal	*******************"<<endl<<endl;
		cout<<"1->	Ingresar un producto al sistema."<<endl;
		cout<<"2->	Ingresar un cliente al sistema."<<endl;
		cout<<"3->	Ingresar un producto al inventario."<<endl;
		cout<<"4->	Realizar una venta."<<endl;
		cout<<"5->	Ver listado de productos."<<endl;
		cout<<"6->	Ver listado de clientes."<<endl;
		cout<<"7->	Ver listado de facturas."<<endl;
		cout<<"8->	Ver ventas por cliente."<<endl;
		cout<<"9->	Guardar listados."<<endl;
		cout<<"10->	Salir."<<endl;
		cout<<"Digita: ";cin>>op;
		system ("cls");
		switch(op){
			
			case 1:
				contenedor->crearProducto();
				getch();
				system ("cls");
				break;
			
			case 2:
				contenedor->crearCliente();
				getch();
				system ("cls");
				break;
			
			case 3:
				contenedor->ingresarAlInventario();
				getch();
				system ("cls");
				break;
			
			case 4:
				contenedor->crearFactura();
				getch();
				system ("cls");
				break;
			
			case 5:
				contenedor->listadoProductos();
				getch();
				system ("cls");
				break;
			
			case 6:
				contenedor->listadoClientes();
				getch();
				system ("cls");
				break;
			
			case 7:
				contenedor->verFacturas();
				getch();
				system ("cls");
				break;
			
			case 8:
				contenedor->verFacturasC();
				getch();
				system ("cls");
				break;
			
			case 9:
				contenedor->guardar();
				getch();
				system ("cls");
				break;	
		}
	}while(op != 10);
	return 0;
}
