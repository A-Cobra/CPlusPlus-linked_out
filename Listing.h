#pragma once
#include<iostream>
#include<algorithm>
using namespace std;
//listing clase que contiene los datos de una publicación
template <typename T>
class Listing
{
private:
	//Empresa* E1;
	T job;
	T category;
	T technologies;
	T description;
	int edadmin;
public:
	Listing();//Default constructor
	Listing(T job, T category, T technologies, T description, int edadmin);//Initialize components
	~Listing();//Destructor

	//Functionality
	//Setters
	void setJob(T job);
	void setCategory(T category);
	void setTechnologies(T technologies);
	void setDescription(T description);
	void setedadmin(int edadmin);
	//Getters
	T getJob();
	T getCategory();
	T getTechnologies();
	T getDescription();
	int getedadmin();
	//Others
	void printInfo();



};




template <typename T>
Listing<T>::Listing() {

}



template <typename T>
Listing<T>::Listing(T job, T category, T technologies, T description, int edadmin) {
	this->job = job;
	this->category = category;
	this->technologies = technologies;
	this->description = description;
	this->edadmin = edadmin;

}

template <typename T>
Listing<T>::~Listing() {

}

//Setting functions 

template <typename T>
void Listing<T>::setJob(T job) {
	this->job = job;
}

template <typename T>
void Listing<T>::setCategory(T category) {
	this->category = category;
}

template <typename T>
void Listing<T>::setTechnologies(T technologies) {
	this->technologies = technologies;
}

template <typename T>
void Listing<T>::setDescription(T description) {
	this->description = description;
}


template <typename T>
void Listing<T>:: setedadmin(int edadmin) {
	this->edadmin = edadmin;
}


//Getting functions

template <typename T>
T Listing<T>::getJob() {
	return job;
}

template <typename T>
T Listing<T>::getCategory() {
	return category;
}

template <typename T>
T Listing<T>::getTechnologies() {
	return technologies;
}

template <typename T>
T Listing<T>::getDescription() {
	return description;
}

template <typename T>
int Listing<T>::getedadmin() {
	return edadmin;
}

//Other functions

template <typename T>
void Listing<T>::printInfo() {
	//cout << "Nombre de la empresa: " << E1->getName();
	Console::ForegroundColor = ConsoleColor(9);
	cout << "Categoría del trabajo: ";
	Console::ForegroundColor = ConsoleColor(15);
	cout << endl << category << endl;

	Console::ForegroundColor = ConsoleColor(9);
	cout << "Nombre del Trabajo: ";
	Console::ForegroundColor = ConsoleColor(15);
	cout << endl << job << endl;

	Console::ForegroundColor = ConsoleColor(9);
	cout << "Tecnologías usadas: ";
	Console::ForegroundColor = ConsoleColor(15);
	cout << endl << technologies << endl;

	Console::ForegroundColor = ConsoleColor(9);
	cout << "Descripción: ";
	Console::ForegroundColor = ConsoleColor(15);
	cout << endl << description << endl;

	Console::ForegroundColor = ConsoleColor(9);
	cout << "Edad minima requerida: ";
	Console::ForegroundColor = ConsoleColor(15);
	cout << endl << edadmin << endl;

}