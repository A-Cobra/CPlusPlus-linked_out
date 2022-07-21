#pragma once
#define t template<typename T>

t
class Empresa
{
private:
	T name;
	T country;
	T description;
	float rating;
	//REVIEW
	int sortRating;
public:
	//Constructors
	Empresa();
	~Empresa();
	Empresa(T name, T description, T country, float rating, int sortRating);

	//Setters
	void setNombre(T name);
	void setCountry(T country);
	void setDescription(T description);
	void setRating(float rating);
	void setSortRating(int rating);
	//void getEverything();

	//Getters
	T getName();
	T getCountry();
	T getDescripcion();
	float getRating();
	int getSortRating();
	//    void setDescripcion(string descripcion) { this->descripcion = descripcion; }
	//    Oficio* getOficio() { return oficio; }
	//    void setOficio(Oficio* oficio) { this->oficio = oficio; }




};


//Constructors
t
Empresa<T>::Empresa()
{
	name = "";
	country = "";
	description = "";
}

t
Empresa<T>::Empresa(T name, T description, T country, float rating, int sortRating)
{
	this->name = name;
	this->description = description;
	this->country = country;
	this->rating = rating;
	this->sortRating = sortRating;
}


t
Empresa<T>::~Empresa()
{

}



//Setters

t
void Empresa<T>::setNombre(T name)
{
	this->name = name;
}

t
void Empresa<T>::setCountry(T country)
{
	this->country = country;
}

t
void Empresa<T>::setDescription(T description)
{
	this->country = country;
}

t
void Empresa<T>::setRating(float rating)
{
	this->rating = rating;
}

t
void Empresa<T>::setSortRating(int sortRating)
{
	this->sortRating = sortRating;
}


//Getters

t
T Empresa<T>::getName()
{
	return name;
}

t
T Empresa<T>::getCountry()
{
	return country;
}

t
T Empresa<T>::getDescripcion()
{
	return description;
}

t
float Empresa<T>::getRating()
{
	return rating;
}

t
int Empresa<T>::getSortRating()
{
	return sortRating;
}

