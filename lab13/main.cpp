/*
 Celem zadania jest przećwiczenie szablonów klas.
 W tym celu napiszemy klasy Array i Vect. Ich rozmiary są podane 
 jako parametr szablonu i są niezmienne.

*/

#include <iostream>
#include "Array.h"
#include "Vect.h"

// #define ERROR1
// #define ERROR2
// #define ERROR3

int main(){
	Array<double, 2, 4> arrayDouble{2.4}; // macierz wypełniona 2.4
	Array<int, 3, 3> arrayInt{3};
	Vect<double, 4> v1{2.2};	// wektor wypełniony 2.2
	const Vect<double, 3> v2{3.4};
	Vect<int, 4> v3{4};
	
	#ifdef ERROR1
	Vect<std::string, 4> v3{"4"};
	#endif

	static_assert(sizeof(v1) == 4 * sizeof(double), "wrong size");
	static_assert(sizeof(arrayInt) == 9 * sizeof(int), "wrong size");

	arrayDouble(1, 2) = -10;
	arrayDouble(0, 1) = -2;

	arrayInt(0, 2) = -1;
	arrayInt(1, 0) = -3;

	arrayDouble.print("---------------");
	arrayInt.print("=============");
	std::cout << "v1 = " << v1 << std::endl; 
	std::cout << "v2 = " << v2 << std::endl;
	std::cout << "v3 = " << v3 << std::endl;
	std::cout << "iloczyn skalarny: " << v1*v3 << std::endl; 
	std::cout << "iloczyn skalarny: " << v3*v1 << std::endl; 

	std::cout << "=== mnozenie ===" << std::endl;
	std::cout << (arrayDouble * v1) << std::endl;
	std::cout << (arrayDouble * v3) << std::endl;
	std::cout << (arrayInt * v2) << std::endl;
	static_assert(sizeof(v3 * v3) == sizeof(int), "wrong size");

	// nie mogą się kompilować. "error: no match for ‘operator*’ (operand types are... 
	#ifdef ERROR2
	arrayInt * v3;
	#endif
	#ifdef ERROR3
	v1 * v2;
	#endif

}

/* wynik
---------------
2.4  -2 2.4 2.4 
2.4 2.4 -10 2.4 
---------------
=============
  3   3  -1 
 -3   3   3 
  3   3   3 
=============
v1 = [ 2.2 2.2 2.2 2.2 ]
v2 = [ 3.4 3.4 3.4 ]
v3 = [   4   4   4   4 ]
iloczyn skalarny: 35.2
iloczyn skalarny: 35.2
=== mnozenie ===
[ 11.44 -6.16 ]
[ 20.8 -11.2 ]
[  17 10.2 30.6 ]

*/
