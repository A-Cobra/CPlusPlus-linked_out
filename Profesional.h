#pragma once
#include <iostream>
using namespace std;


template<typename T>
class Profesional {
private:
	T name;
	T email;
	T number_phone;
	T university;
	T age;
public:
	Profesional(T name, T email, T number_phone, T university, T age);
	Profesional();
	~Profesional();

	void setName(T name);
	void setEmail(T email);
	void setNumber_phone(T number_phone);
	void setUniversity(T university);
	void setAge(T age);
	T getName();
	T getEmail();
	T getNumber_phone();
	T getUniversity();
	T getAge();

};


//implementar contructor
template<typename T>
Profesional<T>::Profesional(T name, T email, T number_phone, T university, T age) {
	this->name = name;
	this->email = email;
	this->number_phone = number_phone;
	this->university = university;
	this->age = age;
}

template<typename T>
Profesional<T>::Profesional() {
	this->name = "";
	this->email = "";
	this->number_phone = "";
	this->university = "";
	this->age = "";
}

//implementar destructor 
template<typename T>
Profesional<T>::~Profesional() {

}

//set
template<typename T>
void Profesional<T>::setName(T name) {
	this->name = name;
}

template<typename T>
void Profesional<T>::setEmail(T email) {
	this->email = email;
}

template<typename T>
void Profesional<T>::setNumber_phone(T number_phone) {
	this->number_phone = number_phone;
}

template<typename T>
void Profesional<T>::setUniversity(T university) {
	this->university = university;
}

template<typename T>
void Profesional<T>::setAge(T age) {
	this->age = age;
}

//get

template<typename T>
T Profesional<T>::getName() {
	return name;
}

template<typename T>
T Profesional<T>::getEmail() {
	return email;
}

template<typename T>
T Profesional<T>::getNumber_phone() {
	return number_phone;
}

template<typename T>
T Profesional<T>::getUniversity() {
	return university;
}

template<typename T>
T Profesional<T>::getAge() {
	return age;
}