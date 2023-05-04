/* Celem zadania jest napisanie standardowego konetnera, jakim jest tablica liczb całkowitych. Tablica ta musi mieć rozmiar określany dynamicznie podczas działania programu.
Rozwiązanie z tablicami statycznimi jest oceniane na 0 punktów!
Korzystanie z kontenrów biblioteki standardowej jest zabronione!
 
Do napisania są:
- wszystkie konstruktory, w tym kopiujący i przenoszący
- destruktor (głośny - wypisuje komunikat na ekran
- operator przypisania =
- metoda size i operator dostępu do elementów tablicy []
- operator ++ inkrementujący wszystkie pola w tablicy
- metoda print i operator wypisania na ekran <<
- operator + dodający liczbę do wszystkich elementów tablicy

Proszę zadbać o zarządzanie pamięcią.
*/


#include "MyArray.h"
#include <iostream>


int main() 
{
    std::cout << "Moja tablica liczb calkowitych!" << std::endl;
    
    //----------------------------------------------------
  	std::cout << "\nKonstruktor obiektu i metoda print" << std::endl;
    MyArray arr(6);
    arr.print("arr");
    
    //----------------------------------------------------
    std::cout << "\nOperator dostępu i metoda size" << std::endl;
    for(int i = 0; i<arr.size(); ++i)
    {
        arr[i] = i;
    }
    arr.print("arr");
    
    //----------------------------------------------------
    std::cout << "\nOperator wypisywania na ekran" << std::endl;
	  std::cout << "arr = " << arr << std::endl;
    
    //----------------------------------------------------
    
    std::cout << "\nInkrementacja" << std::endl;
    ++arr;
    arr.print("arr");
    
    //----------------------------------------------------
    
    std::cout << "\nKonstruktor kopiujący" << std::endl;
    const MyArray arrCopy = arr;
    arrCopy.print("copy");
        
    //----------------------------------------------------
    
    std::cout << "\nSprawdzenie glebokiej kopii" << std::endl;
    arr[4] = 99;
    std::cout <<  "arr[5] = " << arr[4] << ", " << 
                 "copy[5] = " << arrCopy[4] << std::endl;
        
    //----------------------------------------------------
    
    std::cout << "\nOperator przypisania" << std::endl;
    MyArray arr2(4);
    arr2.print("arr2");
    arr2 = arr2 = arr;
    arr2.print("arr2");
                //----------------------------------------------------  
    
    std::cout << "\nOperator dodawania" << std::endl;
    arr2 += 2; 
    std::cout << "arr2 = " << arr2 << std::endl;
    const MyArray arr3 = arr2; 
    arr2 = arr3 + 3;
    arr2.print("arr3");
    
    arr2 = 10 + arr3;
    arr2.print("arr3");
     //----------------------------------------------------
    
    std::cout << "\nKonstruktor przenoszacy" << std::endl;
    arr.print("arr");
    MyArray marr = std::move(arr);
    arr.print("arr");
    marr.print("moved arr");

  
    //----------------------------------------------------
    std::cout << "\nDestruktory" << std::endl;
    
}

/* Oczekiwany wynik ./main
Moja tablica liczb calkowitych!

Konstruktor obiektu i metoda print
arr = [0, 0, 0, 0, 0, 0]

Operator dostępu i metoda size
arr = [0, 1, 2, 3, 4, 5]

Operator wypisywania na ekran
arr = [0, 1, 2, 3, 4, 5]

Inkrementacja
arr = [1, 2, 3, 4, 5, 6]

Konstruktor kopiujący
copy = [1, 2, 3, 4, 5, 6]

Sprawdzenie glebokiej kopii
arr[5] = 99, copy[5] = 5

Operator przypisania
arr2 = [0, 0, 0, 0]
arr2 = [1, 2, 3, 4, 99, 6]

Operator dodawania
arr2 = [3, 4, 5, 6, 101, 8]
Usuwam tablice
arr3 = [6, 7, 8, 9, 104, 11]
Usuwam tablice
arr3 = [13, 14, 15, 16, 111, 18]

Konstruktor przenoszacy
arr = [1, 2, 3, 4, 99, 6]
arr = []
moved arr = [1, 2, 3, 4, 99, 6]

Destruktory
Usuwam tablice
Usuwam tablice
Usuwam tablice
Usuwam tablice
Usuwam tablice
*/