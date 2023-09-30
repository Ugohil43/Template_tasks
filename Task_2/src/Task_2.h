#ifndef TASK_2
#define TASK_2
#include <string>
#include <iostream>
#include <math.h>

template<typename T>
class Task_2
{
public:
    Task_2(/* args */){}
    ~Task_2(){}

    T Sum(T& first, T& second)
    {
        return first+second;
    }

    T Comp(T& first, T& second)
    {
        if (first == second)
        {
            std::cout << "The numbers are equal ";
            return first;
        }
        else
        {
            if (first > second)
                return first;
            else 
                return second;
        }
    }

    int strToInt(std::string);
};

template<> std::string Task_2<std::string>::Comp(std::string& first, std::string& second) 
{
        if (first.size() == second.size())
            if (strToInt(first) > strToInt(second))
                return first;
            else 
                return second;
        else
        {
            if (first.size() > second.size())
                return first;
            else 
                return second;
        }
};

template<> std::string Task_2<std::string>::Sum(std::string& first, std::string& second) 
{
        return first + second;
};
#endif

template <typename T>
inline int Task_2<T>::strToInt(std::string str)
{
    int res = 0;
    for (int i = 0; i < str.size(); i++)
    {
        res = res+str[i]*pow(10,str.length()-i);
    }
    return res;
}
