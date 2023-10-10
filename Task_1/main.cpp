#include <iostream>
#include <string>
#include "MyVector.h"
//cmake -G "MinGW Makefiles" ../

int main()
{
    std::cout << "Beginning of program... " << std::endl;

    std::cout << "________Tes 1________" << std::endl;
    MyVector<int> v1(10);
    std::size_t n1 = v1.size();
    for (int i = 0; i < n1; ++i)
        v1[i] = i+1;
    v1.show();
    std::cout << std::endl;

    std::cout << "________Tes 2________" << std::endl;
    std::string initStr[5] = {"first","second","third","fourth","fifth"};
    
    MyVector<std::string> v2(5);
    std::size_t n2 = v2.size();
    for (int i = 0; i < n2; ++i)
        v2[i] = initStr[i];

    v2.show();
    v2.insert(v2.begin() + 3, "After_third");
    v2.show();
    //std::cout << v2[6] << std::endl;
    v2.push_back("Add_1");
    v2.push_back("Add_2");
    v2.push_back("Add_3");
    v2.show();

    v2.pop_back();
    v2.pop_back();
    v2.show();
    std::cout << std::endl;
    return 0;
}