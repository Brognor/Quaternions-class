struct quaternioni { 
double co [4]; //componenti

quaternioni operator = (quaternioni); //uguaglianza
	
quaternioni operator + (quaternioni); //somma
	
quaternioni operator - (quaternioni); //sottrazione	

quaternioni operator += (quaternioni); //+=
	
quaternioni operator -= (quaternioni); //-=

quaternioni operator *= (quaternioni); //*=
	
quaternioni operator * (quaternioni); //prodotto
	
quaternioni operator * (); //coniugato

quaternioni operator -- (); //inverso
	
double operator / (quaternioni); //distanza

quaternioni operator -(); // opposto

quaternioni operator +(); // se stesso medesimo

double operator ~ (); //modulo

double operator !(); //angolo di rotazione
	
quaternioni operator * (double); // * scalare

quaternioni operator / (double); // / scalare	

quaternioni operator *= (double); // *= scalare
	
quaternioni operator /= (double); // /= scalare
	
quaternioni ()=default;

quaternioni(double , double , double , double );

quaternioni(double , double *);

quaternioni rot (quaternioni);

bool ver ();
   //******************************//
}; //fine della classe quaternioni//
   //****************************//


struct SOtre //Struct SO3
{double el [3][3];
double s;
SOtre(quaternioni);

SOtre()=default;
}; //fine struct SO3

	
struct vettori{
vettori()=default;
double co[3];
vettori(quaternioni);
};
std::ostream & operator << (std::ostream & , vettori );
std::ostream & operator << (std::ostream & , SOtre ) ;//scrittura SO3
std::ostream & operator << (std::ostream & , quaternioni ); //scrittura
