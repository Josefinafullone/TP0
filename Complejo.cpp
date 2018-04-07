#include"Complejo.h"
#include<iostream>
#include<string.h>
#include<cmath>

using namespace std;

//CONSTRUCTORES

Complejo::Complejo()
{
	Re_=0.0;
	Im_=0.0;
}

Complejo::Complejo(double const real,double const imaginario)
{
	Re_=real;
	Im_=imaginario;
}

Complejo::Complejo(const Complejo & c)
{
	Re_=c.Re_;
	Im_=c.Im_;
}

Complejo const & Complejo::operator=(Complejo const & c)
{
	Re_=c.GetRe();
	Im_=c.GetIm();
	return *this;
}

//

double Complejo::GetRe()const
{
	return Re_;
}

double Complejo::GetIm()const
{
	return Im_;
}

void Complejo::print()
{
	cout <<'('<< Re_ << ',' << Im_ << ')'<< endl;
}

Complejo::~Complejo(){}


//OPERADORES

Complejo const operator+(Complejo const & a,Complejo const & b)
{
	Complejo d(a.GetRe() + b.GetRe(),a.GetIm() + b.GetIm());
	return d;
}

Complejo const operator+(Complejo const & a,double b)
{
		Complejo d(a.GetRe() + b,a.GetIm());
		return d;
}

Complejo const operator+(double const b,Complejo const & a)
{
	Complejo d(b + a.GetRe(), a.GetIm());
	return d;
}

Complejo const operator-(Complejo const & a,Complejo const & b)
{
	Complejo d(a.GetRe() - b.GetRe(),a.GetIm() - b.GetIm());
	return d;
}

Complejo const operator-(Complejo const & a,double b)
{
		Complejo d(a.GetRe() - b,a.GetIm());
		return d;
}

Complejo const operator-(double const b,Complejo const & a)
{
	Complejo d(b - a.GetRe(), -a.GetIm());
	return d;
}


Complejo const operator*(Complejo const & a,Complejo const & b)
{
	return Complejo(a.GetRe()*b.GetRe()-a.GetIm()*b.GetIm(),a.GetRe()*b.GetIm()+a.GetIm()*b.GetRe());
}

Complejo const operator*(Complejo const & a,double const b)
{
	return Complejo(a.GetRe()*b,a.GetIm()*b);
}

Complejo const operator*(double const a,Complejo const & c)
{
	return Complejo(a*c.GetRe(),a*c.GetIm());
} 

Complejo const operator/(Complejo const & a,Complejo const & b)
{
	return ((a * b.Conjugado()) / (b.Abs_Cuadrado()));
}

Complejo const operator/(Complejo const & a,double const b)
{
	if(b!=0)
	{
		return Complejo(a.GetRe()/b,a.GetIm()/b);
	}
	else Complejo(a);
}

Complejo const operator/(double const b,Complejo const & a)
{
	
	return b*a.Conjugado()/a.Abs_Cuadrado();
	
}

Complejo const & Complejo:: Conjugar ()
{
	Im_*= -1;
	return *this;
}

Complejo const Complejo:: Conjugado() const
{
		return Complejo(Re_,-Im_);
}

double Complejo::Abs_Cuadrado()const
{
	return (Re_ * Re_ + Im_ * Im_);
}

double Complejo::Abs()const
{
	return sqrt(Re_ * Re_ + Im_ * Im_);
}



Complejo const & Complejo::operator*=(Complejo const &c)
{
	double Real,Imag; 
	Real = Re_ * c.Re_- Im_ * c.Im_;
	Imag = Re_ * c.Im_+ Im_ * c.Re_;
	Re_ = Real;
	Im_ = Imag;
	return *this;
}

Complejo const & Complejo::operator+=(Complejo const &c)
{
	double Real,Imag;
	Real = Re_ + c.Re_;
	Imag = Imag + c.Im_;
	Re_ = Real;
	Im_ = Imag;
	return *this;
}

Complejo const & Complejo::operator-=(Complejo const &c)
{
	double Real,Imag;
	Real = Re_ - c.Re_;
	Imag = Imag - c.Im_;
	Re_ = Real;
	Im_ = Imag;
	return *this;
}

 istream & operator >> (istream & is, Complejo &c)
{
	bool good=false;
	bool bad=false;
	double re=0,im=0;
	char ch=0;
	if(is >> ch && ch=='(')
	{
		if(is >> re && is >>ch && ch==',' && is>>im && is>>ch && ch==')')
		{
			good=true;
		}
		else	bad=true;
	}
	else	if(is.good())
			{
				is.putback(ch);					//vuelve al caracter anterior. Aca tendría un loop infinito.
				if(is >> re) good=true;
				else bad=true;
			}
	if(good)
	{
		c.Re_=re;
		c.Im_=im;
	}
	if(bad)
		is.clear(ios::badbit);
	return is;
}
