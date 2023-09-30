#ifndef TASK_0_TEMP
#define TASK_0_TEMP

class Task_0_temp
{
public:
    Task_0_temp(/* args */);
    ~Task_0_temp();
    template <typename T> T add(T& a, T& b)
    {
        return a + b;
    }

    template <typename T> T subtract(T& a, T& b)
    {
        return a - b;
    }

    template <typename T> T multiply(T& a, T& b)
    {
        return a * b;
    }

    template <typename T> T divide(T& a, T& b)
    {
        return a / b;
    }
};

Task_0_temp::Task_0_temp(/* args */)
{
}

Task_0_temp::~Task_0_temp()
{
}

#endif