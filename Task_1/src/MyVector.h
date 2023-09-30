#ifndef TASK_1
#define TASK_1
#include <iostream>

template <typename T>
class MyVector
{
private:
    std::size_t size;
    std::size_t count; 
    T *arr;             
public:
    MyVector();
    MyVector(const std::size_t size);
    ~MyVector();

    void push_back(const T& value);
    void pop_back();
    void insert(const std::size_t& index, const T& value);
    void reserve(const std::size_t& size);

    inline std::size_t length() const;

    T& operator[](const std::size_t& index) const;
    MyVector<T> operator=(const MyVector<T>& v);
    MyVector<T> operator=(MyVector<T>&& v);

    template<typename T1>
    friend std::ostream& operator<<(std::ostream& out, const MyVector<T1>& v);
};

template <typename T>
inline MyVector<T>::MyVector()
{
    this->size = 0;
    this->count = 0;
    arr = new T[size];
}

template <typename T>
inline MyVector<T>::MyVector(const std::size_t size)
{
    this->size = size;
    this->count = 0;
    arr = new T[size];
}

template <typename T>
inline MyVector<T>::~MyVector()
{
    delete[] arr;
    arr = nullptr;
}

template <typename T>
inline void MyVector<T>::push_back(const T& value)
{
    if(count == size)
    {
        reserve(size);
    }
    arr[count++] = value;
}

template <typename T>
inline void MyVector<T>::pop_back()
{
    if(!count)
    {
        return; 
    }
    count--;
}

template <typename T>
inline void MyVector<T>::insert(const std::size_t& index, const T& value)
{
    if(index >= count || index < 0)
    {
        throw "Incorrect index!";
    }
    
    if(count == size)
    {
        reserve(size);
    }
    
    for(std::size_t i = count - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[index] = value;
    count++;
}

template <typename T>
inline void MyVector<T>::reserve(const std::size_t& size)
{
    if(size <= 0)
    {
        return;
    }
    
    this->size = size;
    T *new_arr = new T[size];
    
    memmove(new_arr, arr, sizeof(T) * count);
    
    delete arr;
    arr = new_arr;
}

template <typename T>
inline std::size_t MyVector<T>::length() const
{
     return count;
}

template <typename T>
inline T &MyVector<T>::operator[](const std::size_t& index) const
{
    if(index >= count)
    {
        throw "Index out of range!";
    }
    
    return arr[index];
}

template <typename T>
inline MyVector<T> MyVector<T>::operator=(const MyVector<T>& v)
{
    if(this == &v)
    {
        return *this;
    }
    
    size  = v.size;
    count = v.count;
    
    delete[] arr;
    arr = new T[size];
    memmove(arr, v.arr, count * sizeof(T));
    
    return *this;
}

template <typename T>
inline MyVector<T> MyVector<T>::operator=(MyVector<T>&& v)
{
    if(this == &v)
    {
        return *this;
    }
    
    size  = v.size;
    count = v.count;
    arr   = v.arr;
    
    v.arr = nullptr;
    
    return *this;
}

template <typename T1>
inline std::ostream &operator<<(std::ostream &out, const MyVector<T1> &v)
{
    for(std::size_t i = 0; i < v.length(); i++)
    {
        out << v[i] << " ";
    }
    
    return out;
}

#endif