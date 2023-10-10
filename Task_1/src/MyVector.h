#ifndef TASK_1
#define TASK_1
#include <iostream>

template <typename T>
class MyVector
{
    private:
    T* first;                                    // указатель на первый элекмент
    T* last;                                     // указатель на последний элемент
    
    void Allocate(std::size_t n)                 // выделение памяти
    {
        first = new T [n*sizeof(T)];   // выделение памяти
        last = first + n;              // опеределение указателя на последний элемент
    }
    
    void Destroy()                               // удаление вектора
    {
        for (T* p = first; p != last; ++p) p->~T();   // вызов декструктора для всех элементов вектора
        delete [] first;                              // освобождение памяти
    }

    public:
    explicit MyVector() : first(0), last(0) {}    // конструктор по умолчанию
    explicit MyVector(std::size_t n, const T& vec = T())
    {
        Allocate(n);
        for (std::size_t i = 0; i < n; i++)
        {
            *(first + i) = vec;
        }
    }

    MyVector(const MyVector&);                    // конструктор копирвоания
    MyVector& operator=(const MyVector&);         // оператор присваивания
    ~MyVector() 
    {
        Destroy();
        first = 0, last = 0;
    }

    std::size_t size() const;                     // размер вектора
    T* begin() const {return first;}              // указатель на первый элемент 
    T* end() const {return last;}                 // указатель на элемент, следующий за последним 
    
    T& operator[](std::size_t i);                 // индексирование
    void insert(T* pos, const T& elem);           // вставка элемента в заданную позицию 
    void push_back(const T& elem);                // вставка элемента в конец вектора 
    void pop_back();                              // удаление элемента из конца вектора
    void show() const;                            // вывод содержимого вектора  
};

// конструктор копирвоания
template <typename T>
inline MyVector<T>::MyVector(const MyVector& other)
{
    std::size_t n = other.size();
    Allocate(n);
    for (std::size_t i = 0 ; i < n; ++i)
    {
        *(first + i) = *(other.first + i);
    };
}

// оператор присваивания
template <typename T>
inline MyVector<T>& MyVector<T>::operator =(const MyVector& other)
{
    if (this == &other) return *this;
    Destroy();
    std::size_t n = other.Size();
    Allocate(n);

    for (std::size_t i = 0 ; i < n; ++i)
    {
        *(first + i) = *(other.first + i);
    };
    return *this;
}

// размер вектора
template <typename T>
inline std::size_t MyVector<T>::size() const
{
    return (0 == first ? 0 : last - first);
}

// индексирование
template <typename T>
inline T &MyVector<T>::operator[](std::size_t i)
{
    if (i < 0 || i > (size() - 1))
    {
        std::cout << "Incorrect index! " << std::endl;
    }
    else
    {
        return (*(first + i));
    };
}

// вставка элемента в заданную позицию
template <typename T>
inline void MyVector<T>::insert(T *pos, const T &elem)
{
    std::size_t n = size() + 1;             // новый размер
    T* new_first = new T [n * sizeof(T)];   
    T* new_last = new_first + n;

    std::size_t offset = pos - first; // смещение соответсвующее адресу pos
    for (std::size_t i = 0; i < offset; ++i) // копирование в новый вектор первой части
    {
        *(new_first + i) = *(first + i);
    };

    *(new_first + offset) = elem;


    for (std::size_t i = offset; i < n; ++i) // копирование второй части
    {
        *(new_first + i + 1) = *(first + i);
    }
    Destroy();
    first = new_first;
    last = new_last;
}

// вставка элемента в конец вектора
template <typename T>
inline void MyVector<T>::push_back(const T &elem)
{
    if (!size())   // если вектор пууст 
    {
        Allocate(1);
        *first = elem;
    }
    else
    {
        insert(end(), elem);
    }
}

// удаление элемента из конца вектора
template <typename T>
inline void MyVector<T>::pop_back()
{
    T* p = end() - 1; // указатель на последний элемент вектора 
    p->~T(); // удаляем элемент 
    last--; 
}

// вывод содержимого вектора
template <typename T>
inline void MyVector<T>::show() const
{
    std::size_t n = size();
    for (std::size_t i = 0 ; i < n; ++i)
    {
        std::cout << *(first + i) << " ";
    };
    std::cout << std::endl;
}

#endif