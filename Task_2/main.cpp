#include <iostream>
#include "Task_2.h"
#include <string>

//cmake -G "MinGW Makefiles" ../

int main()
{
    std::cout << "Beginning of program... " << std::endl;
    
    Task_2<std::string> str_res;
    Task_2<int> int_res;
    Task_2<double> double_res;
    Task_2<char> char_res;
    int a = 2, b = 1;
    double c = 1.5, d = 2.5;
    char e = 5, i = 10;
    std::string str1 = "BA", str2 = "AB"; 
    
    std::cout << "The first string: "<< str1 << std::endl;
    std::cout << "The second string: "<< str2 << std::endl;
    std::cout << "Size of first string: "<< str1.size() << std::endl;
    std::cout << "Size of second string: "<< str2.size() << std::endl;
    std::cout << "The first string to int: " << str_res.strToInt(str1) << std::endl;
    std::cout << "The second string to int: " << str_res.strToInt(str2) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Sum int: \"" << a << "\" + \"" << b << "\" = "<< int_res.Sum(a,b) << std::endl;
    std::cout << "Sum double: \"" << c << "\" + \"" << d << "\" = "<< double_res.Sum(c,d) << std::endl; 
    std::cout << "Sum char: \"" << static_cast<double>(e) << "\" + \"" << static_cast<double>(i) << "\" = "<< static_cast<double>(char_res.Sum(e,i)) << std::endl;  
    std::cout << "Sum string: \"" << str1 << "\" + \"" << str2 << "\" = "<< str_res.Sum(str1,str2) << std::endl;
    std::cout << std::endl;

    std::cout << "Comparing int: \"" << a << "\" and \"" << b << "\" : "<< int_res.Comp(a,b) << " is greater" << std::endl;
    std::cout << "Comparing double: \"" << c << "\" and \"" << d << "\" : "<< double_res.Comp(c,d) << " is greater" << std::endl;
    std::cout << "Comparing char: \"" << static_cast<double>(e) << "\" and \"" << static_cast<double>(i) << "\" : "<< static_cast<double>(char_res.Comp(e,i)) << " is greater" << std::endl;
    std::cout << "Comparing string: \"" << str1 << "\" and \"" << str2 << "\" : "<< str_res.Comp(str1,str2) << " is greater" << std::endl;
    return 0;
}