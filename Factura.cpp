#include "Factura.h"

Factura::Factura(int cont, NodoP* listapro, char *_cedula,char *_nombre,char *_direccion)
{	
	listaPro = listapro;
	strcpy(cedula, _cedula);
	strcpy(nombreC, _nombre);
	strcpy(direccion, _direccion);
	nFactura = cont;
}
Factura::Factura()
{
	listaPro = NULL;
}
Factura::~Factura()
{
}

void Factura::verFactura()
{
	float subtotal, iva, total;
	system ("cls");
	cout<<"MOTOREPUESTOS FERMIN AM								No. Factura		"<<nFactura<<endl;
	cout<<"							FACTURA DE CONTADO"<<endl;
	cout<<"Cedula: "<<cedula<<"		Nombre: "<<nombreC<<endl;
	cout<<"Direccion: "<<direccion<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Digite codigo del producto:			Digite la cantidad: "<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Codigo		Nombre					Precio Unit.			Precio Total"<<endl;
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	NodoP *auxPro = listaPro;
	while(auxPro != NULL)
	{
		cout<<auxPro->getDato()->getCodigo()<<"		"<<auxPro->getDato()->getNombre()<<"					"<<auxPro->getDato()->getPrecio()<<"			"<<(auxPro->getDato()->getPrecio()*auxPro->getDato()->getCantidad())<<endl;
		auxPro = auxPro->getSig();
	}
	cout<<"-------------------------------------------------------------------------------------------------"<<endl;
	NodoP *actual = listaPro;
	while(actual != NULL)
	{
		subtotal += actual->getDato()->getPrecio() * actual->getDato()->getCantidad();
		actual = actual->getSig();
	}
	iva = (subtotal*1.13)-subtotal;
	total = subtotal+iva;
	cout<<"																Subtotal: "<<subtotal<<endl;
	cout<<"																     IVA: "<<iva<<endl;
	cout<<"																   Total: "<<total<<endl;
}
void Factura::ubicarCursor(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void Factura::guardar()
{
	if(listaPro != NULL) 
	{
		stringstream cadena;
		cadena<<nFactura<<endl;
		string newstring = cadena.str();
		string rutaArchivo = newstring+".bin";
		cout<<rutaArchivo<<endl;
		FILE* archivo = fopen(rutaArchivo.c_str(),"wb");
		NodoP* aux = listaPro;
		while(aux!=NULL)
		{
			
			fwrite(aux->getDato(),sizeof(Producto),1,archivo);
			aux = aux->getSig();
		}
		fclose(archivo);
	}
}
void Factura::recuperar()
{
	stringstream cadena;
	cadena<<nFactura<<endl;
	string newstring = cadena.str();
	string rutaArchivo = newstring+".bin";
	FILE* archivo = fopen(rutaArchivo.c_str(),"rb");
	if (archivo != NULL) 
	{
		eliminarListaP();
		while (!feof(archivo)) 
		{
			Producto* nuevo = new Producto();
			if (fread(nuevo,sizeof(Producto),1,archivo)==1)
			{
				agregarP(new NodoP(nuevo));
			}	
		}
		fclose(archivo);
	}
}
void Factura::eliminarListaP()
{
	NodoP *aux;
	while(listaPro != NULL)
	{
		aux = listaPro;
		listaPro = listaPro->getSig();
		delete aux;
	}
	listaPro = NULL;
}
void Factura::agregarP(NodoP* nuevo)
{
	if (listaPro == NULL) 
	{
		listaPro = nuevo;
	} 
	else 
	{
		NodoP *aux = listaPro;
		while(aux->getSig() != NULL)
		{
			aux = aux->getSig();
		}
		aux->setSig(nuevo);
		nuevo->setAnt(aux);
	}
}
