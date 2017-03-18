#include <bits/stdc++.h>
using namespace std;
#define PI (3.141592653589793)

int main()
{
	
	vector<double>valores;

	double distancia[4];
	const double grad=180/PI;
	const double k=8.99e9;
	const double rad=PI/float(180);
	double nCargas,valor,fuerza=0,fx=0,fy=0,angulo=0,ftotal;
	int objetivo;

	cout<<"Inserte el numero de cargas: ";
	cin>>nCargas;
	cout<<"\nEste es el diagrama de referencia \n\n\n";

	for(int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			if(i==0 && j==0 && nCargas>=4)
			{
				cout<<"q4\t";
			}
			else if(j==3 && i==0 && nCargas>=3)
			{
				cout<<"q3\t";
			}
			else if(i==3 && j==0 && nCargas>=1)
			{
				cout<<"q1\t";
			}
			else if(i==3 && j==3 && nCargas>=2)
			{
				cout<<"q2\t";
			}
			else cout<<"*\t";

		}
		cout<<"\n\n";
	}

	for(int i=0;i<nCargas-1;i++)
	{
		cout<<"\nEscribe la distancia entre: q"<<i+1<<" y  q"<<i+2<<": ";
		cin>>distancia[i];
	}

	distancia[3]=sqrt(pow(distancia[0],2)+pow(distancia[1],2));
	
	cout<<"\n\n";
	
	for(int i=0;i<nCargas;i++)
	{
		cout<<"\nCual es el valor de q"<<i+1<<" en Coulumbs?: ";
		cin>>valor;
		valores.push_back(abs(valor));
	} 

	cout<<"\n\nSobre que carga se calculara la fuerza?: ";
	cin>>objetivo;

	double distancias[4][4]={
		{0, distancia[0], distancia[3], distancia[1]},
		{distancia[0], 0, distancia[1], distancia[3]},
		{distancia[3], distancia[1], 0, distancia[0]},
		{distancia[1], distancia[3], distancia[0], 0}
	};

	double angulos[4][4]=
	{
		{0,0,90-asin(	(distancias[0][1]*sin(90*rad))	/	(distancia[3])  )*grad,90},
		{180,0,90,90+asin(	(distancias[0][1]*sin(90*rad))	/	(distancia[3])  )*grad},
		{270-asin(	(distancias[0][1]*sin(90*rad))	/	(distancia[3])  )*grad,270,0,180},
		{270,270+asin(	(distancias[0][1]*sin(90*rad))	/	(distancia[3])  )*grad,0,0}
	};

	
	for(int i=0;i<valores.size();i++)
	{
		if(i!=objetivo-1)
		{
			double find=(k*valores[i]*valores[objetivo-1] )/pow(distancias[objetivo-1][i],2);
			cout<<"\n\n->La fuerza de q"<<objetivo<<" a q"<<i+1<<"="<<find;
			fx+=find*cos(rad*angulos[objetivo-1][i]);
			fy+=find*sin(rad*angulos[objetivo-1][i]);

			cout<<"\nFx= "<<find<<" cos("<<angulos[objetivo-1][i]<<")  = "<<find*cos(rad*angulos[objetivo-1][i])<<"\n\n";
			cout<<"Fy= "<<find<<" sin("<<angulos[objetivo-1][i]<<")  = "<<find*sin(rad*angulos[objetivo-1][i])<<"\n\n";
		}
	}
	angulo=atan( fy/fx)*grad;
	ftotal=sqrt(fx*fx+fy*fy);

	if(fx>0&&fy>0)
	{
		angulo=angulo*1;
	}
	else if(fx<0&&fy<0)
	{
		angulo+=180;
	}
	else if(fx>0&&fy<0)
	{
		angulo=360-abs(angulo);
	}
	else if(fx<0&&fy>0)
	{
		angulo=180-abs(angulo);
	}
	cout<<"\n\n--La fuerza fx: "<<fx;
	cout<<"\n\n--La fuerza fy: "<<fy;
	cout<<"\n\n--La fuerza resultante sobre q"<<objetivo<<" es "<<ftotal<<" N \n";
	cout<<"--El angulo de la fuerza es: "<<angulo<<" grados";
}