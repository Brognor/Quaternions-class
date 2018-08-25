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
	componenti[1]=vet[0]*k*sin(angolo/2); 
	componenti[2]=vet[1]*k*sin(angolo/2); 
	componenti[3]=vet[2]*k*sin(angolo/2);};

double Quaternioni::norm() const
	{return (sqrt(
	this->componenti[0]*this->componenti[0]+
	this->componenti[1]*this->componenti[1]+
	this->componenti[2]*this->componenti[2]+
	this->componenti[3]*this->componenti[3]));}

Quaternioni & Quaternioni::operator = (Quaternioni b) //assegnamento
	{for (int p=0; p<4; ++p) {
	this->componenti[p]=b.componenti[p];}
	return *this;}

Quaternioni & Quaternioni::operator += (Quaternioni  b) //+=
	{for (int i=0; i<4; ++i) {this->componenti[i]+=b.componenti[(i)];}
	return *this;}

Quaternioni operator + (const Quaternioni a, Quaternioni  b) //somma
	{Quaternioni r=a;
	r+=b;
	return r;}

Quaternioni & Quaternioni::operator -= (Quaternioni  b) //-=
	{for (int i=0; i<4; ++i) {this->componenti[i]-=b.componenti[i];}
	return *this;}

Quaternioni operator - (const Quaternioni c, Quaternioni  b) //sottrazione
	{Quaternioni o=c;
	o-=b;
	return o;}

Quaternioni & Quaternioni::operator *= (Quaternioni b) //prodotto
	{Quaternioni t=*this;
	this->componenti[0]=t.componenti[0]*b.componenti[0]-t.componenti[1]*b.componenti[1]-t.componenti[2]*b.componenti[2]-t.componenti[3]*b.componenti[3];  //Re
	this->componenti[1]=t.componenti[0]*b.componenti[1]+t.componenti[1]*b.componenti[0]+t. 		 	 	 componenti[2]*b.componenti[3]-t.componenti[3]*b.componenti[2]; // i
	this->componenti[2]=t.componenti[0]*b.componenti[2]-t.componenti[1]*b.componenti[3]+t. 		 	 	 componenti[2]*b.componenti[0]+t.componenti[3]*b.componenti[1]; // j
	this->componenti[3]=t.componenti[0]*b.componenti[3]+t.componenti[1]*b.componenti[2]-t.      	 	 	 componenti[2]*b.componenti[1]+t.componenti[3]*b.componenti[0]; // k
        return *this;}


Quaternioni operator * (Quaternioni const c, const Quaternioni b) //*=
	{Quaternioni p=c;
	p*=b;
	return p;} 


Quaternioni operator ~ (Quaternioni const t) //coniugato
	{Quaternioni c;
	c.componenti[0]=t.componenti[0]; 
	c.componenti[1]=-t.componenti[1]; 
	c.componenti[2]=-t.componenti[2]; 
	c.componenti[3]=-t.componenti[3];
	return c;}

Quaternioni operator ! (const Quaternioni a) //inverso
        {Quaternioni c=a;
	double m=a.componenti[0]*a.componenti[0]+a.componenti[1]*a.componenti[1]+
	a.componenti[2]*a.componenti[2]+a.componenti[3]*a.componenti[3];
    	c.componenti[0]=a.componenti[0]/m; 
	c.componenti[1]=-a.componenti[1]/m; 
	c.componenti[2]=-a.componenti[2]/m; 
	c.componenti[3]=-a.componenti[3]/m;
        return c;}

	
double operator | (const Quaternioni a, const Quaternioni b) //distanza
	{double distanza;
        distanza=(a-b).norm();
	return distanza;}

Quaternioni operator -(Quaternioni const a) // opposto
	{Quaternioni b=a;
	b*=-1;
	return b;}

Quaternioni operator +(Quaternioni const b) // se stesso medesimo
	{return b;}

Quaternioni & Quaternioni::operator *= (double g) // *= scalare
	{for (int p=0; p<4; ++p)
	{this->componenti[p]*=g;}
	return *this;}

