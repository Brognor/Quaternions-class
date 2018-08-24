#include <iostream>
#include <cmath>
#include <iomanip>
#include "Quaternioni.h"

using namespace std;

Quaternioni::Quaternioni(double a, double i , double j, double k) {componenti[0]=(a), componenti[1]=(i), componenti[2]=(j), componenti[3]=(k);};

Quaternioni::Quaternioni(double angolo, double *vet) {
	componenti[0]=cos(angolo/2); 
	double k;
	k=sqrt(1/(vet[0]*vet[0]+vet[1]*vet[1]+vet[2]*vet[2]));
	componenti[1]=vet[0]*k*sin(angolo/2); componenti[2]=vet[1]*k*sin(angolo/2); componenti[3]=vet[2]*k*sin(angolo/2);};

double Quaternioni::norm()
	{return (sqrt(
	this->componenti[0]*this->componenti[0]+
	this->componenti[1]*this->componenti[1]+
	this->componenti[2]*this->componenti[2]+
	this->componenti[3]*this->componenti[3])
	);}

Quaternioni & Quaternioni::operator = (Quaternioni b) //assegnamento
	{for (int p=0; p<4; ++p) {
	this->componenti[p]=b.componenti[p];}
	return *this;}

Quaternioni & Quaternioni::operator += (Quaternioni  b) //+=
	{for (int i=0; ++i; i<4) {this->componenti[i]+=b.componenti[i];}
	return *this;}

Quaternioni Quaternioni::operator + (Quaternioni  b) //somma
	{Quaternioni a=*this;
	a+=b;
	return a;}

Quaternioni & Quaternioni::operator -= (Quaternioni  b) //-=
	{for (int i=0; ++i; i<4) {this->componenti[i]-=b.componenti[i];} 
	return *this;}

Quaternioni Quaternioni::operator - (Quaternioni  b) //sottrazione
	{Quaternioni c=*this;
	c-=b;
	return c;}

Quaternioni Quaternioni::operator * (Quaternioni b) //prodotto
	{Quaternioni c;
	c.componenti[0]=this->componenti[0]*b.componenti[0]-this->componenti[1]*b.componenti[1]-this-> 		     		componenti[2]*b.componenti[2]-this->componenti[3]*b.componenti[3];  //Re
	c.componenti[1]=this->componenti[0]*b.componenti[1]+this->componenti[1]*b.componenti[0]+this-> 		 	 componenti[2]*b.componenti[3]-this->componenti[3]*b.componenti[2]; // i
	c.componenti[2]=this->componenti[0]*b.componenti[2]-this->componenti[1]*b.componenti[3]+this-> 		 	 componenti[2]*b.componenti[0]+this->componenti[3]*b.componenti[1]; // j
	c.componenti[3]=this->componenti[0]*b.componenti[3]+this->componenti[1]*b.componenti[2]-this->      	 	 componenti[2]*b.componenti[1]+this->componenti[3]*b.componenti[0]; // k
        return c;}


Quaternioni & Quaternioni::operator *= (Quaternioni b) //*=
	{Quaternioni c;
	c=*this;
	*this=(c*b);
	return *this;} 


Quaternioni Quaternioni::operator ~ () //coniugato
	{Quaternioni c;
	c.componenti[0]=this->componenti[0]; 
	c.componenti[1]=-this->componenti[1]; 
	c.componenti[2]=-this->componenti[2]; 
	c.componenti[3]=-this->componenti[3];
	return c;}

Quaternioni Quaternioni::operator ! () //inverso
        {Quaternioni c;
	double m=this->componenti[0]*this->componenti[0]+this->componenti[1]*this->componenti[1]+
	this->componenti[2]*this->componenti[2]+this->componenti[3]*this->componenti[3];
    	c.componenti[0]=this->componenti[0]/m; 
	c.componenti[1]=-this->componenti[1]/m; 
	c.componenti[2]=-this->componenti[2]/m; 
	c.componenti[3]=-this->componenti[3]/m;
        return c;}

	
double Quaternioni::operator | (Quaternioni b) //distanza
	{double distanza;
        distanza=(*this-b).norm();
	return distanza;}

Quaternioni Quaternioni::operator -() // opposto
	{Quaternioni a=*this;
	a*=-1;
	return a;}

Quaternioni Quaternioni::operator +() // se stesso medesimo
	{return *this;}

Quaternioni & Quaternioni::operator *= (double g) // *= scalare
	{for (int p=0; p<4; ++p)
	{this->componenti[p]*=g;}
	return *this;}

Quaternioni & Quaternioni::operator /= (double g) // /= scalare
	{for (int p=0; p<4; ++p)
	{this->componenti[p]/=g;}
	return *this;
	}
Quaternioni Quaternioni::operator * (double g) // * scalare
	{Quaternioni c=*this;
	c*=g;
	return c;}

Quaternioni Quaternioni::operator / (double g) // / scalare
	{Quaternioni c=*this;
	c/=g;
	return c;}

