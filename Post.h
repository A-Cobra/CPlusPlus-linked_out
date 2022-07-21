#pragma once
#define t template<typename T>

t
class Post
{
private:
	//TO ADD IN BST
	T primaryKey;
	//AD IT IN EMPRESA
	T title;
	T subject;
	T description;
	
public:
	//Constructors
	Post();
	~Post();
	Post(T title, T subject, T description);

	//Setters
	void setTitle(T title);
	void setSubject(T subject);
	void setDescription(T description);


	//Getters
	T getTitle();
	T getSubject();
	T getDescription();
	//    void setDescripcion(string descripcion) { this->descripcion = descripcion; }
	//    Oficio* getOficio() { return oficio; }
	//    void setOficio(Oficio* oficio) { this->oficio = oficio; }




};


//Constructors
t
Post<T>::Post()
{
	title = "";
	subject = "";
	description = "";
}

t
Post<T>::Post(T title, T subject, T description)
{
	this->title = title;
	this->subject = subject;
	this->description = description;
}


t
Post<T>::~Post()
{

}



//Setters

t
void Post<T>::setTitle(T title)
{
	this->title = title;
}

t
void Post<T>::setSubject(T subject)
{
	this->subject = subject;
}

t
void Post<T>::setDescription(T description)
{
	this->country = country;
}



//Getters

t
T Post<T>::getTitle()
{
	return title;
}

t
T Post<T>::getSubject()
{
	return subject;
}

t
T Post<T>::getDescription()
{
	return description;
}