Quaternioni & Quaternioni::operator /= (double g) // /= scalare
	{for (int p=0; p<4; ++p)
	{this->componenti[p]/=g;}
	return *this;
	}
Quaternioni operator * (const Quaternioni q, double g) // * scalare
	{Quaternioni r=q;
	r*=g;
	return r;}

Quaternioni operator / (const Quaternioni c ,double g) // / scalare
	{Quaternioni r=c;
	r/=g;
	return r;}

Quaternioni operator *= (double a, const Quaternioni p) // *= scalare
	{Quaternioni Al(a,0.,0.,0.);
	Al*=p;
	return Al;} 
	
Quaternioni operator * (double a, const Quaternioni p) // * scalare
	{return p*a;} 

double Quaternioni::angle() const //angolo di rotazione
	{return 2*acos(this->componenti[0]);}

bool operator == (const Quaternioni & t, const Quaternioni & j)
	{t.componenti[0]==j.componenti[0] && 
	t.componenti[1]==j.componenti[1] && 
	t.componenti[2]==j.componenti[2] && 
	t.componenti[3]==j.componenti[3];};

bool operator != (const Quaternioni & t, const Quaternioni & j) 
	{return !(t==j);};


 
Quaternioni Quaternioni::rot (Quaternioni quat) const
	{return (*this)*quat*(!(*this));}

bool Quaternioni::isNorm (double soglia=0.01)  const
	{return (abs((this->norm())-1)<=soglia);}

bool Quaternioni::isNorm () const
	{return (abs((this->norm())-1)<=0.01);}

double Quaternioni::Get_Cr() const {
	return this->componenti[0];}

double Quaternioni::Get_Ci() const {
	return this->componenti[1];}

double Quaternioni::Get_Cj() const {
	return this->componenti[2];}

double Quaternioni::Get_Ck() const{
	return this->componenti[3];}

ostream & operator << (ostream & o, const Quaternioni b) //scrittura
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

double SOtre::Get_El11() const 
	{return this->elemento[0][0];}

double SOtre::Get_El12() const
	{return this->elemento[0][1];}

double SOtre::Get_El13() const 
	{return this->elemento[0][2];}
	
double SOtre::Get_El21() const 
	{return this->elemento[1][0];}
	
double SOtre::Get_El22() const 
	{return this->elemento[1][1];}

double SOtre::Get_El23() const 
	{return this->elemento[1][2];}

double SOtre::Get_El31() const 
	{return this->elemento[2][0];}

double SOtre::Get_El32() const 
	{return this->elemento[2][1];}

double SOtre::Get_El33() const 
	{return this->elemento[2][2];}



ostream & operator << (ostream & o, const SOtre a)  //scrittura SO3
	{ return  o <<fixed <<setprecision(2)  
	<<setw(12) <<a.elemento[0][0] <<setw(12) <<a.elemento[0][1]  <<setw(12) <<a.elemento[0][2] <<endl
	<<setw(12) <<a.elemento[1][0] <<setw(12) <<a.elemento[1][1]  <<setw(12) <<a.elemento[1][2] <<endl
	<<setw(12) <<a.elemento[2][0] <<setw(12) <<a.elemento[2][1]  <<setw(12) <<a.elemento[2][2]  <<endl;}


Vettori::Vettori(Quaternioni q) {
	coordinate[0]=q.Get_Ci()/(sin(acos(q.Get_Cr())));
	coordinate[1]=q.Get_Cj()/(sin(acos(q.Get_Cr())));
	coordinate[2]=q.Get_Ck()/(sin(acos(q.Get_Cr())));}

double Vettori::Get_x() const {
	return this->coordinate[0];}

double Vettori::Get_y() const  {
	return this->coordinate[1];}

double Vettori::Get_z() const  {
	return this->coordinate[2];}


ostream & operator << (ostream & o, const Vettori v)  //scrittura
	{return o <<setprecision(2) <<fixed <<noshowpos 
	<<(v.coordinate[0]) <<' ' 
	<<(v.coordinate[1]) <<' '
	<<(v.coordinate[2]);}





