#include <iostream>
#include "Complejo.cpp"
using namespace std;
int main()
{
	Complejo z1;
	Complejo z2(1,0);
	Complejo z3(2,3);
	double Q=5;
	//funciones constructoras y de salida por pantalla
	cout<<"z1=";
	z1.print();
	cout<<"z2=";
	z2.print();
	cout<<"z3=";
	z3.print();
	cout<<"z1=z2*z3"<<endl;
	z1=z2-z3;
	cout<<"z1=";
	z1.print();
	cout<<"z2=";
	z2.print();
	cout<<"z3=";
	z3.print();
	z3.Conjugar();
	cout<<"z3=";
	z3.print();
	z1=z3.Conjugado();
	cout<<"z1=";
	z1.print();
	cout<<"z3=";
	z3.print();



	return 0;
}