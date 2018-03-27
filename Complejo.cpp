#include <iostream>
#include "Complejo.h"
#include <string>
#include <cmath>
using namespace std;


//CONSTRUCTORES y DESTRUCTORES:
Complejo::Complejo(){
	_Re=0;
	_Im=0;
}
Complejo::Complejo(double const R, double const I){
	_Re=R;
	_Im=I;
}
Complejo::Complejo(Complejo const &z1){
	_Re=z1.GetRe();
	_Im=z1.GetIm();
}
Complejo::~Complejo(){}


//OUTPUTS
void Complejo::print(){
	cout<<'('<<_Re<<','<<_Im<<')'<<endl;
}

double Complejo::GetRe() const{
	return _Re;
}

double Complejo::GetIm() const{
	return _Im;
}

//OPERATIONS
Complejo const &Complejo::operator=(Complejo const &z){
 	_Re=z.GetRe();
 	_Im=z.GetIm();
 	return *this;
}

Complejo const operator+(Complejo const &x, Complejo const &y){
	Complejo z(x.GetRe() + y.GetRe(), x.GetIm() + y.GetIm());
	return z;
}

Complejo const operator+(Complejo const &x, double const i){
	Complejo z(x.GetRe() + i, x.GetIm());
	return z;
}

Complejo const operator+(double const b,Complejo const & a)
{
	Complejo d(b + a.GetRe(), a.GetIm());
	return d;
}

Complejo const operator-(Complejo const &x, Complejo const &y){
	Complejo z(x.GetRe() - y.GetRe(), x.GetIm() - y.GetIm());
	return z;
}

Complejo const operator-(Complejo const &x, double const i){
	Complejo z(x.GetRe() - i, x.GetIm());
	return z;
}

Complejo const operator-(double const b,Complejo const & a)
{
	Complejo d(b - a.GetRe(), -a.GetIm());
	return d;
}

Complejo const operator*(Complejo const &z1, Complejo const &z2){
	Complejo z(z1.GetRe() * z2.GetRe()-z1.GetIm() * z2.GetIm() , z1.GetRe()*z2.GetIm()+z1.GetIm()*z2.GetRe());
	return z;
}

Complejo const operator*(Complejo const &z1, double const Q){
	Complejo z(z1.GetRe() * Q , z1.GetIm()*Q);
	return z;
}

Complejo const operator*(double const Q, Complejo const &z1){
	Complejo z(z1.GetRe() * Q , z1.GetIm()*Q);
	return z;
}

Complejo const &Complejo::Conjugar(){
 	_Im*=-1;
 	return *this;
}

Complejo const Complejo::Conjugado()const{
	return Complejo(_Re,-(_Im));
}

Complejo const operator/(Complejo const &z1, double const Q){
	if(Q!=0){
	Complejo z(z1.GetRe() / Q , z1.GetIm()/Q);
	return z;
	} else return z1;
}

Complejo const operator/(Complejo const &z1, Complejo const &z2){ 
	return (z1*z2.Conjugado())/z2.abs2();
}

Complejo const operator/(double const Q, Complejo const &z2){ 
	return (Q*z2.Conjugado())/z2.abs2();
}

double Complejo::abs() const{
	return sqrt((_Re*_Re)+(_Im+_Im));
}

double Complejo::abs2 () const{
	return ((_Re*_Re)+(_Im+_Im));
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
