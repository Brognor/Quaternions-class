#ifndef QUATERNIONI_H
#define QUATERNIONI_H

class Quaternioni { 
	double componenti [4]; //componenti
	public:
	Quaternioni & operator = (Quaternioni); //assegnamento 

	Quaternioni & operator += (Quaternioni); //+=	
	
	Quaternioni & operator -= (Quaternioni); //-=

	Quaternioni & operator *= (Quaternioni); //*=

	Quaternioni & operator *= (double); // *= scalare
	
	Quaternioni & operator /= (double); // /= scalare

	friend Quaternioni  operator !(const Quaternioni); //inverso

	friend Quaternioni operator ~ (const Quaternioni); //coniugato

	friend bool operator == (const Quaternioni &, const Quaternioni &);

	friend bool operator != (const Quaternioni &, const Quaternioni &);

	Quaternioni ()=default;

	Quaternioni(double , double , double , double );

	Quaternioni(double , double *);
	
	Quaternioni rot (Quaternioni) const ;

	bool isNorm  (double)const;

	bool isNorm () const;

	double norm () const; //modulo

	double angle () const; //angolo di rotazione

	double Get_Cr() const; //Getter quaternioni

	double Get_Ci() const;

	double Get_Cj() const;

	double Get_Ck()const;

	friend std::ostream & operator << (std::ostream & , const Quaternioni ); //scrittura

};// [Quaternioni]

	Quaternioni operator + (const Quaternioni, const Quaternioni ); //somma

	Quaternioni operator - (Quaternioni const, const Quaternioni); //sottrazione	

	Quaternioni operator * (Quaternioni const, const Quaternioni); //prodotto
	
	double operator | (const Quaternioni, const Quaternioni); //distanza

	Quaternioni operator -(const Quaternioni ); // opposto

	Quaternioni operator +(const Quaternioni); // se stesso medesimo
	
	Quaternioni operator * (const Quaternioni, double); // * scalare

	Quaternioni operator / (const Quaternioni, double); // / scalare	

	Quaternioni operator * (double, const Quaternioni); // * scalare	

	Quaternioni operator *= (double, const Quaternioni); // *= scalare

class SOtre //Struct SO3

	{double elemento [3][3];
	double s;

	public:
	SOtre(Quaternioni);
	
	SOtre()=default;

	friend std::ostream & operator << (std::ostream & , const SOtre ) ;//scrittura SO3

	double Get_El11() const ; //Getter matrice

	double Get_El12() const ;

	double Get_El13() const ;

	double Get_El21() const ;

	double Get_El22() const ;

	double Get_El23() const ;

	double Get_El31() const ;

	double Get_El32() const ;

	double Get_El33() const;}; //[SO3]

class Vettori{
	double coordinate[3];
	public:
	Vettori()=default;

	Vettori(Quaternioni);

	friend std::ostream & operator << (std::ostream & , const Vettori ) ;

	double Get_x() const ; //Getter vettori

	double Get_y() const ;

	double Get_z() const ;
};//[Vettori]

#endif

