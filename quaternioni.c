#include <iostream>
#include <cmath>
#include <iomanip>
#include "quaternioni.h"

using namespace std;

quaternioni quaternioni::operator = (quaternioni b) //uguaglianza
	{for (int p=0; p<4; ++p) {
	this->co[p]=b.co[p];}
	return *this;
}


quaternioni quaternioni::operator + (quaternioni  b) //somma
	{quaternioni c;
	for (int p=0; p<4; ++p)
	{c.co[p]=this->co[p]+b.co[p];}
	return c;}

quaternioni quaternioni::operator - (quaternioni  b) //sottrazione
	{quaternioni c;
	for (int p=0; p<4; ++p)
	{c.co[p]=this->co[p]-b.co[p];}
	return c;}

quaternioni quaternioni::operator += (quaternioni  b) //+=
	{for (int i=0; ++i; i<4) {this->co[i]+=b.co[i];} return *this;}

quaternioni quaternioni::operator -= (quaternioni  b) //-=
	{for (int i=0; ++i; i<4) {this->co[i]-=b.co[i];} return *this;}

quaternioni quaternioni::operator *= (quaternioni b) //*=
{quaternioni c;
c=*this;
*this=(c*b);
return *this
;
} 
	


quaternioni quaternioni::operator * (quaternioni b) //prodotto
	{quaternioni c;
	c.co[0]=this->co[0]*b.co[0]-this->co[1]*b.co[1]-this->co[2]*b.co[2]-this->co[3]*b.co[3];  //Re
	c.co[1]=this->co[0]*b.co[1]+this->co[1]*b.co[0]+this->co[2]*b.co[3]-this->co[3]*b.co[2]; // i
	c.co[2]=this->co[0]*b.co[2]-this->co[1]*b.co[3]+this->co[2]*b.co[0]+this->co[3]*b.co[1]; // j
	c.co[3]=this->co[0]*b.co[3]+this->co[1]*b.co[2]-this->co[2]*b.co[1]+this->co[3]*b.co[0]; // k
        return c;}



quaternioni quaternioni::operator * () //coniugato
	{quaternioni c;
	c.co[0]=this->co[0]; c.co[1]=-this->co[1]; c.co[2]=-this->co[2]; c.co[3]=-this->co[3];
	return c;}

quaternioni quaternioni::operator -- () //inverso
    {quaternioni c;
    double m=this->co[0]*this->co[0]+this->co[1]*this->co[1]+this->co[2]*this->co[2]+this->co[3]*this->co[3];
    c.co[0]=this->co[0]/m; c.co[1]=-this->co[1]/m; c.co[2]=-this->co[2]/m; c.co[3]=-this->co[3]/m;
    return c;}

	
double quaternioni::operator / (quaternioni b) //distanza

	{double distanza;
        distanza=~(*this-b);
	return distanza;}

quaternioni quaternioni::operator -() // opposto
	{for (int i=0; i<4; ++i)
	{co[i]*=-1;}; return *this;}

quaternioni quaternioni::operator +() // se stesso medesimo
	{return *this;}
	

double quaternioni::operator ~ () //modulo
	{return (sqrt(this->co[0]*this->co[0]+this->co[1]*this->co[1]+this->co[2]*this->co[2]+this->co[3]*this->co[3]))
	;}

double quaternioni::operator !() //angolo di rotazione
	{return 2*acos(this->co[0]);}

quaternioni quaternioni::operator * (double g) // * scalare
	{quaternioni c;
	for (int p=0; p<4; ++p)
	{c.co[p]=this->co[p]*g;}
	return c;
	}

quaternioni quaternioni::operator / (double g) // / scalare
	{quaternioni c;
	for (int p=0; p<4; ++p)
	{c.co[p]=this->co[p]/g;}
	return c;
	}

quaternioni quaternioni::operator *= (double g) // *= scalare
	{for (int p=0; p<4; ++p)
	{this->co[p]*=g;}
	return *this;
	}

quaternioni quaternioni::operator /= (double g) // /= scalare
	{for (int p=0; p<4; ++p)
	{this->co[p]/=g;}
	return *this;
	}


quaternioni::quaternioni(double a, double i , double j, double k) {co[0]=(a), co[1]=(i), co[2]=(j), co[3]=(k);};
quaternioni::quaternioni(double angolo, double *vet) {
	co[0]=cos(angolo/2); 
	double k;
	k=sqrt(1/(vet[0]*vet[0]+vet[1]*vet[1]+vet[2]*vet[2]));
	co[1]=vet[0]*k*sin(angolo/2); co[2]=vet[1]*k*sin(angolo/2); co[3]=vet[2]*k*sin(angolo/2);}
 
quaternioni quaternioni::rot (quaternioni quat) {return (*this)*quat*(--(*this));}
bool quaternioni::ver () {if (abs(~(*this)-1)<=0.01) return true;
else return false;}



ostream & operator << (ostream & o, quaternioni b) //scrittura
{ return o <<setprecision(3) <<fixed <<noshowpos  << b.co[0]  <<showpos  <<b.co[1] <<"i"  << b.co[2] <<"j" << b.co[3] <<"k"; 
}


 

SOtre::SOtre(quaternioni q): s(1/(~q)*(~q)) {el[0][0]=1-2*s*(q.co[2]*q.co[2]+q.co[3]*q.co[3]),  el[0][1]=2*s*(q.co[1]*q.co[2]-q.co[3]*q.co[0]),       el[0][2]=2*s*(q.co[1]*q.co[3]+q.co[2]*q.co[0]), 
                      el[1][0]=2*s*(q.co[1]*q.co[2]+q.co[3]*q.co[0]),  el[1][1]=1-2*s*(q.co[1]*q.co[1]+q.co[3]*q.co[3]), el[1][2]=2*s*(q.co[2]*q.co[3]-q.co[1]*q.co[0]),
                      el[2][0]=2*s*(q.co[1]*q.co[3]-q.co[2]*q.co[0]),  el[2][1]=2*s*(q.co[2]*q.co[3]+q.co[1]*q.co[0]), el[2][2]=1-2*s*(q.co[1]*q.co[1]+q.co[2]*q.co[2]);}





ostream & operator << (ostream & o, SOtre s) //scrittura SO3
	{ return  o <<fixed <<setprecision(2)  
	<<setw(12) <<s.el[0][0] <<setw(12) <<s.el[0][1]  <<setw(12) <<s.el[0][2] <<endl
	<<setw(12) <<s.el[1][0] <<setw(12) <<s.el[1][1]  <<setw(12) <<s.el[1][2] <<endl
	<<setw(12) <<s.el[2][0] <<setw(12) <<s.el[2][1]  <<setw(12) <<s.el[2][2]  <<endl;}



vettori::vettori(quaternioni q){for (int i=0; i<3; ++i) {co[i]=q.co[i+1]/(sin(acos(q.co[0])));}
;}

ostream & operator << (ostream & o, vettori v) //scrittura
{return o <<setprecision(2) <<fixed <<noshowpos <<v.co[0] <<' ' <<v.co[1] <<' ' <<v.co[2];}



