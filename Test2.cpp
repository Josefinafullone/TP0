#include<iostream>
#include<fstream> 
#include<string>
#include"Complejo.cpp"

using namespace std;

int main() 
{

	Complejo z(0,0);
	fstream is;
	int i=0;
 	is.open("prueba.txt");
 	while(!is.eof())
 	{
 		is >> z;
		if(is.good())
		{
			z.print();
			i=i+1;
		}
		else if(is.bad())
			{
				is.good(true);
			}		
 	}
	return 0;
}

