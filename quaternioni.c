#include <iostream>
#include <cmath>
#include <iomanip>
#include "Quaternioni.h"

using namespace std;


template <class X> Quaternioni<X>::Quaternioni(X a, X i , X j, X k) {componenti[0]=(a), componenti[1]=(i), componenti[2]=(j), componenti[3]=(k);};

template <class X> Quaternioni<X>::Quaternioni(X angolo, X *vet) {
	componenti[0]=cos(angolo/2); 
	double k;
	k=sqrt(1/(vet[0]*vet[0]+vet[1]*vet[1]+vet[2]*vet[2]));
	componenti[1]=vet[0]*k*sin(angolo/2); 
	componenti[2]=vet[1]*k*sin(angolo/2); 
	componenti[3]=vet[2]*k*sin(angolo/2);};

template <class X> double  Quaternioni<X>::norm() const
	{return (sqrt(
	this->componenti[0]*this->componenti[0]+
	this->componenti[1]*this->componenti[1]+
	this->componenti[2]*this->componenti[2]+
	this->componenti[3]*this->componenti[3]));}

template <class X> Quaternioni<X> & Quaternioni<X>::operator = (Quaternioni<X> b) //assegnamento
	{for (int p=0; p<4; ++p) {
	this->componenti[p]=b.componenti[p];}
	return *this;}

template <class X> Quaternioni <X> &  Quaternioni<X>::operator += (Quaternioni <X> b) //+=
	{for (int i=0; i<4; ++i) {this->componenti[i]+=b.componenti[(i)];}
	return *this;}

template <class X> Quaternioni <X> operator + (const Quaternioni<X> a, Quaternioni<X>  b) //somma
	{Quaternioni <X> r=a;
	r+=b;
	return r;}

template <class X> Quaternioni <X> & Quaternioni<X>::operator += (const X a) //+= num
	{this->componenti[0]+=a;
	return *this;}
	
	
template <class X> Quaternioni<X> operator + (const Quaternioni<X>  a, const X b)//somma num
	{Quaternioni<X> c=a;
	c+=b;
	return c;}

template <class X> Quaternioni <X> operator += (X a, const Quaternioni <X> b) //num +=
	{Quaternioni<X> Al(a,0,0,0);
	return Al+=b;}

template <class X> Quaternioni <X> operator + (const X a, const Quaternioni <X> b) //num somma
	{X c=a;
	return c+=b;}

template <class X> Quaternioni <X> &  Quaternioni <X>::operator -= (Quaternioni <X>  b) //-=
	{for (int i=0; i<4; ++i) {this->componenti[i]-=b.componenti[i];}
	return *this;}

template <class X> Quaternioni <X> operator - (const Quaternioni  <X> c, Quaternioni <X> b) //sottrazione
	{Quaternioni <X>o=c;
	o-=b;
	return o;}

template <class X> Quaternioni <X> & Quaternioni<X>::operator -= (X a) //-= num
	{this->componenti[0]-=a;
	return *this;}

template <class X> Quaternioni<X> operator - (Quaternioni<X> const a, const X b) //sottrazione num
	{Quaternioni<X> c=a;
	c-=b;
	return c;}

template <class X> Quaternioni <X> operator -= (X a, Quaternioni <X> b) //num -=
	{Quaternioni<X> Al(a,0,0,0);
	return Al-=b;}

template <class X> Quaternioni <X> operator -(X a, Quaternioni <X> b) //num sottrazione
	{X c=a;
	return c-=b;}


template <class X>  Quaternioni <X> & Quaternioni <X>::operator *= (Quaternioni<X> b) //prodotto
	{Quaternioni <X> t=*this;
	this->componenti[0]=t.componenti[0]*b.componenti[0]-t.componenti[1]*b.componenti[1]-t.componenti[2]*b.componenti[2]-t.componenti[3]*b.componenti[3];  //Re
	this->componenti[1]=t.componenti[0]*b.componenti[1]+t.componenti[1]*b.componenti[0]+t. 		 	 	 componenti[2]*b.componenti[3]-t.componenti[3]*b.componenti[2]; // i
	this->componenti[2]=t.componenti[0]*b.componenti[2]-t.componenti[1]*b.componenti[3]+t. 		 	 	 componenti[2]*b.componenti[0]+t.componenti[3]*b.componenti[1]; // j
	this->componenti[3]=t.componenti[0]*b.componenti[3]+t.componenti[1]*b.componenti[2]-t.      	 	 	 componenti[2]*b.componenti[1]+t.componenti[3]*b.componenti[0]; // k
        return *this;}


