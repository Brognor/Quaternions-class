#ifndef QUATERNIONI_H
#define QUATERNIONI_H


template <class X> class Quaternioni { 
	X componenti [4]; //componenti

	public:
	Quaternioni<X> & operator = (Quaternioni<X>); //assegnamento 

	Quaternioni<X> & operator += (Quaternioni<X>); //+=	
	
	Quaternioni<X> & operator -= (Quaternioni<X>); //-=

	Quaternioni<X> & operator += (const X); //+= num
	
	Quaternioni<X> & operator -= (const X); //-= num

	Quaternioni<X> & operator *= (Quaternioni<X>); //*=

	Quaternioni<X> & operator *= (X); // *= scalare
	
	Quaternioni<X> & operator /= (X); // /= scalare

	template <class Y> Quaternioni <Y>   friend operator !(const Quaternioni <Y>); //inverso

	template <class Y> Quaternioni <Y> friend   operator ~ (const Quaternioni <Y>); //coniugato

	template <class Y> bool friend operator == (const Quaternioni<Y> &, const Quaternioni<Y> &);
		 
	template <class Y> bool friend operator != (const Quaternioni<Y> &, const Quaternioni<Y> &);

	Quaternioni<X> ()=default;

	Quaternioni<X> (X , X , X , X );

	Quaternioni<X> (X , X *);
	
	Quaternioni<X> rot (Quaternioni<X>) const ;

	bool isNorm  (double)const;

	bool isNorm () const;

	double norm () const; //modulo

	double angle () const; //angolo di rotazione

	X Get_Cr() const; //Getter quaternioni

	X Get_Ci() const;

	X Get_Cj() const;

	X Get_Ck()const;

template <class Y> friend std::ostream &  operator << (std::ostream & , const Quaternioni <Y> ); //scrittura

};// [Quaternioni]

template <class X> Quaternioni<X> operator + (Quaternioni<X> const, const Quaternioni<X>);//somma

template <class X> Quaternioni<X> operator - (Quaternioni<X> const, const Quaternioni<X>); //sottrazione

template <class X> Quaternioni<X> operator += ( X, const Quaternioni <X>);//+= num

template <class X> Quaternioni<X> operator -= (X, const Quaternioni <X>); //-= num

template <class X> Quaternioni<X> operator + (const X, const Quaternioni<X>);//num somma 


template <class X> Quaternioni<X> operator - (const Quaternioni<X> , const X); //sottrazione num

template <class X> Quaternioni<X> operator + (const X, const Quaternioni<X>);//num somma 

template <class X> Quaternioni<X> operator - (const X, const Quaternioni<X>); //num sottrazione 

template <class X> Quaternioni<X> operator * (Quaternioni<X> const, const Quaternioni<X>); //prodotto
	
template <class X> double operator | (const Quaternioni<X>, const Quaternioni<X>); //distanza

template <class X> Quaternioni<X> operator -(const Quaternioni<X> ); // opposto

template <class X> Quaternioni<X> operator +(const Quaternioni<X>); // se stesso medesimo
	
template <class X> Quaternioni<X> operator * (const Quaternioni<X>, X); // * scalare

template <class X> Quaternioni<X> operator / (const Quaternioni<X>, X); // / scalare	

template <class X> Quaternioni<X> operator * (const X, const Quaternioni<X>); // * scalare	

template <class X> Quaternioni<X> operator *= (X, const Quaternioni<X>); // *= scalare

template < class X> class SOtre //Struct SO3

	{X elemento [3][3];
	double s;

	public:
	SOtre(Quaternioni <X>);
	
	SOtre()=default;

template <class Y> friend std::ostream & operator << (std::ostream & , const SOtre<Y> ) ;//scrittura SO3

	X Get_El11() const ; //Getter matrice

	X Get_El12() const ;

	X Get_El13() const ;

	X Get_El21() const ;

	X Get_El22() const ;

	X Get_El23() const ;

	X Get_El31() const ;

	X Get_El32() const ;

	X Get_El33() const;}; //[SO3]

template <  class X> class Vettori{
	X coordinate[3];
	public:
	Vettori()=default;

	Vettori(Quaternioni <X>);

template <  class Y> friend std::ostream & operator << (std::ostream & , const Vettori<Y> ) ;

	X Get_x() const ; //Getter vettori

	X Get_y() const ;

	X Get_z() const ;
};//[Vettori]


#endif
