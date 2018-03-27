//clase Complejo. Implementación de numeros complejos
#include <iostream>
class Complejo{
private:	
	double _Re, _Im;
public:
	Complejo();										//crea un complejo inicializado en cero por defecto.
	Complejo(double const real, double const imaginary);// crea un complejo y asigna su valor.
	Complejo(Complejo const &z);
	double GetRe() const;								//Devuelve la parte Real del numero complejo
	double GetIm() const;								//Devuelve la parte Imaginaria del Numero Complejo
	void print();									//Imprime el numero complejo como "(Re,Im)"
	Complejo const &Conjugar();						//Modifica el valor al conjudado
	Complejo const Conjugado()const;						//Modifica el valor al conjudado POR QUE EL CONST DEL FINAL??
	double abs() const;						//obtiene el valor absluto de un complejo
	double abs2() const;						//obtiene el valor absluto al cuadrado de un complejo
	Complejo const &operator= (Complejo const &z1);	//copia el valor de una variable compleja.
	friend Complejo const operator+ (Complejo const &z1, Complejo const &z2);	//Suma dos valores y los asigna a una variable Lvalue POR QUE PONGO FRIEND???
	friend Complejo const operator+ (Complejo const &z1, double const Q);	//Suma dos valores y los asigna a una variable Lvalue POR QUE PONGO FRIEND???
	friend Complejo const operator- (Complejo const &z1, Complejo const &z2);	//Suma dos valores y los asigna a una variable Lvalue POR QUE PONGO FRIEND???
	friend Complejo const operator- (Complejo const &z1, double const Q);	//Suma dos valores y los asigna a una variable Lvalue POR QUE PONGO FRIEND???
	friend Complejo const operator* (Complejo const &z1, Complejo const &z2);	//Suma dos valores y los asigna a una variable Lvalue POR QUE PONGO FRIEND???
	friend Complejo const operator* (Complejo const &z1, double const Q);	//Suma dos valores y los asigna a una variable Lvalue POR QUE PONGO FRIEND???
	friend Complejo const operator* (double const Q, Complejo const &z1);	//Suma dos valores y los asigna a una variable Lvalue POR QUE PONGO FRIEND???
	friend Complejo const operator/ (Complejo const &z1, Complejo const &z2);	//Suma dos valores y los asigna a una variable Lvalue POR QUE PONGO FRIEND???
	friend Complejo const operator/ (Complejo const &z1, double const Q);	//Suma dos valores y los asigna a una variable Lvalue POR QUE PONGO FRIEND???
	friend Complejo const operator/ (double const Q, Complejo const &z1);	//Suma dos valores y los asigna a una variable Lvalue POR QUE PONGO FRIEND???
	~Complejo();								//Destruye un complejo
};
