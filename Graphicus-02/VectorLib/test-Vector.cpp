/***
 * Fichier:  test-Vector.cpp
 * Auteurs: Nathan Lessard et Gabriel Bruneau
 * Date: 09 janvier 2024
 * Description: tests pour la classe vector.h 
 */


#include "vector.h"
#include <iostream>

Vector<int>* array = new Vector<int>();


void TestAdd(){

    std::cout << "size: " << array->Count() << std::endl;
    int* value1 = new int(4);
    int* value2 = new int(5);
    for (int i = 0; i < 10; i++){
        array->Add(new int(i));
    }

    array->Display(std::cout);
    std::cout << "size: " << array->Count() << std::endl;
}

void TestRemove(){
    std::cout << "size: " << array->Count() << std::endl;

    array->Remove(1);

    array->Display(std::cout);
    std::cout << "size: " << array->Count() << std::endl;
}

void TestGet(){
    array->Display(std::cout);
    
    std::cout << *array->Get(1) << std::endl;
}

void TestClear(){
    array->Display(std::cout);

    array->Clear();

    array->Display(std::cout);
}

void TestIsEmpty(){
    std::cout << "Empty : " << array->IsEmpty() << std::endl;
}

void TestCount(){
    std::cout << "Count : " << array->Count() << std::endl;
}

void TestCapacity(){
    std::cout << "Capacity : " << array->Capacity() << std::endl;
}

int main(){
    std::cout << "--------------" << std::endl;
    TestCount();
    TestCapacity();
    TestAdd();
    TestCount();
    TestCapacity();
    TestRemove();
    TestCount();
    TestCapacity();
    TestGet();
    TestIsEmpty();
    TestCount();
    TestCapacity();
    TestClear();
    TestCount();
    TestCapacity();
    TestIsEmpty();
    std::cout << "--------------" << std::endl;
}