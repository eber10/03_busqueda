#include<iostream>
using namespace std;
struct monomio
{
	int coeficiente;
	int exponente;
};
void ordenar_polinomio(monomio termino[], int n)
{
	for(int i = 0 ; i < n - 1 ; i++)
	{
		for(int j =  i+1 ; j < n  ; j++)
		{
			if( termino[i].exponente > termino[j].exponente)
			{
				monomio aux;
				aux = termino[i];
				termino[i] = termino[j];
				termino[j] = aux;
			}
		}
	}
	cout<<endl;
	cout<<"Polinomio ordenado: "<<endl;
	cout<<"********************"<<endl;
	cout<<endl;
	for(int i=0; i<n; i++)
	{
		if(i>0 and termino[i].coeficiente>0) 
		{
			cout<<" + "; 
		}
		if(termino[i].coeficiente > 0)
		{
			cout<<termino[i].coeficiente;
		}
		if(termino[i].exponente == 0) 
		{
			cout<<termino[i].coeficiente; 
		}
		else if (termino[i].exponente == 1) 
		{
			cout<<"x"; 
		}
		else 
		{
			cout<< "x^" <<termino[i].exponente;  
		}
	}
	cout<<endl;
	
}
int busqueda_Secuencial_Ord(monomio termino[], int n, monomio buscartermino)
{
	int i, pos;
	i=0;
	while(i<n and termino[i].exponente<buscartermino.exponente)
	{
		i=i+1;
	}
	if(i<n and termino[i].exponente==buscartermino.exponente and termino[i].coeficiente==buscartermino.coeficiente )
	{
		pos=i;
	}
	else
	{
		pos=-i;		
	}
	return pos;
}
int main()
{
	int n;
	cout<<"Ingrese la cantidad de terminos del polinomio: "; cin>>n;
	monomio termino[n];
	cout<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<"coeficiente"<<i+1<<":"; cin>>termino[i].coeficiente;
		cout<<"exponente "<<i+1<<":"; cin>>termino[i].exponente;
		cout<<"----------------------"<<endl;
	}
	cout<<endl;
	ordenar_polinomio(termino, n);
	monomio buscar;
	cout<<endl;
	cout<<"            BUSCAR MONOMIO          "<<endl;
	cout<<"************************************"<<endl;
	cout<<"Ingrese el coeficiente del monomio: "; cin>>buscar.coeficiente;
	cout<<"-------------------------------------"<<endl;
	cout<<"Ingrese el exponente del monomio: "; cin>>buscar.exponente;
	cout<<"-------------------------------------"<<endl;
	cout<<endl;
	int posicion=busqueda_Secuencial_Ord(termino, n, buscar);
    if(posicion!=-1)
	{
		cout<<"El monomio si forma parte del polinomio."<<endl;
		cout<<endl;
        cout<<"El monomio se encuentra en el termino: "<<posicion+1<< endl;
    } 
	else
	{
        cout<<"El monomio no forma parte del polinomio."<< endl;
    }
	
	
	return 0; 
}