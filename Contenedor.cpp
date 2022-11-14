#include "Contenedor.h"

Contenedor::Contenedor()
{
	listaC = NULL;
	listaP = NULL;
	listaF = NULL;
	nFactura = 0;
}
Contenedor::~Contenedor()
{
}

void Contenedor::crearCliente()
{
	char nombre[40];
	char direccion[40];
	char cedula[40];
	
	cout<<"Ingrese la cedula: ";
	cin>>cedula;
	
	cout<<"Ingrese el nombre: ";
	leeOrac(nombre);
	
	cout<<"Ingrese la direccion: ";
	leeOrac(direccion);
	
	Cliente *ptrDato = new Cliente(cedula, nombre, direccion);
	if(listaC == NULL) 
	{
		listaC = new NodoC(NULL, ptrDato, NULL);	
	}
	else 
	{
		NodoC *actual = listaC;
		while (actual->getSig() != NULL )  
		{
			actual = actual->getSig() ;
		}
		actual->setSig(new NodoC(actual, ptrDato, NULL));
	}
}
void Contenedor::crearProducto()
{
	float precio;
	char codigo[40];
	char nombre[40];
	char descripcion[40];
	
	cout<<"Ingrese el codigo: "<<endl;
	leeOrac(codigo);
	cout<<"Ingrese la nombre: "<<endl;
	leeOrac(nombre);
	cout<<"Ingrese la descripcion: "<<endl;
	leeOrac(descripcion);
	cout<<"Ingrese la precio: "<<endl;
	cin>>precio;
	Producto *ptrDato = new Producto(codigo, precio, nombre, descripcion);
	if (listaP == NULL) 
	{
		listaP = new NodoP(NULL, ptrDato, NULL);
	}
	else 
	{
		NodoP *actual = listaP;
		while (actual->getSig() != NULL )  
		{
			actual = actual->getSig() ;
		}
		actual->setSig(new NodoP(actual, ptrDato, NULL));
	}
}
void Contenedor::ingresarAlInventario()
{
	NodoP *actual = listaP;
	int cantidad;
	char codigo[40];
	bool bandera = false;
	cout<<"Digite el codigo: "<<endl;
	leeOrac(codigo);
	while (actual != NULL)  
	{
		if(strcmp(actual->getDato()->getCodigo(), codigo)==0)
		{
			cout<<"Actualmente hay: "<<actual->getDato()->getCantidad()<<endl;
			cout<<"Digite la cantidad a ingresar al inventario: ";cin>>cantidad;
			actual->getDato()->sumarInventario(cantidad);
			bandera = true;
		}
		actual = actual->getSig() ;
	}
	if(bandera == false)
	cout<<"			!!!!!Error no existe el codigo digitado!!!!!"<<endl;
}
void Contenedor::crearFactura()
{
	NodoC *ListaC = listaC;
	NodoP *ListaP = listaP;
	NodoP *listaPro = NULL;
	char cedula[40];
	char nombreC[40];
	char direccion[40];
	float total = 0;
	float subtotal = 0;
	float iva = 0;
	
	NodoP *auxPro;
	int conta = 0;
	int contador = 0;
	int cantidad;
	bool bandera = false;
	bool bandera2 = false;
	bool bandera3 = false;
	bool bandera4 = false;
	char codigo[40];
	char fin[10] = "fin";
	nFactura++;
	
	while(bandera == false) //este ciclo busca la cudula del cliente
	{
		ListaC = listaC;
		if(bandera == false)
		{
			system ("cls");
			cout<<"MOTOREPUESTOS FERMIN AM								No. Factura		"<<nFactura<<endl;
			cout<<"							FACTURA DE CONTADO"<<endl;
			cout<<"Cedula: ";cin>>cedula;
		}
		while(ListaC != NULL)
		{
			if(strcmp(ListaC->getDato()->getCedula(), cedula) == 0)
			{
				strcpy(nombreC, ListaC->getDato()->getNombre());
				strcpy(direccion, ListaC->getDato()->getDireccion());
				bandera = true;
			}
			ListaC = ListaC->getSig();
		}
	}
	bandera = false;
	
	while(bandera == false) // este ingresa productos que desea comprar
	{
		if(bandera == false && contador<=10) // si no se han ingresado 10 productos o se ingreso fin como codigo
		{
			system ("cls");
			cout<<"Si desea salir digite <<    fin    >>"<<endl;
			cout<<"MOTOREPUESTOS FERMIN AM								No. Factura		"<<nFactura<<endl;
			cout<<"							FACTURA DE CONTADO"<<endl;
			cout<<"Cedula: "<<cedula<<"		Nombre: "<<nombreC<<endl;
			cout<<"Direccion: "<<direccion<<endl;
			cout<<"-------------------------------------------------------------------------------------------------"<<endl;
			cout<<"Digite codigo del producto: ";cin>>codigo;
			
			if(strcmp(fin, codigo) == 0) // si se digita fin se brinca los demas metodos y sale
			{
				bandera = false;
			}
		}
		auxPro = listaPro;
		system ("cls");
		cout<<"MOTOREPUESTOS FERMIN AM								No. Factura		"<<nFactura<<endl;
		cout<<"							FACTURA DE CONTADO"<<endl;
		cout<<"Cedula: "<<cedula<<"		Nombre: "<<nombreC<<endl;
		cout<<"Direccion: "<<direccion<<endl;
		cout<<"-------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Digite codigo del producto: "<<codigo<<"	Digite la cantidad: "; cout<<endl;
		cout<<"-------------------------------------------------------------------------------------------------"<<endl;
		cout<<"Codigo		Nombre					Precio Unit.			Precio Total"<<endl;
		cout<<"-------------------------------------------------------------------------------------------------"<<endl;
		while(auxPro != NULL) // si hay productos digitados los imprime
		{
			cout<<auxPro->getDato()->getCodigo()<<"		"<<auxPro->getDato()->getNombre()<<"					"<<auxPro->getDato()->getPrecio()<<"			"<<(auxPro->getDato()->getPrecio()*auxPro->getDato()->getCantidad())<<endl;
			auxPro = auxPro->getSig();
			conta++;
		}
		cout<<"-------------------------------------------------------------------------------------------------"<<endl;
		bool bandera5 = false;
		while(ListaP != NULL && bandera5 == false) // revisa si el codigo digitado existe
		{
			if(strcmp(ListaP->getDato()->getCodigo(), codigo) != 0)
			{
				bandera3 = true;
			}
			else if(strcmp(ListaP->getDato()->getCodigo(), codigo) == 0)
			{
				bandera3 = false;
				bandera5 = true;
			}
			ListaP = ListaP->getSig();
		}
		ListaP = listaP;
		while(bandera3 == false) // si existe el codigo digita la cantidad
		{
			bandera = false;
			ubicarCursor(60,5);cin>>cantidad;
			ubicarCursor(0,11+conta);
			while(ListaP != NULL && bandera == false) //recorre la lista de productos hasta encontrar el codigo
			{
				if(strcmp(ListaP->getDato()->getCodigo(), codigo) == 0)
				{
					if(ListaP->getDato()->compararCantidad(cantidad) == true) // si la cantidad es menor o igual a las existencias
					{														  // entra al este if y lo ingresa en la lista de productos
						if(listaPro == NULL) 
						{
							Producto *Pro = new Producto(ListaP->getDato()->getCodigo(),ListaP->getDato()->getPrecio(),ListaP->getDato()->getNombre(),ListaP->getDato()->getDescripcion());
							Pro->cantidadFactura(cantidad);
							listaPro = new NodoP(NULL, Pro, NULL);
							ListaP->getDato()->restarInventario(cantidad);
						}
						else 
						{
							NodoP *actual = listaPro;
							while(actual->getSig() != NULL )
							{
								actual = actual->getSig() ;
							}
							Producto *Pro = new Producto(ListaP->getDato()->getCodigo(),ListaP->getDato()->getPrecio(),ListaP->getDato()->getNombre(),ListaP->getDato()->getDescripcion());
							Pro->cantidadFactura(cantidad);
							actual->setSig(new NodoP(actual, Pro, NULL));
							ListaP->getDato()->restarInventario(cantidad);
						}
						bandera3 = true;
						bandera = true;
					}
					else
					{
						bandera = true;
						bandera3 = true;
						bandera4 = true;
					}	
				}
				ListaP = ListaP->getSig();
			}
		}
		bandera = false;  //reinicia los valores bool
		bandera2 = false;
		if(bandera4 == true)
		{
			bandera3 = false;
		}
		bandera4 = false;
		ListaP = listaP;
		conta = 0;
		
		if(strcmp(fin, codigo) == 0) // si el codigo es fin, pone en true para terminar la factura
			bandera = true;
		if(bandera3 == true)
			contador++;
		bandera3 = false;
		if(strcmp(fin, codigo) == 0) //calcula y muestra el monto de la factura
		{
			subtotal = 0;
			NodoP *actual = listaPro;
			while(actual != NULL)
			{
				subtotal += actual->getDato()->getPrecio() * actual->getDato()->getCantidad();
				actual = actual->getSig();
			}
			iva = (subtotal*1.13)-subtotal;
			total = subtotal+iva;
			cout<<"																Subtotal: "<<subtotal<<endl;
			cout<<"																	 IVA: "<<iva<<endl;
			cout<<"																   Total: "<<total<<endl;
		}
	}
	Factura *ptrDato = new Factura(nFactura, listaPro, cedula, nombreC, direccion); // guarda la factura
	if (listaF == NULL) 
	{
		listaF = new NodoF(NULL, ptrDato, NULL);
	}
	else 
	{
		NodoF *actual = listaF;
		while (actual->getSig() != NULL )  
		{
			actual = actual->getSig() ;
		}
		actual->setSig(new NodoF(actual, ptrDato, NULL));
	}
}
void Contenedor::verFacturas()
{
	NodoF *aux = listaF;
	while(aux != NULL)
	{
		aux->getDato()->verFactura();
		cout<<endl<<endl;
		aux = aux->getSig();
	}
}
void Contenedor::leeOrac(char *cadena)
{
	cin.ignore();
	cin.getline(cadena,40);
}
void Contenedor::ubicarCursor(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void Contenedor::listadoProductos()
{
	NodoP* aux = listaP;
	while (aux != NULL){
		cout<<"Codigo: "<<aux->getDato()->getCodigo()<<" Cantidad: "<<aux->getDato()->getCantidad()<<"	Nombre: "<<aux->getDato()->getNombre()<<"  Descripcion: "<<aux->getDato()->getDescripcion()<<"	Precio: "<<aux->getDato()->getPrecio()<<endl;
		aux = aux->getSig();
	}
}
void Contenedor::listadoClientes()
{
	NodoC* aux = listaC;
	while (aux != NULL){
		cout<<"Cedula: "<<aux->getDato()->getCedula()<<"	Nombre: "<<aux->getDato()->getNombre()<<"  Direccion: "<<aux->getDato()->getDireccion()<<endl;
		aux = aux->getSig();
	}
}
void Contenedor::guardar() // guarda cada lista en un archivo diferente
{
	if(listaC != NULL) 
	{
		FILE* archivo = fopen("Clientes.bin","wb");
		NodoC* aux = listaC;
		while(aux!=NULL)
		{
			fwrite(aux->getDato(),sizeof(Cliente),1,archivo);
			aux = aux->getSig();
		}
		fclose(archivo);
	}
	if(listaP != NULL) 
	{
		FILE* archivo = fopen("Productos.bin","wb");
		NodoP* aux = listaP;
		while(aux!=NULL)
		{
			fwrite(aux->getDato(),sizeof(Producto),1,archivo);
			aux = aux->getSig();
		}
		fclose(archivo);
	}
	if(listaF != NULL) 
	{
		FILE* archivo = fopen("Factura.bin","wb");
		NodoF* aux = listaF;
		while(aux!=NULL)
		{
			fwrite(aux->getDato(),sizeof(Factura),1,archivo);
			aux = aux->getSig();
		}
		fclose(archivo);
	}
	if(listaF != NULL) 
	{
		NodoF* aux = listaF;
		while(aux!=NULL)
		{
			aux->getDato()->guardar();
			aux = aux->getSig();
		}
	}
}
void Contenedor::recuperar()   // Recupera los archivos
{
	FILE* archivo = fopen("Clientes.bin","rb");
	if (archivo != NULL) {
		eliminarListaC();
		while (!feof(archivo)) {
			Cliente* nuevo = new Cliente();
			if (fread(nuevo,sizeof(Cliente),1,archivo)==1)
				agregarC(new NodoC(nuevo));
		}
		fclose(archivo);
	}
	
	archivo = fopen("Productos.bin","rb");
	if (archivo != NULL) 
	{
		eliminarListaP();
		while(!feof(archivo)) 
		{
			Producto* nuevo = new Producto();
			if (fread(nuevo,sizeof(Producto),1,archivo)==1)
				agregarP(new NodoP(nuevo));
		}
		fclose(archivo);
	}
	
	archivo = fopen("Factura.bin","rb");
	bool bandera = false;
	if (archivo != NULL) {
		eliminarListaF();
		while (!feof(archivo)) {
			Factura* nuevo = new Factura();
			if (fread(nuevo,sizeof(Factura),1,archivo)==1)
			{
				agregarF(new NodoF(nuevo));
				bandera = true;
			}	
		}
		fclose(archivo);
	}
	if(bandera == true)
	{
		Factura *ultimo;
		NodoF *aux = listaF;
		while(aux != NULL)
		{
			ultimo = aux->getDato();
			aux = aux->getSig();
		}
		nFactura = ultimo->nFactura;
	}
	if(bandera == true)
	{
		NodoF *aux = listaF;
		while(aux != NULL)
		{
			aux->getDato()->recuperar();
			aux = aux->getSig();
		}
	}
}
void Contenedor::eliminarListaP()
{
	NodoP *aux;
	while(listaP != NULL)
	{
		aux = listaP;
		listaP = listaP->getSig();
		delete aux;
	}
	listaP = NULL;
}
void Contenedor::eliminarListaC()
{	
	NodoC *aux;
	while(listaC != NULL)
	{
		aux = listaC;
		listaC = listaC->getSig();
		delete aux;
	}
	listaC = NULL;
}
void Contenedor::eliminarListaF()
{	
	NodoF *aux;
	while(listaF != NULL)
	{
		aux = listaF;
		listaF = listaF->getSig();
		delete aux;
	}
	listaF = NULL;
}
void Contenedor::agregarC(NodoC* nuevo)
{
	if (listaC == NULL) 
	{
		listaC = nuevo;
	} 
	else 
	{
		NodoC *aux = listaC;
		while(aux->getSig() != NULL)
		{
			aux = aux->getSig();
		}
		aux->setSig(nuevo);
		nuevo->setAnt(aux);
	}
}
void Contenedor::agregarP(NodoP* nuevo)
{
	if (listaP == NULL) 
	{
		listaP = nuevo;
	} 
	else 
	{
		NodoP *aux = listaP;
		while(aux->getSig() != NULL)
		{
			aux = aux->getSig();
		}
		aux->setSig(nuevo);
		nuevo->setAnt(aux);
	}
}
void Contenedor::agregarF(NodoF* nuevo)
{
	if (listaF == NULL) 
	{
		listaF = nuevo;
	} 
	else 
	{
		NodoF *aux = listaF;
		while(aux->getSig() != NULL)
		{
			aux = aux->getSig();
		}
		aux->setSig(nuevo);
		nuevo->setAnt(aux);
	}
}
void Contenedor::verFacturasC()
{
	NodoC *aux = listaC;
	char nombrec[40];
	while(aux != NULL)
	{
		strcpy(nombrec, aux->getDato()->getNombre());
		NodoF *fac = listaF;
		cout<<"Facturas de "<<nombrec<<endl<<endl;
		while(fac != NULL)
		{
			if(strcmp(fac->getDato()->nombreC, nombrec) == 0)
			{
				fac->getDato()->verFactura();
			}
			fac = fac->getSig();
			cout<<endl;
		}
		aux = aux->getSig();
	}
	
}