Quaternioni operator *= (double a, Quaternioni p) // *= scalare
	{Quaternioni Al(a,0.,0.,0.);
	Al*=p;
	return Al;} 
	
Quaternioni operator * (double a, Quaternioni p) // * scalare
	{return p*a;} 

double Quaternioni::angle() //angolo di rotazione
	{return 2*acos(this->componenti[0]);}

bool Quaternioni::operator == (Quaternioni j)
	{this->componenti[0]==j.componenti[0] && 
	this->componenti[1]==j.componenti[1] && 
	this->componenti[2]==j.componenti[2] && 
	this->componenti[3]==j.componenti[3];};

bool Quaternioni::operator != (Quaternioni j) 
	{return !(*this==j);};


 
Quaternioni Quaternioni::rot (Quaternioni quat) 
	{return (*this)*quat*(!(*this));}

bool Quaternioni::isNorm (double soglia=0.01) 
	{return (abs((this->norm())-1)<=soglia);}

bool Quaternioni::isNorm () 
	{return (abs((this->norm())-1)<=0.01);}

double Quaternioni::Get_Cr() {
	return this->componenti[0];}

double Quaternioni::Get_Ci() {
	return this->componenti[1];}

double Quaternioni::Get_Cj() {
	return this->componenti[2];}

double Quaternioni::Get_Ck() {
	return this->componenti[3];}

ostream & operator << (ostream & o, Quaternioni b) //scrittura
	{return o <<setprecision(3) <<fixed <<noshowpos  << b.componenti[0]
	<<showpos  <<b.componenti[1] <<"i"  
	<<b.componenti[2] <<"j" 
	<<b.componenti[3] <<"k";}
 
SOtre::SOtre(Quaternioni q): s(1/(q.norm()*(q.norm()))) {
	elemento[0][0]=1-2*s*(q.Get_Cj()*q.Get_Cj()+q.Get_Ck()*q.Get_Ck()),  
	elemento[0][1]=2*s*(q.Get_Ci()*q.Get_Cj()-q.Get_Ck()*q.Get_Cr()),       
	elemento[0][2]=2*s*(q.Get_Ci()*q.Get_Ck()+q.Get_Cj()*q.Get_Cr()), 
	elemento[1][0]=2*s*(q.Get_Ci()*q.Get_Cj()+q.Get_Ck()*q.Get_Cr()),  
	elemento[1][1]=1-2*s*(q.Get_Ci()*q.Get_Ci()+q.Get_Ck()*q.Get_Ck()), 
	elemento[1][2]=2*s*(q.Get_Cj()*q.Get_Ck()-q.Get_Ci()*q.Get_Cr()),
	elemento[2][0]=2*s*(q.Get_Ci()*q.Get_Ck()-q.Get_Cj()*q.Get_Cr()), 
	elemento[2][1]=2*s*(q.Get_Cj()*q.Get_Ck()+q.Get_Ci()*q.Get_Cr()), 
	elemento[2][2]=1-2*s*(q.Get_Ci()*q.Get_Ci()+q.Get_Cj()*q.Get_Cj());}

double SOtre::Get_El11()
	{return this->elemento[0][0];}

double SOtre::Get_El12()
	{return this->elemento[0][1];}

double SOtre::Get_El13()
	{return this->elemento[0][2];}
	
double SOtre::Get_El21()
	{return this->elemento[1][0];}
	
double SOtre::Get_El22()
	{return this->elemento[1][1];}

double SOtre::Get_El23()
	{return this->elemento[1][2];}

double SOtre::Get_El31()
	{return this->elemento[2][0];}

double SOtre::Get_El32()
	{return this->elemento[2][1];}

double SOtre::Get_El33()
	{return this->elemento[2][2];}



ostream & operator << (ostream & o, SOtre a) //scrittura SO3
	{ return  o <<fixed <<setprecision(2)  
	<<setw(12) <<a.elemento[0][0] <<setw(12) <<a.elemento[0][1]  <<setw(12) <<a.elemento[0][2] <<endl
	<<setw(12) <<a.elemento[1][0] <<setw(12) <<a.elemento[1][1]  <<setw(12) <<a.elemento[1][2] <<endl
	<<setw(12) <<a.elemento[2][0] <<setw(12) <<a.elemento[2][1]  <<setw(12) <<a.elemento[2][2]  <<endl;}


Vettori::Vettori(Quaternioni q) {
	coordinate[0]=q.Get_Ci()/(sin(acos(q.Get_Cr())));
	coordinate[1]=q.Get_Cj()/(sin(acos(q.Get_Cr())));
	coordinate[2]=q.Get_Ck()/(sin(acos(q.Get_Cr())));}

double Vettori::Get_x() {
	return this->coordinate[0];}

double Vettori::Get_y() {
	return this->coordinate[1];}

double Vettori::Get_z() {
	return this->coordinate[2];}


ostream & operator << (ostream & o, Vettori v) //scrittura
	{return o <<setprecision(2) <<fixed <<noshowpos 
	<<(v.coordinate[0]) <<' ' 
	<<(v.coordinate[1]) <<' '
	<<(v.coordinate[2]);}





