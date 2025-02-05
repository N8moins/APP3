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
#include "../couche.h"
#include "../Formes/rectangle.h"
#include "../Formes/cercle.h"
#include "../Formes/carre.h"

template<class T>
class Vector {
public:
    Vector();
    ~Vector();

    T Remove(int index);
    T& GetLast();
    void Clear();
    void Display(std::ostream& s);
    int Count() const;
    int Capacity() const;
    bool IsEmpty();
    bool Add(T value);

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
        Add(item);
    };

private:
    int m_initialSize = 2;
    int m_currentSize = m_initialSize;
    int m_count = 0;
    T* m_array;
    int m_activatedItem = 0;

    void Resize();
    T& Get(int index);
    Vector<int> Split(std::string input, char divider);

    // Déclarez les fonctions amies à l'intérieur de la classe
    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vector);

    template<class U>
    friend std::istream& operator>>(std::istream& is, Vector<U>& vector);
};

template<class T>
T& Vector<T>::operator[] (int index) {
    return Get(index);
}

template<class T>
Vector<T>::Vector() {
    m_array = new T[m_initialSize];
}

template<class T>
Vector<T>::~Vector() {
    Clear();
    delete[] m_array;
}

template<class T>
bool Vector<T>::Add(T value) {
    try {
        if (m_count == m_currentSize)
            Resize();

        m_array[m_count] = value;
        m_count++;
    }
    catch (const std::exception& e) {
        return false;
    }
    return true;
}

template<class T>
T& Vector<T>::Get(int index) {
    if (index < 0 || index >= m_currentSize) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_array[index];
}

template<class T>
T& Vector<T>::GetLast() {
    return m_array[m_count - 1];
}

template<class T>
T Vector<T>::Remove(int index) {
    if (index < 0 || index >= m_currentSize) {
        throw std::out_of_range("Index out of bounds");
    }

    T deletedValue = m_array[index];
    for (int i = index; i < m_count - 1; i++) {
        m_array[i] = m_array[i + 1];
    }

    m_count--;
    return deletedValue;
}

template<class T>
void Vector<T>::Clear() {
    for (int i = 0; i < m_count; i++) {
        m_array[i] = NULL;
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
    T* newArray = new T[m_currentSize];

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
    std::string line;
    while (std::getline(is, line)) {
        if (line.find('L') != std::string::npos) {
            Couche layer;
            if (line.find('a') != std::string::npos)
                layer.changerEtat(Couche::Etat::actif);
            else if (line.find('i') != std::string::npos)
                layer.changerEtat(Couche::Etat::Initialise);
            else if (line.find('x') != std::string::npos)
                layer.changerEtat(Couche::Etat::desactive);

            vector.Add(layer);
        }
        else if (line.find('K') != std::string::npos) {
            Couche layer = vector.GetLast();
            Vector<int> values = vector.Split(line, ' ');
            int x = values[0];
            int y = values[1];
            int c = values[2];

            Carre square(x, y, c);
            layer.ajouterForme(square);
        }
        else if (line.find('R') != std::string::npos) {
            Couche layer = vector.GetLast();
            Vector<int> values = vector.Split(line, ' ');
            int x = values[0];
            int y = values[1];
            int l = values[2];
            int h = values[3];

            Rectangle rect(x, y, l, h);
            layer.ajouterForme(rect);
        }
        else if (line.find('C') != std::string::npos) {
            Couche layer = vector.GetLast();
            Vector<int> values = vector.Split(line, ' ');
            int x = values[0];
            int y = values[1];
            int r = values[2];

            Cercle circle(x, y, r);
            layer.ajouterForme(circle);
        }
    }
    return is;
}

#endif
