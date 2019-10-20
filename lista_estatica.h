#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H
#include <iostream>
#include <stdexcept> //Permite lanzar excepciones

using namespace std;

//template: Indica que la clase es una plantilla (maneja cualquier tipo de dato)
//size_t: Entero sin signo, se utiliza para indicar tamaños de colecciones
//typename: Declara el tipo de dato T que puede ser cualquier tipo válido
template<size_t n, typename T>
class ListaEstatica
{
private:
    static const size_t CAPACITY = 1000;
    T elements[CAPACITY];
    size_t index;
    size_t containerSize;
public:
    ListaEstatica()
    {
        if (n > CAPACITY)
            throw invalid_argument("Trying to create a list with non valid size");
        index = 0;
        containerSize = n;
    }

    bool empty() const;
    bool full() const;
    size_t size() const;
    void push_front(const T& element);
    void push_back(const T& element);
    const T& front() const;
    const T& back() const;
    void pop_front();
    void pop_back();
    void insert(size_t position, const T& element);
    void erase(size_t position);
    T& operator[](size_t position);
    void clear();
    void remove(const T& value);
};

template<size_t n, typename T>
bool ListaEstatica<n, T>::empty() const
{
    return index == 0;
}

template<size_t n, typename T>
bool ListaEstatica<n, T>::full() const
{
    return index == containerSize;
}

template<size_t n, typename T>
size_t ListaEstatica<n, T>::size() const
{
    return index;
}

template<size_t n, typename T>
void ListaEstatica<n, T>::push_front(const T &element)
{
    if (full())
        throw range_error("Trying push_front(const T& element) on a full list");
    if (empty())
        elements[0] = element;
    else
    {
        for (size_t i(index); i > 0; --i)
            elements[i] = elements[i-1];
        elements[0] = element;
    }
    ++index;
}

template<size_t n, typename T>
void ListaEstatica<n, T>::push_back(const T &element)
{
    if (full())
        throw range_error("Trying push_back(const T& element) on a full list");
    elements[index] = element;
    ++index;
}

template<size_t n, typename T>
const T& ListaEstatica<n, T>::front() const
{
    if (empty())
        throw range_error("Trying front() on empty list");
    return elements[0];
}

template<size_t n, typename T>
const T& ListaEstatica<n, T>::back() const
{
    if (empty())
        throw range_error("Trying back() on empty list");
    return elements[index-1];
}

template<size_t n, typename T>
void ListaEstatica<n, T>::pop_front()
{
    if (empty())
        throw range_error("Trying pop_front() on empty list");
    for (size_t i(0); i < index-1; ++i)
        elements[i] = elements[i+1];
    --index;
}

template<size_t n, typename T>
void ListaEstatica<n, T>::pop_back()
{
    if (empty())
        throw range_error("Trying pop_back() on empty list");
    --index;
}

template<size_t n, typename T>
void ListaEstatica<n, T>::insert(size_t position, const T &element)
{
    if (full())
        throw range_error("Trying insert(size_t position, const T &element) on full list");
    if (position > index)
        throw range_error("Trying insert(size_t position, const T &element) in non valid position");
    if (position == 0)
        push_front(element);
    else if (position == size())
        push_back(element);
    else
    {
        for (size_t i(index); i > position; --i)
            elements[i] = elements[i-1];
        elements[position] = element;
        ++index;
    }
}

template<size_t n, typename T>
void ListaEstatica<n, T>::erase(size_t position)
{
    if (empty())
        throw range_error("Trying erase(size_t position) on empty list");
    if (position >= index)
        throw range_error("Trying erase(size_t position) on non valid position");
    if (position == 0)
        pop_front();
    else if (position == index-1)
        pop_back();
    else
    {
        for (size_t i(position); i < index-1; ++i)
            elements[i] = elements[i+1];
        --index;
    }
}

template<size_t n, typename T>
T& ListaEstatica<n, T>::operator [](size_t position)
{
    if (empty())
        throw range_error("Trying [] on empty list");
    if (position >= index)
        throw range_error("Trying [] on non valid position");
    return elements[position];
}

template<size_t n, typename T>
void ListaEstatica<n, T>::clear()
{
    index = 0;
}

template<size_t n, typename T>
void ListaEstatica<n, T>::remove(const T &value)
{
    if (empty())
        throw range_error("Trying remove(const T &value) on empty list");
    size_t i = 0;
    while (i < index)
    {
        if (elements[i] == value)
        {
            erase(i);
            --i;
        }
        ++i;
    }
}

#endif // LISTA_ESTATICA_H
