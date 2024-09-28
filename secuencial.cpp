#include<iostream>
using namespace std;
int busqueda_SecuencialDes(int arr[], int n, int valor)
{
	int pos, i;
	pos=0;
	i=1;
	while(i<=n and arr[i]!=valor)
	{
		i=i+1;
	}
	if(i<=n)
	{
		pos=i;
	}
	else
	{
		return pos;		
	}
}

int busqueda_SecuencialOr(int arr[], int n, int valor)
{
	int i, pos;
	i=1;
	while(i<=n and arr[i]<valor)
	{
		i=i+1;
	}
	if(i>n or arr[i]!=valor)
	{
		pos=-i;
	}
	else
	{
		pos=i;		
	}
	return pos;
	 
}

int main()
{
	
	int op;
    bool salir=false;
	do{
		cout<<"  busqueda secuencial "<<endl;
        cout<<"-----------------------"<<endl;
		cout<<"1. Datos desordenados. "<<endl;
		cout<<"2. Datos ordenados. "<<endl;
		cout<<"3. Salir del programa. "<<endl;
        cout<<"-----------------------"<<endl;
		cout<<"Ingrese una opcion: "; cin>>op;
		switch(op)
		{
			case 1:
				{
					int n;
					int num;
					cout<<"Ingrese la cantidad de elementos: "; cin>>n;
					int arreglo[n];
					for(int i=0; i<n; i++)
					{
						cout<<"elemento"<<i+1<<":"; cin>>arreglo[i];
					}
					cout<<endl;
					cout<<"Ingrese el valor a buscar: "; cin>>num;
					cout<<"la posicion del elemento es: "<<busqueda_SecuencialDes(arreglo, n, num)<<endl;
					break;
				}
			case 2:
				{
					int n;
					int num;
					cout<<"Ingrese la cantidad de elementos: "; cin>>n;
					int arreglo[n];
					for(int i=0; i<n; i++)
					{
						cout<<"elemento"<<i+1<<":"; cin>>arreglo[i];
					}
					cout<<endl;
					cout<<"Ingrese el valor a buscar: "; cin>>num;
					cout<<"la posicion del elemento es: "<<busqueda_SecuencialOr(arreglo, n, num)<<endl;					
					break;
				}
			case 3: salir=true; break;
			default: break;
		}
		
	}while(!salir);
	
	return 0;
}