template <class X> Quaternioni <X> operator * (Quaternioni <X> const c, const Quaternioni <X> b) //*=
	{Quaternioni <X> p=c;
	p*=b;
	return p;} 


template <class X> Quaternioni <X> operator ~ (Quaternioni <X> const t) //coniugato
	{Quaternioni <X> c;
	c.componenti[0]=t.componenti[0]; 
	c.componenti[1]=-t.componenti[1]; 
	c.componenti[2]=-t.componenti[2]; 
	c.componenti[3]=-t.componenti[3];
	return c;}

template <class X> Quaternioni <X> operator ! (const Quaternioni <X> a) //inverso
        {Quaternioni<X> c=a;
	double m=a.componenti[0]*a.componenti[0]+a.componenti[1]*a.componenti[1]+
	a.componenti[2]*a.componenti[2]+a.componenti[3]*a.componenti[3];
	if (m==0) cout <<"Errore\n";
	else
    	c.componenti[0]=a.componenti[0]/m; 
	c.componenti[1]=-a.componenti[1]/m; 
	c.componenti[2]=-a.componenti[2]/m; 
	c.componenti[3]=-a.componenti[3]/m;
        return c;}

	
template <class X> double operator | (const Quaternioni <X> a, const Quaternioni <X> b) //distanza
	{double distanza;
        distanza=(a-b).norm();
	return distanza;}

template <class X> Quaternioni <X> operator -(Quaternioni <X> const a) // opposto
	{Quaternioni <X> b=a;
	b*=-1;
	return b;}

template <class X> Quaternioni <X> operator +(Quaternioni <X> const b) // se stesso medesimo
	{return b;}

template <class X> Quaternioni<X> &  Quaternioni <X>::operator *= (X g) // *= scalare
	{for (int p=0; p<4; ++p)
	{this->componenti[p]*=g;}
	return *this;}

template <class X>  Quaternioni <X> & Quaternioni<X>::operator /= (X g) // /= scalare
	{if (g==0) cout <<"Errore\n";
	else 
	for (int p=0; p<4; ++p)
		{this->componenti[p]/=g;}
	return *this;
	}
template <class X> Quaternioni <X> operator * (const Quaternioni <X> q, X g) // * scalare
	{Quaternioni <X> r=q;
	r*=g;
	return r;}

template <class X> Quaternioni <X> operator / (const Quaternioni <X> c ,X g) // / scalare
	{if(g==0) cout <<"Errore\n"
	else
	Quaternioni <X> r=c;
	r/=g;
	return r;}

template <class X> Quaternioni <X> operator *= (X a, const Quaternioni <X> p) // *= scalare
	{Quaternioni <X> Al(a,0.,0.,0.);
	Al*=p;
	return Al;} 
	
template <class X> Quaternioni <X> operator * (X a, const Quaternioni<X> p) // * scalare
	{X c=a;
	return c*=p;} 

template <class X> double  Quaternioni <X>::angle() const //angolo di rotazione
	{return 2*acos(this->componenti[0]);}

template <class X> bool operator == (const Quaternioni <X> & t, const Quaternioni <X> & j)
	{t.componenti[0]==j.componenti[0] && 
	t.componenti[1]==j.componenti[1] && 
	t.componenti[2]==j.componenti[2] && 
	t.componenti[3]==j.componenti[3];};

template <class X> bool operator != (const Quaternioni<X> & t, const Quaternioni<X> & j) 
	{return !(t==j);};


 
template <class X> Quaternioni<X>  Quaternioni<X>::rot (Quaternioni<X> quat) const
	{return ((*this)*quat)*(!(*this));}

template <class X> bool  Quaternioni<X>::isNorm (double soglia)  const
	{return (abs((this->norm())-1)<=soglia);}

template <class X>  bool Quaternioni<X>::isNorm () const
	{return (abs((this->norm())-1)<=0.01);}

template <class X> X  Quaternioni<X>::Get_Cr() const {
	return this->componenti[0];}

template <class X> X  Quaternioni<X>::Get_Ci() const {
	return this->componenti[1];}

template <class X> X  Quaternioni<X>::Get_Cj() const {
	return this->componenti[2];}

