/**
* Smart Pointer for automatic deallocating when going out of scope.
* @author Huynh Hoang Kha
* @version 1.0 25/04/2019
*/

#pragma once
#ifndef _SMART_POINTER_H_
#define _SMART_POINTER_H_

template <class T>
class SmartPointer {
	T* pointer;
	int callStackIndex;
public:
	SmartPointer();
	SmartPointer(T* _pointer);
	SmartPointer(SmartPointer<T>& obj);
	~SmartPointer();
	bool operator==(T* _pointer);
	T* operator=(T* _pointer);
	T& operator*();
	operator T*();
	T* operator->();
};

template <class T>
SmartPointer<T>::SmartPointer() {
	this->pointer = NULL;
	this->callStackIndex = 0;
}

template <class T>
SmartPointer<T>::SmartPointer(T* _pointer) {
	this->pointer = _pointer;
	this->callStackIndex = 0;
}

template <class T>
SmartPointer<T>::~SmartPointer() {
	if (this->callStackIndex == 0 && this->pointer != NULL) {
		delete[] this->pointer;
		this->pointer = NULL;
	}
}

template <class T>
bool SmartPointer<T>::operator==(T* _pointer) {
	return (this->pointer == _pointer);
}

template <class T>
T* SmartPointer<T>::operator=(T* _pointer) {
	delete[] this->pointer;
	return this->pointer = _pointer;
}

template <class T>
SmartPointer<T>::SmartPointer(SmartPointer<T>& obj) {
	this->pointer = obj.pointer;
	this->callStackIndex = obj.callStackIndex + 1;
}

template <class T>
T& SmartPointer<T>::operator*() {
	return *(this->pointer);
}

template <class T>
T* SmartPointer<T>::operator->() {
	return this->pointer;
}

template <class T>
SmartPointer<T>::operator T*() {
	return this->pointer;
}

#endif // !_SMART_POINTER_H_