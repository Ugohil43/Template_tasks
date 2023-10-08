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
    MyVector(const std::size_t size, const T& value);
    ~MyVector();

    void push_back(const T& value);                         // добавить элемент в конец вектора
    void pop_back();                                        // удалить элемент с конеца вектора
    void insert(const std::size_t& index, const T& value);  // вставка значения по индексу 
    //void reserve(const std::size_t& size);

    inline std::size_t length() const;

    T& operator[](const std::size_t& index) const;          // перегрузка оператора индексирвоания
    MyVector<T> operator=(const MyVector<T>& v);            // перегрузка оператора присваивания   
    MyVector<T> operator=(MyVector<T>&& v);                 // перегрузка оператора присваивания с помощью универсальной ссылки

    template<typename T1>
    friend std::ostream& operator<<(std::ostream& out, const MyVector<T1>& v);
};

template <typename T>
inline MyVector<T>::MyVector()
{
    this->size = 0;
    this->count = 1;
    arr = new T[1];
     for (std::size_t i = 0; i < size; i++) 
    {
      this->arr[i] = NULL;     // заполняем
    }
}

template <typename T>
inline MyVector<T>::MyVector(const std::size_t size, const T& value)
{
    this->size = size;
    this->count = size;
    arr = new T[size];          // выделяем память
    for (std::size_t i = 0; i < size; i++) 
    {
      this->arr[i] = value;     // заполняем
    }
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
    /*
    if(count == size)
    {
        reserve(size);
    }
    arr[count++] = value;
    */
    if (this->size == this->count)          // если массив заполнен
    {        
      this->count *= 2;                     // увеличиваем его в 2 раза
      T* new_arr = new T[this->count];      // создаем новый массив
      for (std::size_t i = 0; i < this->size; i++) 
      {
        new_arr[i] = this->arr[i];          // копируем данные
      }
      delete[] this->arr;                   // удаляем старый массив
      this->arr = new_arr;                  // меняем указатель
    }
    this->arr[this->size] = value;          // добавляем элемент
    this->size++;                           // увеличиваем размер
}

template <typename T>
inline void MyVector<T>::pop_back()
{
    if(!this->size)
    {
        return; 
    }
    this->size--;
}

template <typename T>
inline void MyVector<T>::insert(const std::size_t& index, const T& value)
{
    /*
    if(index >= count || index < 0)
    {
        throw "Incorrect index!";
    }
    
    if(count == size)
    {
        //reserve(size);
        size*2;
    }
    
    for(std::size_t i = count - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[index] = value;
    count++;
    */
    if (index >= this->size)                             // если индекс больше размера массива
    {                              
      throw std::out_of_range("Incorrect index!");      // бросаем исключение
    }
    if (this->size == this->count)                      // если массив заполнен
    {  
      this->count *= 2;                                 // увеличиваем его в 2 раза
      T* new_arr = new T[this->count];                  // создаем новый массив
      for (std::size_t j = 0; j < this->size; j++) 
      {
        new_arr[j] = this->arr[j];                       // копируем данные
      }
      delete[] this->arr;                               // удаляем старый массив
      this->arr = new_arr;                              // меняем указатель
    }
    for (std::size_t j = this->size; j > index; j--) 
    {
      this->arr[j] = this->arr[j - 1];                  // сдвигаем элементы
    }
    this->arr[index] = value;                            // вставляем элемент
    this->size++;                                       // увеличиваем размер массива
}

/*
template <typename T>
inline void MyVector<T>::reserve(const std::size_t& size)
{
    if(size <= 0)
    {
        return;
    }
    std::cout << "Size: " << this->size << std::endl;
    this->size = size*2;
    std::cout << "Size: " << this->size << std::endl;
    std::cout << "sizeof(T): " << sizeof(T) << std::endl;
    T *new_arr = new T[size];
    std::cout << "sizeof(T): " << sizeof(T) << std::endl;
    memmove(new_arr, arr, sizeof(T) * count);
    
    delete arr;
    arr = new_arr;
}
*/

template <typename T>
inline std::size_t MyVector<T>::length() const
{
     return size;
}

template <typename T>
inline T &MyVector<T>::operator[](const std::size_t& index) const
{
    if(index >= count)
    {
        throw "Index out of range!";
    }
    
    return this->arr[index];
}

template <typename T>
inline MyVector<T> MyVector<T>::operator=(const MyVector<T>& v)
{
    if(this == &v)          // проверка на самокопирование
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
    if(this == &v)          // проверка на самокопирование
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
inline std::ostream &operator<<(std::ostream& out, const MyVector<T1>& v)
{
    for(std::size_t i = 0; i < v.size; i++)
    {
        out << v[i] << " ";
    }
    
    return out;
}

#endif