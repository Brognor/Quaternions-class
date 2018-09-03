#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include "Quaternioni.h"
using namespace std; 

void Amleto()
	{cout <<"Vuoi eseguire operazioni tra quaternioni(1), conoscere le caratteristiche di un quaternione(2) o vuoi ruotare un vettore?(3) ";}

void decisione ()
	{cout <<"Vuoi inizializzare il quaternione con le componenti (g) o come operatore di rotazione?(u) ";}

void caratteristiche ()
	{cout <<"Vuoi conoscere le caratteristiche di questo quaternione?(s/n) ";}

void funz (Quaternioni<double> *p) {
	cout <<"Per i due quaternioni le operazioni danno i seguenti risultati:\n" 
	<<"\033[36m" <<"Somma " <<"\033[0m"  <<p[0]+p[1] <<endl 
	<<"\033[36m" <<"Differenza " <<"\033[0m" <<p[0]-p[1] <<endl
	<<"\033[36m" <<"Prodotto " <<"\033[0m" <<p[0]*p[1] <<endl 
	<<"\033[36m" <<"Distanza " <<"\033[0m" <<(p[0]|p[1]) <<endl <<endl ;};

void funzuno (Quaternioni<double> *p) {
	funz(p);
	SOtre<double> matricefin(p[1]*p[0]);
	Vettori<double> v(p[1]*p[0]);
	cout <<"La composizione delle due trasformazioni (eseguite nell'ordine di immissione dei quaternioni) è una rotazione di " <<((p[1]*p[0]).angle()) <<" radianti\n" 
	<< "attorno al vettore " <<v <<endl
	<<"La trasformazione è rappresentata dalla seguente matrice\n" <<matricefin   <<endl
	;};



void solitario (Quaternioni<double> p) 
	{cout <<"Il quaternione inserito ha:\n" <<"\033[36m"<< "Modulo " <<"\033[0m"<<(p.norm()) <<endl <<"\033[36m" 		<<"Inverso " <<"\033[0m" <<!p  <<endl <<"\033[36m" <<"Coniugato " <<"\033[0m" <<~p <<endl <<endl;};

void solitariouno (Quaternioni<double> p) {
	SOtre<double> m(p);
	Vettori<double> vector(p);
	cout <<"Il quaternione inserito ha\n" <<endl <<"\033[36m" <<"Inverso " <<"\033[0m" <<!p <<endl 
	<<"\033[36m" <<"Coniugato " <<"\033[0m" <<~p <<endl 
	<< "Modulo 1 perciò è associato ad una rotazione nel 3-spazio " <<endl 
	<<"Il vettore attorno cui avviene la rotazione è " <<vector <<' ' <<"l'angolo di rotazione vale "  		<<p.angle() <<" radianti." <<endl <<"Il quaternione rappresenta la seguente matrice\n" <<m <<endl;};

