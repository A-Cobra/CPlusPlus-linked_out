#pragma once
#include<iostream>
using namespace std;

template<typename T>
class Node
{
private:
	T element;
	Node<T>* next;
	Node<T>* previous;
public:
	Node();
	Node(T element);
	~Node();

	//Setters and getters
	void setElement(T element);
	void setNext(Node<T>* next);
	void setPrevious(Node<T>* next);

	T getElement();
	Node<T>* getNext();
	Node<T>* getPrevious();
};

template<typename T>
Node<T>::Node() {
	//T nada = 0;
	//element = nada;
	next = nullptr;
}

template<typename T>
Node<T>::Node(T element) {
	this->element = element;
	next = nullptr;
}

template<typename T>
Node<T>::~Node() {

}

//Setters

template<typename T>
void Node<T>::setElement(T element) {
	this->element = element;
	next = nullptr;
}

template<typename T>
void Node<T>::setNext(Node<T>* next) {
	this->next = next;
}

template<typename T>
void Node<T>::setPrevious(Node<T>* previous) {
	this->previous = previous;
}

//Getters

template<typename T>
T Node<T>::getElement() {
	return element;
}

template<typename T>
Node<T>* Node<T>::getNext() {

	return next;
}

template<typename T>
Node<T>* Node<T>::getPrevious() {

	return previous;
}