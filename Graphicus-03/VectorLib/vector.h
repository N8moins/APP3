#pragma once

/***
 * Fichier:  vector.h
 * Auteurs: Nathan Lessard et Gabriel Bruneau
 * Date: 09 janvier 2024
 * Description: Definition de la classe vector selon
 * les specifications de Graphicus.
 */

#ifndef VECTOR_H__
#define VECTOR_H__

#include <iostream>
#include <string>
#include <sstream>

template<class T>
class Vector {
public:
    Vector();
    ~Vector();

    T* Remove(int index);
    T* GetLast();
    void Clear();
    void Display(std::ostream& s);
    int Count() const;
    int Capacity() const;
    bool IsEmpty();
    bool Add(T* value);
    void SetActive(int index);
    T& GetActive();

    T& operator[] (int index);

    void operator++() {
        if (m_activatedItem < m_count - 1)
            m_activatedItem++;
    };

    void operator--() {
        if (m_activatedItem > 0)
            m_activatedItem--;
    };

    void operator+= (T item) {
        Add(&item);
    };

private:
    int m_initialSize = 2;
    int m_currentSize = m_initialSize;
    int m_count = 0;
    T** m_array;
    int m_activatedItem = 0;

    void Resize();
    T* Get(int index);
    Vector<int> Split(std::string input, char divider);
    
    // Déclarez les fonctions amies à l'intérieur de la classe
    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vector);

    template<class U>
    friend std::istream& operator>>(std::istream& is, Vector<U>& vector);
};

template<class T>
T& Vector<T>::operator[] (int index) {
    
        return *Get(index);
}

template<class T>
Vector<T>::Vector() {
    m_array = new T*[m_initialSize];
}

template<class T>
Vector<T>::~Vector() {
    Clear();
    delete[] m_array;
}

template<class T>
bool Vector<T>::Add(T* value) {
    try {
        if (m_count == m_currentSize)
            Resize();


        m_array[m_count] = new T(*value);
        m_count++;
    }
    catch (const std::exception& e) {
        return false;
    }
    return true;
}

template<class T>
void Vector<T>::SetActive(int index) {
    if (index < m_count)
        m_activatedItem = index;
}

template<class T>
T& Vector<T>::GetActive() {
    return *m_array[m_activatedItem];
}

template<class T>
T* Vector<T>::Get(int index) {
    if (index < 0 || index >= m_currentSize) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_array[index];
}

template<class T>
T* Vector<T>::GetLast() {
    return m_array[m_count - 1];
}

template<class T>
T* Vector<T>::Remove(int index) {
    if (index < 0 || index >= m_currentSize) {
        throw std::out_of_range("Index out of bounds");
    }

    T* deletedValue = m_array[index];
    for (int i = index; i < m_count - 1; i++) {
        m_array[i] = m_array[i + 1];
    }

    m_count--;
    return deletedValue;
}

template<class T>
void Vector<T>::Clear() {
    for (int i = 0; i < m_count; i++) {
        m_array[i] = nullptr;
    }
    m_count = 0;
}

template<class T>
int Vector<T>::Count() const {
    return m_count;
}

template<class T>
int Vector<T>::Capacity() const {
    return m_currentSize;
}

template<class T>
void Vector<T>::Resize() {
    m_currentSize *= 2;
    T** newArray = new T*[m_currentSize];

    for (int i = 0; i < m_count; i++) {
        newArray[i] = m_array[i];
    }

    delete[] m_array;
    m_array = newArray;
}

template<class T>
bool Vector<T>::IsEmpty() {
    return m_count == 0;
}

template<class T>
void Vector<T>::Display(std::ostream& s) {
    for (int i = 0; i < m_count; i++) {
        s << "[" << i << "] = " << m_array[i] << std::endl;
    }
}

template<class T>
Vector<int> Vector<T>::Split(std::string input, char divider) {
    Vector<int> values;
    size_t pos;
    while ((pos = input.find(divider)) != std::string::npos) {
        values += std::stoi(input.substr(0, pos));
        input = input.substr(pos + 1);
    }
    values += std::stoi(input);
    return values;
}
template<class T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
    for (int i = 0; i < vector.m_count; ++i) {
        os << vector.m_array[i] << "\n";
    }
    return os << std::endl;
}

template<class T>
std::istream& operator>>(std::istream& is, Vector<T>& vector) {
    std::stringstream ss;
    ss << is.rdbuf();
    std::string text = ss.str();
    Vector<std::string> values = vector.Split(text, 'L');
    for (int i = 0; i < values.Count(); i++){
        values[i] >> T;
        vector += T;
    }

    return is;
}

#endif
