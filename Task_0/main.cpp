#include <iostream>
#include "Task_0.h"
#include "Task_0_temp.h"
//cmake -G "MinGW Makefiles" ../

template <typename T> T Sum(T& first, T& second)
{
    return first+second;
}

int main()
{
    std::cout << "Beginning of program... " << std::endl;
    Task_0_temp a,b,c;
    char numb1 = 10, numb2 = 5;
    int i = 10, e = 5;
    double o = 10, p = 5;
    std::cout << "Sum int: " << a.add(i,e) << std::endl;
    std::cout << "Sub int: " << a.subtract(i,e) << std::endl;
    std::cout << "Mult int: " << a.multiply(i,e) << std::endl;
    std::cout << "Div int: " << a.divide(i,e) << std::endl;
    std::cout << "Sum double: " << b.add(o,p) << std::endl;
    std::cout << "Sub double: " << b.subtract(o,p) << std::endl;
    std::cout << "Mult double: " << b.multiply(o,p) << std::endl;
    std::cout << "Div double: " << b.divide(o,p) << std::endl;
    std::cout << "Sum char: " << static_cast<double>(c.add(numb1,numb2)) << std::endl;
    std::cout << "Sub char: " << static_cast<double>(c.subtract(numb1,numb2)) << std::endl;
    std::cout << "Mult char: " << static_cast<double>(c.multiply(numb1,numb2)) << std::endl;
    std::cout << "Div char: " << static_cast<double>(c.divide(numb1,numb2)) << std::endl;
    

    return 0;
}