#ifndef QUATERNIONI_H
#define QUATERNIONI_H
class Quaternioni { 
double componenti [4]; //componenti
public:
Quaternioni & operator = (Quaternioni); //assegnamento 

Quaternioni & operator += (Quaternioni); //+=	

Quaternioni operator + (Quaternioni); //somma

Quaternioni & operator -= (Quaternioni); //-=
	
Quaternioni operator - (Quaternioni); //sottrazione	

Quaternioni & operator *= (Quaternioni); //*=

Quaternioni operator * (Quaternioni); //prodotto
		
Quaternioni operator ~ (); //coniugato
	
double operator | (Quaternioni); //distanza

Quaternioni operator -(); // opposto

Quaternioni operator +(); // se stesso medesimo

Quaternioni  operator !(); //inverso
	
Quaternioni operator * (double); // * scalare

Quaternioni operator / (double); // / scalare	

Quaternioni & operator *= (double); // *= scalare
	
Quaternioni & operator /= (double); // /= scalare

friend Quaternioni operator * (double, Quaternioni); // * scalare	

friend Quaternioni operator *= (double, Quaternioni); // *= scalare


bool operator == (Quaternioni)	;

bool operator != (Quaternioni);

Quaternioni ()=default;

Quaternioni(double , double , double , double );

Quaternioni(double , double *);

Quaternioni rot (Quaternioni);

bool isNorm (double);

bool isNorm ();

double norm(); //modulo

double angle(); //angolo di rotazione

double Get_Cr(); //Getter quaternioni

double Get_Ci();

double Get_Cj();

double Get_Ck();

friend std::ostream & operator << (std::ostream & , Quaternioni ); //scrittura
};// [Quaternioni]

class SOtre //Struct SO3
	{double elemento [3][3];
	double s;
	public:
	SOtre(Quaternioni);
	
	SOtre()=default;

	friend std::ostream & operator << (std::ostream & , SOtre ) ;//scrittura SO3

	double Get_El11(); //Getter matrice

	double Get_El12();

	double Get_El13();

	double Get_El21();

	double Get_El22();

	double Get_El23();

	double Get_El31();

	double Get_El32();

	double Get_El33();}; //[SO3]

class Vettori{
	double coordinate[3];
	public:
	Vettori()=default;

	Vettori(Quaternioni);

	friend std::ostream & operator << (std::ostream & , Vettori );

	double Get_x(); //Getter vettori

	double Get_y();

	double Get_z();
	};//[Vettori]

#endif
