#include <iostream>
#include <string>
using namespace std;
struct fecha 
{
    int dia;
    int mes;
    int anio;
};
struct personal 
{
    string DNI;
    string nombres;
    fecha fechaNacimiento;
};
int compararFechas(fecha f1, fecha f2) 
{
    if (f1.anio!=f2.anio) 
	{
        return f1.anio-f2.anio; 
        
    }else if (f1.mes!=f2.mes){
    	
        return f1.mes-f2.mes;
		   
    } 
	else
	{
        return f1.dia-f2.dia;   
    }
}
void ordenar_insercion_Directa_porFecha(personal arr[], int& n) 
{
	int k;
	for(int i = 1; i < n; i++)
	{
		personal aux = arr[i];
		k = i - 1;
		while(k >= 0 and compararFechas(aux.fechaNacimiento, arr[k].fechaNacimiento) < 0) { 
			arr[k + 1] = arr[k];
			k = k - 1;
		}
		arr[k + 1] = aux;
	}
    cout<<"  Datos ordenados por fecha de nacimiento "<<endl;
    for(int i=0; i<n; i++)
    {
    	cout<<"persona "<<i+1<<":"<<endl;
    	cout<<"DNI:"<<arr[i].DNI<<endl;
    	cout<<"Nombres:"<<arr[i].nombres<<endl;
    	cout<<"Fecha de nacimiento:"<<arr[i].fechaNacimiento.dia << "/" 
         << arr[i].fechaNacimiento.mes << "/" << arr[i].fechaNacimiento.anio << endl;
         cout<<endl;
	}
}
int busquedaBinariaPorFecha(personal arr[], int n, fecha fechaBuscada)
{
	int izq, der, cen,  m, pos;
	izq=0;
	der=n-1;
	cen=0;
	pos=-1;
	while(izq<=der and cen==0)
	{
		m=(izq+der)/2;
		int comparar=compararFechas(arr[m].fechaNacimiento, fechaBuscada);
		if(comparar==0)
		{
			cen=1;
			pos=m;
		}
		else if(comparar<0)
		{
			izq=m+1;
		}
		else
		{
			der=m-1;
		}	
	}
	if(cen==0)
	{
		pos=-1;
	}
	return pos;
}
int main() 
{    
    int n;
    cout<<"          registrar datos        "<<endl;
    cout<<"*********************************"<<endl;
    cout<<"ingrese la cantidad de personal: "; cin>>n;
    personal arreglo[n];
    for(int i=0; i<n; i++)
    {
    	
    	cout<<"persona "<<i+1<<":"<<endl;
    	cout<<"DNI:"; cin>>arreglo[i].DNI;
    	cout<<"Nombres:"; cin>>arreglo[i].nombres;
    	cout<<"Fecha de nacimiento:"; cin>>arreglo[i].fechaNacimiento.dia; 
        cin>>arreglo[i].fechaNacimiento.mes; cin>>arreglo[i].fechaNacimiento.anio;
	}
    ordenar_insercion_Directa_porFecha(arreglo, n);
    cout<<endl;
    fecha fechaBuscada;
    cout<<"Ingrese la fecha de nacimiento a buscar: ";
    cout<<"Dia: ";
	cin>>fechaBuscada.dia;
    cout<<"Mes: ";
	cin>>fechaBuscada.mes;
    cout<<"Anio: "; 
	cin>>fechaBuscada.anio;
	cout<<endl;
	
	int posicion=busquedaBinariaPorFecha(arreglo, n, fechaBuscada);
    
    if(posicion!=-1) 
	{
        cout<<"Persona encontrada: "<<arreglo[posicion].nombres<<endl;
		cout<<"DNI: "<<arreglo[posicion].DNI<<endl;
    } 
	else 
	{
        cout<<"Ninguna persona fue registrada con esa fecha de nacimiento."<< endl;
    }
    return 0;
}