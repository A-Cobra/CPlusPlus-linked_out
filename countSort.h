#pragma once
#include<iostream>
#include"Profesional.h"
#include"Programa.h"

using namespace std;

template<typename T>

void countSort(Programa<T>** arrProfesional[], int size) {
    // The size of count must be at least the (max+1) but
    // we cannot assign declare it as int count(max+1) in C++ as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int output[10];
    int count[10];
    int max = array[0];

    // Find the largest element of the array
    for (int i = 1; i < size; i++) {
        if (arrProfesional[i]->getAge() > max)
            max = arrProfesional[i]->getAge();
    }

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[arrProfesional[i]->getAge()]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[arrProfesional[i]->getAge()] - 1] = array[i];
        count[arrProfesional[i]->getAge()]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) {
        arrProfesional[i]->getAge() = output[i];
    }
}

// Function to print an array
template <class T>
void printArray(Programa<T>** arrProfesional[], int size) {
    for (int i = 0; i < size; i++)
        cout << arrProfesional[i]->getAge() << " ";
    cout << endl;
}