template <class X> X  Quaternioni<X>::Get_Ck() const{
	return this->componenti[3];}

template <class X> ostream & operator << (ostream & o, const Quaternioni <X> b) //scrittura
	{return o <<setprecision(3) <<fixed <<noshowpos  << b.componenti[0]
	<<showpos  <<b.componenti[1] <<"i"  
	<<b.componenti[2] <<"j" 
	<<b.componenti[3] <<"k";}
 
template <class X> SOtre<X>::SOtre(Quaternioni <X> q): s(1/(q.norm()*(q.norm()))) {
	elemento[0][0]=1-2*s*(q.Get_Cj()*q.Get_Cj()+q.Get_Ck()*q.Get_Ck()),  
	elemento[0][1]=2*s*(q.Get_Ci()*q.Get_Cj()-q.Get_Ck()*q.Get_Cr()),       
	elemento[0][2]=2*s*(q.Get_Ci()*q.Get_Ck()+q.Get_Cj()*q.Get_Cr()), 
	elemento[1][0]=2*s*(q.Get_Ci()*q.Get_Cj()+q.Get_Ck()*q.Get_Cr()),  
	elemento[1][1]=1-2*s*(q.Get_Ci()*q.Get_Ci()+q.Get_Ck()*q.Get_Ck()), 
	elemento[1][2]=2*s*(q.Get_Cj()*q.Get_Ck()-q.Get_Ci()*q.Get_Cr()),
	elemento[2][0]=2*s*(q.Get_Ci()*q.Get_Ck()-q.Get_Cj()*q.Get_Cr()), 
	elemento[2][1]=2*s*(q.Get_Cj()*q.Get_Ck()+q.Get_Ci()*q.Get_Cr()), 
	elemento[2][2]=1-2*s*(q.Get_Ci()*q.Get_Ci()+q.Get_Cj()*q.Get_Cj());}

template <class X> X SOtre<X>::Get_El11() const 
	{return this->elemento[0][0];}

template <class X> X SOtre<X>::Get_El12() const
	{return this->elemento[0][1];}

template <class X> X SOtre<X>::Get_El13() const 
	{return this->elemento[0][2];}
	
template <class X> X SOtre<X>::Get_El21() const 
	{return this->elemento[1][0];}
	
template <class X> X SOtre<X>::Get_El22() const 
	{return this->elemento[1][1];}

template <class X> X SOtre<X>::Get_El23() const 
	{return this->elemento[1][2];}

template <class X>  X SOtre<X>::Get_El31() const 
	{return this->elemento[2][0];}

template <class X> X  SOtre<X>::Get_El32() const 
	{return this->elemento[2][1];}

template <class X> X  SOtre<X>::Get_El33() const 
	{return this->elemento[2][2];}



template <class X> ostream & operator << (ostream & o, const SOtre<X> a)  //scrittura SO3
	{ return  o <<fixed <<setprecision(2)  
	<<setw(12) <<a.elemento[0][0] <<setw(12) <<a.elemento[0][1]  <<setw(12) <<a.elemento[0][2] <<endl
	<<setw(12) <<a.elemento[1][0] <<setw(12) <<a.elemento[1][1]  <<setw(12) <<a.elemento[1][2] <<endl
	<<setw(12) <<a.elemento[2][0] <<setw(12) <<a.elemento[2][1]  <<setw(12) <<a.elemento[2][2]  <<endl;}


template <class X> Vettori<X>::Vettori(Quaternioni <X> q) {
	coordinate[0]=q.Get_Ci()/(sqrt(1-q.Get_Cr()*q.Get_Cr()));
	coordinate[1]=q.Get_Cj()/(sqrt(1-q.Get_Cr()*q.Get_Cr()));
	coordinate[2]=q.Get_Ck()/(sqrt(1-q.Get_Cr()*q.Get_Cr()));}

template <class X> X Vettori<X>::Get_x() const {
	return this->coordinate[0];}

template <class X> X  Vettori<X>::Get_y() const  {
	return this->coordinate[1];}

template <class X> X  Vettori<X>::Get_z() const  {
	return this->coordinate[2];}


template <class X> ostream & operator << (ostream & o, const Vettori <X> v)  //scrittura
	{return o <<setprecision(2) <<fixed <<noshowpos 
	<<(v.coordinate[0]) <<' ' 
	<<(v.coordinate[1]) <<' '
	<<(v.coordinate[2]);}



