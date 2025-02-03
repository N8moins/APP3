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

template<class T>

class Vector{
public:
    Vector();
    ~Vector();

    bool Add(T* value);
    T* Remove(int  index);
    void Clear();
    void Display(std::ostream &s);
    T* Get(int index);
    int Count() const;
    int Capacity() const;
    bool IsEmpty();

private:
    int m_initialSize = 2;
    int m_currentSize = m_initialSize;
    int m_count = 0;
    T** m_array;

    void Resize();
};

template<class T>
Vector<T>::Vector(){
    m_array = new T*[m_initialSize];
}

template<class T>
Vector<T>::~Vector(){
    Clear();
    delete[] m_array;
}

template<class T>
bool Vector<T>::Add(T* value){
    try{
        if(m_count == m_currentSize)
            Resize();
    
        m_array[m_count] = value;
        m_count++;
    } catch(const std::exception& e){
        return false;
    }
    return true;
}

template<class T>
T* Vector<T>::Get(int index){
    try{
        return m_array[index];
    } catch(const std::exception& e){
        return nullptr;
    }

}

template<class T>
T* Vector<T>::Remove(int index){
    try{   
        T* deletedValue = m_array[index];
        for (int i = index; i < m_count - 1; i++){
            m_array[i] = m_array[i + 1];
        }
    
        m_count--;
        return deletedValue;
    }
    catch(const std::exception& e){
        return nullptr;
    }
}

template<class T>
void Vector<T>::Clear(){
    for (int i = 0; i < m_count; i++){
        delete m_array[i];
    }
    m_count = 0;
}

template<class T>
int Vector<T>::Count() const{
    return m_count;
}

template<class T>
int Vector<T>::Capacity() const{
    return m_currentSize;
}

template<class T>
void Vector<T>::Resize(){
    m_currentSize *= 2;
    T** newArray = new T*[m_currentSize];

    for (int i = 0; i < m_count; i++){
        newArray[i] = m_array[i];
    }

    delete[] m_array;
    m_array = newArray;
}

template<class T>
bool Vector<T>::IsEmpty(){
    return m_count == 0;
}

template<class T>
void Vector<T>::Display(std::ostream &s){
    for (int i = 0; i < m_count; i++){
        s << "[" << i << "] = " << *m_array[i] << std::endl;
    }
}
#endif