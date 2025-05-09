// #ifndef ARRAY_H
// #define ARRAY_H

// #include <iostream>


// #include <cstdlib>
// #include "defs.h"



// //convert the Array to template class
// template <typename T>

// class Array {

// 	public:
// 		//constructor
// 		Array();
				
// 		//destructor
// 		~Array();
		
// 		//other
// 		Array& operator+=(const T& element);
// 		Array& operator-=(const T& element);
// 		//const and not const function
// 		T& operator[] (int index);
// 		const T& operator[] (int index) const;

// 		int getSize() const;
// 		bool isFull() const;


	
	
// 	private:
// 		int numElements;
// 		T* elements;
	
// };
// template <typename T>
// Array<T>::Array() : elements(new T[MAX_ARR]), numElements(0) {}

// template <typename T>
// Array<T>::~Array(){
// 	delete[] elements;
// }

// template <typename T>
// Array<T>& Array<T>::operator+=(const T& element) {
//     if (numElements >= MAX_ARR) return *this;

//     elements[numElements++] = element;
//     return *this;
// }

// template <typename T>
// Array<T>& Array<T>::operator-=(const T& element){
// 	int index = 0;
// 	while(index < numElements){
// 		if(elements[index] == element){
// 			numElements--;
// 			break;
// 		}
// 		index++;
// 	}
// 	while(index < numElements){

// 		elements[index] = elements[index + 1];
//         ++index;
// 	}
// 	return *this;
// }

// template <typename T>
// T& Array<T>::operator[](int index) {
//     if (index < 0 || index >= numElements) {
//         std::cerr << "Array index out of bounds" << std::endl;
//         exit(1);
//     }
//     return elements[index];
// }

// template <typename T>
// T& Array<T> ::operator[](int index){

// 	if(index < 0 || index >= numElements){
// 		std::cerr << "Array index out of bounds" << std::endl;
//         exit(1);
// 	}
// 	return elements[index];

// }
// template <typename T>
// int Array<T>::getSize() const{
// 	return numElements;
// }
// template <typename T>
// bool Array<T>::isFull() const {
// 	return numElements >= MAX_ARR;
// }

// #endif
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
#include "defs.h"

template <typename T>
class Array {
public:
    Array();
    ~Array();
	void clear();
    Array& operator+=(const T& element);
    Array& operator-=(const T& element);
    T& operator[](int index);
    const T& operator[](int index) const;
    int getSize() const;
    bool isFull() const;

private:
    int numElements;
    T* elements;
};

template <typename T>
Array<T>::Array() : elements(new T[MAX_ARR]), numElements(0) {}

template <typename T>
Array<T>::~Array() {
	
    delete[] elements;
}

template <typename T>
void Array<T>::clear() { numElements = 0; }

template <typename T>
Array<T>& Array<T>::operator+=(const T& element) {
    if (numElements >= MAX_ARR) return *this;
    elements[numElements++] = element;
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator-=(const T& element) {
    int index = 0;
    while (index < numElements) {
        if (elements[index] == element) {
            numElements--;
            break;
        }
        index++;
    }

    while (index < numElements) {
        elements[index] = elements[index + 1];
        index++;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index) {

    if (index < 0 || index >= numElements) {
        std::cerr << "Array index out of bounds" << std::endl;
        exit(1);
    }
    return elements[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {

    if (index < 0 || index >= numElements) {
        std::cerr << "Array index out of bounds" << std::endl;
        exit(1);
    }
    return elements[index];

}

template <typename T>
int Array<T>::getSize() const {

    return numElements;
}

template <typename T>
bool Array<T>::isFull() const {

    return numElements >= MAX_ARR;
}

#endif