int main() {
double a, b, c, d;
double x,y,z;
int cont;
char scelta;
char i;
i='i';

Amleto();
cin >>scelta;
cin.ignore(200, '\n');
while(scelta!='1'&& scelta!='2' && scelta!='3') 
	{cout <<"Opzione non riconosciuta\n";   Amleto(); cin>>scelta; cin.ignore(200, '\n'); }

 switch (scelta)
{case '1':
	{cont=0;
	Quaternioni<double> ar[2];
	while (cont<=1) {	
		decisione ();
		cin >> scelta;
		cin.ignore(200, '\n');

		while(scelta!='u'&& scelta!='g') 
			{cout <<"Opzione non riconosciuta\n"; decisione(); cin>>scelta; cin.ignore(200, '\n');}

		switch (scelta)

		{case 'u': 
			{cout<<"Scrivi il vettore attorno a cui avviene la rotazione\n";
			cin >>b >>c >>d; cin.ignore(200, '\n');

			while (cin.fail()) 
				{cin.clear(); cin.ignore(200, '\n');cout <<"Input non valido\n"; 
				cout<<"Scrivi il vettore attorno a cui avviene la rotazione\n"; 
				cin >>b >>c >>d; cin.ignore(200, '\n');}

			double ax[3]={b,c,d};
			cout<<"Scrivi l'angolo di rotazione in radianti\n";
			cin >>a; cin.ignore(200, '\n');

			while (cin.fail())  
				{cin.clear(); cin.ignore(200, '\n'); cout <<"Input non valido\n";
				cout<<"Scrivi l'angolo di rotazione in radianti\n"; cin >>a; cin.ignore(200, '\n');}

			Quaternioni<double> p(a,ax);
			cout << "Il quaternione che rappresenta questa trasformazione è " <<p <<endl; ar[cont]=p; 
			++cont; break;} //fine case u
	
		case 'g': 
			{cout <<"Scrivi le componenti del quaternione\n";
			cin >>a >>b >>c >>d; cin.ignore(200, '\n');
			while (cin.fail()) 
				{cin.clear(); cin.ignore(200, '\n'); cout <<"Input non valido\n";
				cout<<"Scrivi le componenti del quaternione\n"; 
				cin >>a >>b >>c >>d; cin.ignore(200, '\n');}

			Quaternioni<double> l(a,b,c,d); ar[cont]=l; ++cont;
			break;} //fine case g

		;}//fine switch

	;} //fine while 1

	if (ar[0].isNorm(0.01) && ar[1].isNorm(0.01))
		 funzuno(ar);

	else funz(ar);

break;} //fine case 1

case '2':{
	while(i){
		decisione();
		cin >> scelta;
		cin.ignore(200, '\n');

		while(scelta!='u'&& scelta!='g') 
			{cout <<"Opzione non riconosciuta\n"; 	decisione(); cin>>scelta; cin.ignore(200, '\n');}

		switch(scelta){

		case 'u': 
			{cout<<"Scrivi il vettore attorno a cui avviene la rotazione\n";
			cin >>b >>c >>d; cin.ignore(200, '\n');

			while (cin.fail()) 
				{cin.clear(); cin.ignore(200, '\n');cout <<"Input non valido\n"; 
				cout<<"Scrivi il vettore attorno a cui avviene la rotazione\n"; 
				 cin >>b >>c >>d; cin.ignore(200, '\n');}

			cout<<"Scrivi l'angolo di rotazione in radianti\n";
			cin >>a; cin.ignore(200, '\n');

			while (cin.fail()) 
				{cin.clear(); cin.ignore(200, '\n'); cout <<"Input non valido\n";  
				cout<<"Scrivi l'angolo di rotazione in radianti\n";
				cin >>a; cin.ignore(200, '\n');}

			double ax[3]={b,c,d};
			Quaternioni<double> q(a,ax);
			SOtre<double> matriceq(q);
			cout<< "Il quaternione che rappresenta questa trasformazione è " <<q  <<" associato alla seguente matrice\n" <<matriceq <<endl; 
			solitario(q);
			break;} //fine case u
				

		case 'g': {cout <<"Scrivi le componenti del quaternione\n";
			cin >>a >>b >>c >>d; cin.ignore(200, '\n');

			while (cin.fail()) 
				{cin.clear(); cin.ignore(200, '\n');cout <<"Input non valido\n";
				cout<<"Scrivi le componenti del quaternione\n"; 
				cin >>a >>b >>c >>d; cin.ignore(200, '\n');}

			Quaternioni<double> l(a,b,c,d);

			if(l.isNorm(0.01)) 
				{solitariouno(l);}

			else solitario (l);
 
			break;} //fine case g
		
		} //fine switch

		cout<<"Si vogliono conoscere le caratteristiche di un nuovo quaternione(s/n)? ";
		cin>>&i;

		while(i!='s' && i!='n') 
			{cout <<"Opzione non riconosciuta\n"; cin.clear();  
			cout<<"Si vogliono conoscere le caratteristiche di un nuovo quaternione(s/n)?"; cin>>&i;}

		(bool) i;
		if (i=='s') i=true;
		if (i=='n') i=false;} //fine while  2

	break;} //fine case 2
	


case '3': {
	std::vector<Quaternioni<double>> v;
	cout <<"Scrivi le componenti del vettore da ruotare\n"; 
	cin >>x >>y >>z;

	while(cin.fail()) 
		{cin.clear(); cin.ignore(200, '\n');cout<<"Input non valido\n"; 
		cout <<"Scrivi le componenti del vettore da ruotare"; cin >>a >>b >>c;}

	Quaternioni<double> ruotando(0,x,y,z);
	Quaternioni<double> r;

	while(i)
		{cout <<"Attorno a che vettore vuoi ruotare?";
		cin >>b >>c >>d; cin.ignore(200, '\n');

		while(cin.fail()) 
			{cin.clear(); cin.ignore(200, '\n');cout<<"Input non valido\n";
			cout <<"Attorno a che vettore vuoi ruotare?"; cin >>b >>c >>d;cin.ignore(200,'\n') ;}

		cout<<"Di che angolo (in radianti) vuoi ruotare?";
		cin >>a;
		cin.ignore(200, '\n');

		while(cin.fail()) 
			{cin.clear(); cin.ignore(200, '\n');cout<<"Input non valido\n"; 
			cout <<"Di che angolo vuoi ruotare?"; cin >>a; cin.ignore(200,'\n') ;}

		double ax[3]={b,c,d};
		Quaternioni<double> r(a,ax);
		v.push_back(r);
		(char) i;
		cout <<"Vuoi ruotare il vettore ottenuto attorno un altro vettore? (s/n)";
		cin>>i;
		cin.ignore(200, '\n');

		while(i!='s' && i!='n') 
			{cout <<"Opzione non riconosciuta\n";  
			cout<<"Vuoi ruotare il vettore ottenuto attorno un altro vettore? (s/n)"; 
			cin>>i; cin.ignore(200, '\n');}

		(bool) i;
		if (i=='s') i=true ;
		if (i=='n') i=false;
		} //fine while 3

	Quaternioni<double> risultato;

	for (int i=1; i<=(v.size()-1); ++i) 
		{v[v.size()-1]*=v[v.size()-1-i];}
 	
	risultato=v[v.size()-1].rot(ruotando);
	cout <<"Il vettore ottenuto dall'insieme delle rotazioni è:" 
	<<risultato.Get_Ci() <<' '
	<<risultato.Get_Cj() <<' ' 
	<<risultato.Get_Ck();

	Vettori<double> vet(v[v.size()-1]);
	SOtre<double> matrice(v[v.size()-1]); 
	cout <<"\nL'insieme delle rotazioni compiute corrisponde ad un'unica rotazione di " 
	<<(v[v.size()-1].angle()) <<" radianti attorno al vettore " <<vet <<endl 
	<<"La matrice che rappresenta la rotazione è\n" <<matrice;

	break;} //fine case 3

	;} //fine Switch iniziale 
;} //chiusura main
