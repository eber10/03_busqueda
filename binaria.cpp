#include<iostream>
using namespace std;

int Binaria(int arr[], int n, int valor)
{
	int izq, der, cen,  m, pos;
	izq=1;
	der=n;
	cen=0;
	while(izq<=der and cen==0)
	{
		m=(izq+der)/2;
		if(arr[m]==valor)
		{
			cen=1;
		}
		else if(arr[m]<valor)
		{
			izq=m+1;
		}
		else
		{
			der=m-1;
		}	
	}
	if(cen==1)
	{
		pos=m;
	}
	else
	{
		pos=-izq;
	}
	return pos;
}
       
int main()
{
	int n, valor;
	cout<<"Ingrese la cantidad de elementos del arreglo: ";
	cin>>n;
	int arreglo[n];	
	for(int i=0; i<n; i++)
	{
		cout<<"elemento"<<i+1<<":"; cin>>arreglo[i];
	}
	cout<<endl;
	cout<<"Ingrese el elemento a buscar: "; cin>>valor;
	cout<<"la posicion es: "<<Binaria( arreglo, n, valor)<<endl;
	
	return 0;
}
