#include<iostream>
#include<string.h>
#include<cmath>

using namespace std;

class Complejo
{
	private:
		double Re_,Im_;
	public:
		Complejo();
		Complejo(double const real,double const imaginario);
		Complejo(Complejo const & z);
		~Complejo();
		double GetRe() const;
		double GetIm() const;
		void print ();
		Complejo const & operator = (Complejo const & c);
		friend Complejo const operator+(Complejo const & z1,Complejo const & z2);
		friend Complejo const operator+(Complejo const &,double);
		friend Complejo const operator+(double,Complejo const &);
		friend Complejo const operator-(Complejo const & z1,Complejo const & z2);
		friend Complejo const operator-(Complejo const &,double);
		friend Complejo const operator-(double,Complejo const &);
		friend Complejo const operator*(const Complejo &,const Complejo &);
		friend Complejo const operator*(const Complejo &,double);
		friend Complejo const operator*(double a,Complejo const &);
		friend Complejo const operator/(const Complejo &,const Complejo &);
		friend Complejo const operator/(const Complejo &,double);
		friend Complejo const operator/(double,const Complejo &);
		Complejo const & Conjugar ();
		Complejo const Conjugado()const;
		double Abs_Cuadrado() const;
		double Abs() const;
		Complejo const & operator*=(Complejo const &);
		Complejo const & operator+=(Complejo const &);
		Complejo const & operator-=(Complejo const &);
		friend istream & operator >> (istream & is, Complejo &c);

	
};
