#include <iostream>
#include "MyVector.h"
//cmake -G "MinGW Makefiles" ../

int main()
{
    std::cout << "Beginning of program... " << std::endl;
    
    MyVector<int> V1(1,0);
    MyVector<double> V2;
    MyVector<char> V3;
    char a = 11, b = 22, c = 33;
    int type;

    for(int i = 1; i <= 9; i++)
    {
        V1.push_back(i);
    }

    V2.push_back(2.5);
    V2.push_back(3.14);
    V2.push_back(56.325);
    
    V3.push_back(a);
    V3.push_back(b);
    V3.push_back(c);

    std::cout << "Enter an number of type (0 - integer; 1 - double; 2 - char): ";
    std::cin >> type;
    switch (type)
    {
    case 0:
    std::cout << "________Integer Numbers________"<< std::endl << std::endl;

    std::cout << "Int vector : " << V1 << std::endl;
    std::cout << "Element at index [3] : " << V1[3] << std::endl;
    std::cout << "Element at index [7] : " << V1[7] << std::endl;
    std::cout << "Length of vector : "  << V1.length()  << std::endl << std::endl;

    std::cout << "Insert new values..." << std::endl << std::endl;
    V1.insert(2,40);
    V1.insert(4,60);
    std::cout << "Int vector : " << V1 << std::endl;
    std::cout << "Length of vector : "  << V1.length()  << std::endl << std::endl;

    std::cout << "Push back new value..." << std::endl << std::endl;
    V1.push_back(100);
    std::cout << "Int vector : " << V1 << std::endl;
    std::cout << "Length of vector : "  << V1.length()  << std::endl << std::endl;
 
    std::cout << "Delete back value..." << std::endl << std::endl;
    V1.pop_back();
    std::cout << "Int vector : " << V1 << std::endl;
    std::cout << "Length of vector : "  << V1.length()  << std::endl << std::endl;
        break;//case 0
    case 1:
    std::cout << "________Double Numbers________"<< std::endl << std::endl;
    
    std::cout << "Double vector : " << V2 << std::endl;
    std::cout << "Element at index [1] : " << V2[1] << std::endl;
    std::cout << "Element at index [2] : " << V2[2] << std::endl;
    std::cout << "Length of vector : "  << V2.length()  << std::endl << std::endl;

     std::cout << "Insert new values..." << std::endl << std::endl;
    V2.insert(2,(double)(rand())/RAND_MAX);
    std::cout << "Double vector : " << V2 << std::endl;
    std::cout << "Length of vector : "  << V2.length()  << std::endl << std::endl;

    std::cout << "Push back new value..." << std::endl << std::endl;
    V2.push_back(0.746605);
    std::cout << "Double vector : " << V2 << std::endl;
    std::cout << "Length of vector : "  << V2.length()  << std::endl << std::endl;
 
    std::cout << "Delete back value..." << std::endl << std::endl;
    V2.pop_back();
    std::cout << "Double vector : " << V2 << std::endl;
    std::cout << "Length of vector : "  << V2.length()  << std::endl << std::endl;
        break;//case 1
    case 2:
    std::cout << "________Char type________"<< std::endl << std::endl;
    
    std::cout << "Char vector : " << V3 << std::endl;
    std::cout << "Element at index [1] : " << V3[1] << std::endl;
    std::cout << "Element at index [2] : " << V3[2] << std::endl;
    std::cout << "Length of vector : "  << V3.length()  << std::endl << std::endl;

    std::cout << "Insert new values..." << std::endl << std::endl;
    V3.insert(2,a);
    std::cout << "Char vector : " << V3 << std::endl;
    std::cout << "Length of vector : "  << V3.length()  << std::endl << std::endl;

    std::cout << "Push back new value..." << std::endl << std::endl;
    V3.push_back(b);
    std::cout << "Char vector : " << V3 << std::endl;
    std::cout << "Length of vector : "  << V3.length()  << std::endl << std::endl;
 
    std::cout << "Delete back value..." << std::endl << std::endl;
    V3.pop_back();
    std::cout << "Char vector : " << V3 << std::endl;
    std::cout << "Length of vector : "  << V3.length()  << std::endl << std::endl;
        break;//case 2
    default:
        std::cout << "Incorrect value";
        return 0;
    }//switch (type) 
    return 0;
}