#pragma once

#include<vector>
#include<typeinfo>
#include<string>
#include<fstream>
#include "Profesional.h"
#include "Listing.h"
#include "LinkedList.h"
#include "Empresa.h"
#include "Node.h"
#include "Post.h"
#include "Hash.h"
//TESTING
#include "radixSort.h"
//TESTING
#define C (char)219 //Code for Solid Block
#define S (char)32 //Code for space

using namespace std;


template<typename T>
class Programa {
private:
	//Profesionales
	Profesional<T>** arrProfesional;
	int number;

	//Para Publicaciones
	int numberlisting;
	Listing<T>** arrPublicaciones;

	//Para empresas
	LinkedList<Empresa<T>>* empresas;
	Node<Empresa<T>>* headCopy;
		//Para quicksort de Empresas
	Node<Empresa<T>>* aux1Empresa;
	Node<Empresa<T>>* aux2Empresa;
	Node<Empresa<T>>* aux3Empresa;
	Node<Empresa<T>>* firstElementPrevious;
	Node<Empresa<T>>* secondElementPrevious;

	//Para Posts
	LinkedList<Post<T>>* posts;
	Node<Post<T>>* headCopyPost;

	//Para hashing
	//int hashFunc1(string myWord, int number);
	//Sirve
	//int(*hashFunction)(string, int);
	Hashtable<string, Profesional<T>*>* hashTabla;
	

	//TESTING
	RadixSort<T>* radixMachine;
	//TESTING


public:
	Programa();
	~Programa();
	//metodos
	void agregarProfesional(Profesional<T>* objProfesional);
	void createProfesional();
	void ordenarEdades();
	void ordenaredadmin();

	int findMax(int arr[], int a);
	void bucketSort(int arr[], Listing <T>** bucket[], int a);


	//Profesional
	void eliminarProfesinal(Profesional<T>* objProfesional);
	T obtenerProfesional(int indice);
	void listarProfesional();
	void loadProfesional();
	void searchProfesional();

	//publicaciones
	void agregarListing(Listing<T>* objListing);
	void createListing();
	void eliminarListing(Listing<T>* objListing);
	T obtenerListing(int indice);
	void listarListing();
	void DesordenarListing();
	void loadListing();


	//Empresas
	void sortBusiness();
	void listEmpresa();
	void swap(int index1, int index2);
	void createEmpresa();
	void loadEmpresa();
	//void partition();

	//Posts
	void createPost();
	void listPost();
	void loadPost();



	
	//Generales
	void loadComponents();//Carga todos los registros
	void saveFile();
	void saveGeneralFiles();
	
};

//implementación 
template <typename T>
Programa<T>::Programa() {
	arrProfesional = nullptr;
	number = 0;

	//Publicaciones
	numberlisting = 0;
	arrPublicaciones = nullptr;

	//Empresas
	//Separar memoria
	empresas = new LinkedList<Empresa<T>>();
	

	//Posts
	posts = new LinkedList<Post<T>>();

	//Para Hashing
	//Sirve lo siguiente
	hashTabla = new Hashtable<string, Profesional<T>*>(100);

	//Load Components();
	loadComponents();

	//TRIALS
	
	//_getch();
	//_getch();
	//TRIALS

}

template<typename T>
Programa<T>::~Programa() {

};


template<typename T>
void Programa<T>::agregarProfesional(Profesional<T>* objProfesional) {
	
	//arreglo temporal
	Profesional<T>** arrTemporal = new Profesional<T> * [number + 1];
	//copiar el contenido del arreglo ori al temp
	for (int i = 0; i < number; i++) {
		arrTemporal[i] = arrProfesional[i];
	}
	//agrega al final
	arrTemporal[number] = objProfesional;
	//aumenta el tamaño del arreglo
	number = number + 1;
	//borra contenido del arreglo ori
	if (arrProfesional != nullptr) delete[] arrProfesional;
	arrProfesional = arrTemporal; //actualiza
	//cout << "Profesional agregado de manera satisfactoria" << endl;
	// 
	// 
	// 
	//TESTING
	//hashTabla->trial();
	hashTabla->insertar(objProfesional->getName(), objProfesional);
	//TESTING
	// 
	// 
	// 
	// 
	//system("pause");
}


template<typename T>
void Programa<T>::createProfesional() {
	Profesional<T>* auxProfesional;
	T name;
	T email;
	T number_phone;
	T university;
	T age;
	//system("cls");
	cin.ignore();//So that the next getline doesn't take the nextline or \n
	cout << "Ingrese el nombre del profesional" << endl;
	//cin >> name;
	std::getline(cin, name);
	cout << "Ingrese el e-mail del profesional" << endl;
	//cin >> email;
	std::getline(cin, email);
	cout << "Ingrese el numero de telefono del profesional" << endl;
	//cin >> number_phone;
	std::getline(cin, number_phone);
	cout << "Ingrese la universidad de procedencia del profesional" << endl;
	//cin >> university;
	std::getline(cin, university);
	cout << "Ingrese la edad del profesional" << endl;
	//cin >> university;
	std::getline(cin, age);
	auxProfesional = new Profesional<string>(name, email, number_phone, university, age);
	agregarProfesional(auxProfesional);
}



template<typename T>
void Programa<T>::listarProfesional() {
	if (arrProfesional != nullptr) {
		//mostrar contactos
		for (int i = 0; i < number; i++) {
			Console::ForegroundColor = ConsoleColor(2);
			cout << "\nProfesional nro " << i + 1 << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << string(5, S) << "\nNombre: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << arrProfesional[i]->getName() << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << string(5, S) << "\nCorreo: "; 
			Console::ForegroundColor = ConsoleColor(15);
			cout << arrProfesional[i]->getEmail() << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << string(5, S) << "\nCelular: "; 
			Console::ForegroundColor = ConsoleColor(15);
			cout << arrProfesional[i]->getNumber_phone() << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << string(5, S) << "\nUniversidad: "; 
			Console::ForegroundColor = ConsoleColor(15);
			cout << arrProfesional[i]->getUniversity() << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << string(5, S) << "\nEdad: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << arrProfesional[i]->getAge() << endl << endl;
		}
	}
	else {
		cout << "\nNo hay algun usuario registrado!!!\n";
	}
}


template<typename T>
T Programa<T>::obtenerProfesional(int indice) {
	return arrProfesional[indice];
}


template<typename T>
void Programa<T>::ordenarEdades() {



	for (int i = 0; i < number - 1; i++) {
		for (int k = i + 1; k < number; k++) {
			if (arrProfesional[i]->getAge() > arrProfesional[k]->getAge()) {
				Profesional <T>* aux = arrProfesional[i];
				arrProfesional[i] = arrProfesional[k];
				arrProfesional[k] = aux;
			}
		}
	}



}



template<typename T>
int Programa<T>::findMax(int arr[], int a)
{
	int i;
	int max = arrPublicaciones[0]->getedadmin();
	int cnt = 0;
	for (i = 1; i < numberlisting; i++)
	{
		if (arrPublicaciones[i]->getedadmin() > max)
			max = arrPublicaciones[i]->getedadmin();
	}
	while (max > 0)
	{
		cnt++;
		max = max / 10;
	}

	return cnt;
}

template<typename T>
void Programa<T>::bucketSort(int arr[], Listing <T>** bucket[], int a)
{
	//cout << "Longitud de listing " << numberlisting << endl;
	static int i, j[10], k, l, d = 1;
	int c;
	c = findMax(arr, a);

	for (int m = 0; m < c; m++)
	{
		for (i = 0; i < 10; i++)
			j[i] = 0;


		for (i = 0; i < a; i++)
		{
			k = (arrPublicaciones[i]->getedadmin() / d) % 10;

			
			bucket[k][j[k]] = arrPublicaciones[i];
			j[k]++;
		}



		l = 0;
		for (i = 0; i < 10; i++)
		{
			for (k = 0; k < j[i]; k++)
			{
				arrPublicaciones[l] = bucket[i][k];
				l++;
			}
		}
		d *= 10;
	}
}

template<typename T>
void Programa<T>::ordenaredadmin() {

	int a, * arr, i;
	Listing <T>** bucket[10];
	//cout << "Enter no of element : ";
	//cin >> a;
	/*arr = new int[a + 1];*/
	for (i = 0; i < 10; i++)
		bucket[i] = new Listing <T>*[numberlisting];
	//cout << "Enter array element : ";
	//for (i = 0; i < a; i++)
	//	cin >> arr[i];
	bucketSort(arr, bucket, numberlisting);



}




template<typename T>
void Programa<T>::searchProfesional() {


	//template<typename value>
	Profesional<T>* found;

	//bool found;
	string name;
	cout << "Ingrese el nombre completo y exacto del usuario" << endl;
	cin.ignore();
	std::getline(cin, name);
	found = hashTabla->find(name);
	//found = hashTabla->find(name);
	if (found!=nullptr) {
		Console::ForegroundColor = ConsoleColor(3);
		cout << endl << endl << "Usuario encontrado" << endl;
		Console::ForegroundColor = ConsoleColor(15);
		cout << endl << "Datos del usuario:" << endl << endl;

		Console::ForegroundColor = ConsoleColor(4);
		cout << string(5, S) << "\nNombre: ";
		Console::ForegroundColor = ConsoleColor(15);
		cout << found->getName() << endl;
		Console::ForegroundColor = ConsoleColor(4);
		cout << string(5, S) << "\nCorreo: ";
		Console::ForegroundColor = ConsoleColor(15);
		cout << found->getEmail() << endl;
		Console::ForegroundColor = ConsoleColor(4);
		cout << string(5, S) << "\nCelular: ";
		Console::ForegroundColor = ConsoleColor(15);
		cout << found->getNumber_phone() << endl;
		Console::ForegroundColor = ConsoleColor(4);
		cout << string(5, S) << "\nUniversidad: ";
		Console::ForegroundColor = ConsoleColor(15);
		cout << found->getUniversity() << endl;
		Console::ForegroundColor = ConsoleColor(4);
		cout << string(5, S) << "\nEdad: ";
		Console::ForegroundColor = ConsoleColor(15);
		cout << found->getAge() << endl << endl;


	}
	else {
		Console::ForegroundColor = ConsoleColor(4);
		cout << "Usuario no encontrado" << endl;
		Console::ForegroundColor = ConsoleColor(15);

	
	}


}



//Empresa

template<typename T>
void Programa<T>::createEmpresa() {

	T name;
	T description;
	T country;
	float rating;
	//system("cls");
	cin.ignore();//So that the next getline doesn't take the nextline or \n

	cout << "Ingrese el nombre de la empresa" << endl;
	std::getline(cin, name);

	cout << "Ingrese la descripcion de la empresa" << endl;
	std::getline(cin, description);

	cout << "Ingrese el pais de la empresa" << endl;
	std::getline(cin, country);

	cout << "Ingrese el rating de la empresa (de 1 - 5)" << endl;
	cin >> rating;
	while (rating>5 || rating<1) {
		cout << "El rating ingresado no se encuentra entre 1 y 5" << endl;
		cin >> rating;
	}

	Empresa<string> auxEmpresa(name, description, country, rating, round(rating*1000));
	//cout << typeid(auxEmpresa).name();
	//auxEmpresa = new Empresa<T>(name, description, country);
	empresas->unshift(auxEmpresa);
	//cout << endl << endl << "Numero de empresas: " << empresas->length() << endl << endl;
}



template<typename T>
void Programa<T>::swap(int index1, int index2) {


	//Caso elemento 0 o nulo
	if (index1 < 1 || index2 > empresas->length() ||  index2 < 1 || index1 > empresas->length()) {
		return;
	}

	//caso mismo elemento
	if (index1 == index2) {
		return;
	}

	//Caso 1er elemento y diferencia de 1
	if (index1 == 1 || index2 == 1) {
		//Definicion
		//cout << "La direccion de cabeza antes de hacer el swap es" << empresas->getHead() << endl;
		if (abs(index1 - index2) == 1) {
			aux1Empresa = empresas->getNodeAt(1);
			//cout << "la direccion de head antes de hacer swap es " << empresas->getHead() << endl;

			//cout << "El valor de aux 1 antes de hacer swap es " << aux1Empresa->getElement().getName() << endl;
			//cout << "la direccion de aux 1 antes de hacer swap es " << aux1Empresa << endl;
			aux2Empresa = aux1Empresa->getNext();
			//cout << "El valor de aux 2 antes de hacer swap es " << aux2Empresa->getElement().getName() << endl;
			//cout << "la direccion de aux 2 antes de hacer swap es " << aux2Empresa << endl;

			aux3Empresa = aux2Empresa->getNext();
			//cout << "El valor de aux 3 antes de hacer swap es " << aux3Empresa->getElement().getName() << endl;
			//cout << "la direccion de aux 3 antes de hacer swap es " << aux3Empresa << endl;


			//intercambio
			aux2Empresa->setNext(aux1Empresa);
			//cout << "El valor de aux 2 despues de hacer swap es " << aux2Empresa->getElement().getName() << endl;

			aux1Empresa->setNext(aux3Empresa);
			//cout << "El valor de aux 1 despues de hacer swap es " << aux1Empresa->getElement().getName() << endl;

			empresas->setHead(aux2Empresa);

			//REVISAR
		
		}
		else if (abs(index1 - index2) > 1) {
			//Definition
			aux1Empresa = empresas->getHead();
			secondElementPrevious = empresas->getNodeAt(index2 - 1);
			aux2Empresa = secondElementPrevious->getNext();
			aux3Empresa = aux2Empresa->getNext();
			//Interchange
			aux2Empresa->setNext(aux1Empresa->getNext());
			secondElementPrevious->setNext(aux1Empresa);
			aux1Empresa->setNext(aux3Empresa);
			empresas->setHead(aux2Empresa);
		}
		//cout << "La direccion de cabeza despues de hacer el swap es" << empresas->getHead() << endl;


		return;
	}

	//Caso que sean dos seguidas
	if (abs(index1 - index2) == 1) {
		//Definicion de nodos
		firstElementPrevious = empresas->getNodeAt(index1 - 1);//Obtenemos el nodo previo
		aux1Empresa = firstElementPrevious->getNext();//Obtenemos el primer nodo
		aux2Empresa = aux1Empresa->getNext();//Obtenemos el segundo nodo
		aux3Empresa = aux2Empresa->getNext();//Obtenemos el siguiente al nodo2
		//Itercambio
		aux2Empresa->setNext(aux1Empresa);
		aux1Empresa->setNext(aux3Empresa);
		firstElementPrevious->setNext(aux2Empresa);
		return;
	}

	
	//Otros casos;
	firstElementPrevious = empresas->getNodeAt(index1 - 1);
	secondElementPrevious = empresas->getNodeAt(index2 - 1);

	aux1Empresa = firstElementPrevious->getNext();//Apuntamos al primer elemento actual
	aux2Empresa = secondElementPrevious->getNext();//Apuntamos al segundo elemento actual
	aux3Empresa = aux2Empresa->getNext();//Obtenemos la direccion del siguiente al segundo elemento actual
	aux2Empresa->setNext(aux1Empresa->getNext());//Apuntamos el nodo siguiente del segundo elemento como el siguiente del nodo primero
	aux1Empresa->setNext(aux3Empresa);//Apuntamos el nodo siguiente del primer elemento como el siguiente del nodo segundo
	firstElementPrevious->setNext(aux2Empresa);//Redirigimos el puntero del elemento previo del primer nodo actual al segundo nodo actual
	secondElementPrevious->setNext(aux1Empresa);//Redirigimos el puntero del elemento previo del segundo nodo actual al primer nodo actual

}



template<typename T>
void Programa<T>::sortBusiness() {
	//RadixSort
	radixMachine = new RadixSort<T>(empresas);
	radixMachine->radixSort();

}



template<typename T>
void Programa<T>::listEmpresa() {
	
	headCopy = empresas->getHead();
	if (headCopy != nullptr) {


		//Show empresas
		headCopy = empresas->getHead();

		//Colores
		for (int i = 0; i < empresas->length(); i++)
		{

			Console::ForegroundColor = ConsoleColor(2);
			cout << "Empresa #" << i + 1 << ":" << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << "Nombre de la empresa: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << headCopy->getElement().getName() << endl;//
			Console::ForegroundColor = ConsoleColor(4);
			cout << "Descripcion de la empresa: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << headCopy->getElement().getDescripcion() << endl;
			Console::ForegroundColor = ConsoleColor(4);//
			cout << "Pais de la empresa: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << headCopy->getElement().getCountry() << endl;//
			Console::ForegroundColor = ConsoleColor(4);
			cout << "Rating de la empresa: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << headCopy->getElement().getRating();
			Console::ForegroundColor = ConsoleColor(4);
			cout << " --> ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << string(round(headCopy->getElement().getRating()), (char)156) << endl << endl;


			headCopy = headCopy->getNext();
		}


	}

	else {
		cout << "\nNo hay alguna empresa registrada!!!\n";

	}

}


//POSTS

template<typename T>
void Programa<T>::createPost() {

	T title;
	T subject;
	T description;
	//system("cls");
	cin.ignore();//So that the next getline doesn't take the nextline or \n

	cout << "Ingrese el titulo del post" << endl;
	std::getline(cin, title);

	cout << "Ingrese el asunto del post" << endl;
	std::getline(cin, subject);

	cout << "Ingrese la descripcion del post" << endl;
	std::getline(cin, description);

	Post<string> auxPost(title, subject, description);
	posts->push(auxPost);

}






template<typename T>
void Programa<T>::listPost() {

	headCopyPost = posts->getHead();
	if (headCopyPost != nullptr) {


		//Show empresas
		headCopyPost = posts->getHead();

		//Colores
		for (int i = 0; i < posts->length(); i++)
		{


			Console::ForegroundColor = ConsoleColor(2);
			cout << "Post #" << i + 1 << ":" << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << "Titulo del post: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << headCopyPost->getElement().getTitle() << endl;//
			Console::ForegroundColor = ConsoleColor(4);
			cout << "Asunto del post: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << headCopyPost->getElement().getSubject() << endl;//
			Console::ForegroundColor = ConsoleColor(4);//
			cout << "Descripcion: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << headCopyPost->getElement().getDescription() << endl;//
			Console::ForegroundColor = ConsoleColor(15);
			


			headCopyPost = headCopyPost->getNext();
		}


	}


	else {
		cout << "\nNo hay algun post registrado!!!\n";

	}

}




//Files


template<typename T>
void Programa<T>::saveFile() {

	
	//For testing
	
	
	/*cout << "Buscando a William Alberto" << endl;
	hashTabla->find("William Alberto");
	cout << "Buscando a Fabrizio Perez" << endl;
	hashTabla->find("Fabrizio Perez");*/



	//Para profesionales
	ofstream file;
	file.open("registrosProfesionales.txt", ios::out);//ios::App

	if (file.fail()) {
		cout << "El archivo no pudo abrirse" << endl;
		_getch();
		exit(0);

	}

	if (arrProfesional != nullptr) {
		//mostrar contactos
		for (int i = 0; i < number; i++) {
			//Nombre del profesional
			file << arrProfesional[i]->getName() << endl;
			//email del profesional
			file << arrProfesional[i]->getEmail() << endl;
			//Celular del profesional
			file << arrProfesional[i]->getNumber_phone() << endl;
			//Universidad del profesional
			file << arrProfesional[i]->getUniversity() << endl;
			//Edad del profesional
			file << arrProfesional[i]->getAge() << endl;
		}
	}
	else {
		file << "";
	}
	file.close();


	//Para empresas
	file.open("registrosEmpresas.txt", ios::out);

	headCopy = empresas->getHead();

	if (headCopy != nullptr) {

		
		for (int i = 0; i < empresas->length(); i++)
		{
			file << headCopy->getElement().getName() << endl;
			file << headCopy->getElement().getDescripcion() << endl;
			file << headCopy->getElement().getCountry() << endl;
			file << headCopy->getElement().getRating()<< endl;
			headCopy = headCopy->getNext();
		}


	}
	else {
		file << "";

	}

	file.close();


	//Para publicaciones
	file.open("registrosPublicaciones.txt", ios::out);


	if (arrPublicaciones != nullptr) {
		//mostrar contactos
		for (int i = 0; i < numberlisting; i++) {

			file << arrPublicaciones[i]->getCategory() << endl;
			file << arrPublicaciones[i]->getJob() << endl;
			file << arrPublicaciones[i]->getTechnologies() << endl;
			file << arrPublicaciones[i]->getDescription() << endl;
			file << arrPublicaciones[i]->getedadmin() << endl;

		}
	}
	else {
		file << "";
	}
	file.close();



	//Para posts
	file.open("registrosPosts.txt", ios::out);
	/// <summary>
	/// /
	/// </summary>
	/// <typeparam name="T"></typeparam>
	headCopyPost = posts->getHead();

	if (headCopyPost != nullptr) {


		for (int i = 0; i < posts->length(); i++)
		{
			file << headCopyPost->getElement().getTitle() << endl;
			file << headCopyPost->getElement().getSubject() << endl;
			file << headCopyPost->getElement().getDescription() << endl;
			headCopyPost = headCopyPost->getNext();

		}


	}
	else {
		file << "";

	}



	file.close();





	saveGeneralFiles();
}


template<typename T>
void Programa<T>::saveGeneralFiles() {

	//Para profesionales
	ofstream file;
	file.open("registrosGenerales.txt", ios::out);//ios::App

	if (file.fail()) {
		cout << "El archivo no pudo abrirse" << endl;
		_getch();
		exit(0);

	}

	file << "Profesionales registrados: " << endl << endl;
	if (arrProfesional != nullptr) {
		//mostrar contactos
		for (int i = 0; i < number; i++) {
			file << "\nProfesional nro " << i + 1;
			file << "\nNombre: ";
			file << arrProfesional[i]->getName();
			file << "\nCorreo: ";
			file << arrProfesional[i]->getEmail();
			file << "\nCelular: ";
			file << arrProfesional[i]->getNumber_phone();
			file << "\nUniversidad: ";
			file << arrProfesional[i]->getUniversity();
			file << "\nEdad: ";
			file << arrProfesional[i]->getAge() << endl;
		}
	}
	else {
		file << "\nNo hay algun usuario registrado!!!\n";
	}
	file << endl << endl;
	


	//Para empresas


	headCopy = empresas->getHead();
	file << "Empresas registradas: " << endl << endl;

	if (headCopy != nullptr) {


		for (int i = 0; i < empresas->length(); i++)
		{
			file << "Empresa #" << i + 1 << ":" << endl;
			file << "Nombre de la empresa: " << headCopy->getElement().getName() << endl;
			file << "Descripcion de la empresa: " << headCopy->getElement().getDescripcion() << endl;
			file << "Pais de la empresa: " << headCopy->getElement().getCountry() << endl;
			file << "Rating de la empresa: " << headCopy->getElement().getRating() << " --> " << string(round(headCopy->getElement().getRating()), '*') << endl;
			file << endl;
			headCopy = headCopy->getNext();
		}


	}
	else {
		file << "\nNo hay alguna empresa registrada!!!\n";

	}

	file << endl << endl;



	//Para publicaciones
	file << "Publicaciones registradas: " << endl << endl;

	if (arrPublicaciones != nullptr) {
		//mostrar contactos
		for (int i = 0; i < numberlisting; i++) {
			file << "\nPublicacion #" << i + 1;
			file << "\nCategoría: ";
			file << arrPublicaciones[i]->getCategory();
			file << "\nTrabajo: ";
			file << arrPublicaciones[i]->getJob();
			file << "\nTecnologías: ";
			file << arrPublicaciones[i]->getTechnologies();
			file << "\nDescripción: ";
			file << arrPublicaciones[i]->getDescription();
			file << "\nEdad mínima requerida: ";
			file << arrPublicaciones[i]->getedadmin();
			file << endl;


		}
	}
	else {
		file << "\nNo hay alguna caracteristica registrada!!!\n";
	}

	file << endl << endl;



	//Para posts
	headCopyPost = posts->getHead();
	file << "Posts registrados: " << endl << endl;

	if (headCopyPost != nullptr) {


		for (int i = 0; i < posts->length(); i++)
		{
			file << "Post #" << i + 1 << ":" << headCopyPost->getElement().getTitle() << endl;
			file << "Post #" << i + 1 << ":" << headCopyPost->getElement().getSubject() << endl;
			file << "Post #" << i + 1 << ":" << headCopyPost->getElement().getDescription() << endl;
			file << endl;
			headCopyPost = headCopyPost->getNext();

		}

	}
	else {
		file << "\nNo hay algun post registrado!!!\n";

	}

	file << endl << endl;

	file.close();


}






//Publicaciones


template<typename T>
void Programa<T>::agregarListing(Listing<T>* objListing) {

	//arreglo temporal
	Listing<T>** arrTemporal = new Listing<T> *[numberlisting + 1];
	//copiar el contenido del arreglo ori al temp
	for (int i = 0; i < numberlisting; i++) {
		arrTemporal[i] = arrPublicaciones[i];
	}
	//agrega al final
	arrTemporal[numberlisting] = objListing;
	//aumenta el tamaño del arreglo
	numberlisting = numberlisting + 1;
	//borra contenido del arreglo ori
	if (arrPublicaciones != nullptr) delete[] arrPublicaciones;
	arrPublicaciones = arrTemporal; //actualiza
	//cout << "Caracteristica agregado de manera satisfactoria" << endl;
	//system("pause");
}

template<typename T>
void Programa<T>::createListing() {
	Listing<T>* auxListing;
	T category;
	T job;
	T technologies;
	T description;
	int edadmin;

	//system("cls");
	cin.ignore();//So that the next getline doesn't take the nextline or \ para que el siguiente getline no tome el nextline
	cout << "Ingrese la categoria del trabajo" << endl;
	//cin >> category;
	std::getline(cin, category);
	cout << "Ingrese el nombre del trabajo" << endl;
	//cin >> job;
	std::getline(cin, job);
	cout << "Ingrese las tecnologias usadas" << endl;
	//cin >> technologies;
	std::getline(cin, technologies);
	cout << "Ingrese una descripcion" << endl;
	//cin >> description;
	std::getline(cin, description);
	cout << "Ingrese la edad minima requerida" << endl;
	cin >> edadmin;
	//std::getline(cin, edadmin);
	auxListing = new Listing<string>(category, job, technologies, description, edadmin);
	//cout << "Listing creado";
	agregarListing(auxListing);
}

template<typename T>
T Programa<T>::obtenerListing(int indice) {
	return arrPublicaciones[indice];
}


template<typename T>
void Programa<T>::listarListing() {

	//DesordenarListing();

	if (arrPublicaciones != nullptr) {
		//mostrar contactos
		for (int i = 0; i < numberlisting; i++) {
			Console::ForegroundColor = ConsoleColor(2);
			cout << "\nPublicacion #" << i + 1 << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << string(5, S) << "\nCategoria: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << arrPublicaciones[i]->getCategory() << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << string(5, S) << "\nTrabajo: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << arrPublicaciones[i]->getJob() << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << string(5, S) << "\nTecnologias: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << arrPublicaciones[i]->getTechnologies() << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << string(5, S) << "\nDescripcion: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << arrPublicaciones[i]->getDescription() << endl;
			Console::ForegroundColor = ConsoleColor(4);
			cout << string(5, S) << "\nEdad minima requerida: ";
			Console::ForegroundColor = ConsoleColor(15);
			cout << arrPublicaciones[i]->getedadmin() << endl;

		}
	}
	else {
		cout << "\nNo hay alguna caracteristica registrada!!!\n";
	}
}



template<typename T>
void Programa<T>::DesordenarListing() {


	for (int i = numberlisting - 1; i > 0; i--) {

		int j = rand() % (i + 1);

		Listing<T>* aux = arrPublicaciones[i];
		arrPublicaciones[i] = arrPublicaciones[j];
		arrPublicaciones[j] = aux;


	}

}





//For loading components

t
void Programa<T>::loadComponents() {
	loadEmpresa();
	loadListing();
	loadPost();
	loadProfesional();
}

t
void Programa<T>::loadEmpresa() {


	ifstream file;
	file.open("registrosEmpresas.txt", ios::in);//ios::App

	if (file.fail()) {
		return;
		cout << "El archivo no pudo abrirse" << endl;
		_getch();
		exit(0);

	}
	while (!file.eof())
	{
		//Read 4 lines at a time


		string name;
		string description;
		string country;
		string ratingString;
		float rating;
		std::getline(file, name);
		std::getline(file, description);
		std::getline(file, country);
		std::getline(file, ratingString);
		if (ratingString!="") {
			rating = stod(ratingString);
		}
		/*cout << name << endl;
		cout << description << endl;
		cout << country << endl;
		cout << rating << endl;*/
		if (name!="" && description != ""&& country != ""&& ratingString != "") {
			Empresa<string> auxEmpresa(name, description, country, rating, round(rating*1000));
			empresas->push(auxEmpresa);
		}
		
	}
	file.close();
}

t
void Programa<T>::loadListing() {


	ifstream file;
	file.open("registrosPublicaciones.txt", ios::in);//ios::App

	if (file.fail()) {
		return;
		cout << "El archivo no pudo abrirse" << endl;
		_getch();
		exit(0);

	}
	while (!file.eof())
	{
		//Read 4 lines at a time


		string category;
		string job;
		string technologies;
		string description;
		string edadmin;
		std::getline(file, category);
		std::getline(file, job);
		std::getline(file, technologies);
		std::getline(file, description);
		std::getline(file, edadmin);

		if (category != "" && job != "" && technologies != "" && description != "" && edadmin != "") {
			Listing<T>* auxListing;
			auxListing = new Listing<string>(category, job, technologies, description, stoi(edadmin));
			agregarListing(auxListing);

		}

	}
	file.close();
}

t
void Programa<T>::loadPost() {


	ifstream file;
	file.open("registrosPosts.txt", ios::in);//ios::App

	if (file.fail()) {
		return;
		cout << "El archivo no pudo abrirse" << endl;
		_getch();
		exit(0);

	}
	while (!file.eof())
	{
		//Read 3 lines at a time


		string title;
		string subject;
		string description;
		std::getline(file, title);
		std::getline(file, subject);
		std::getline(file, description);

		if (title != "" && subject != "" && description != "") {
			Post<string> auxPost(title, subject, description);
			posts->push(auxPost);

		}
	}
	file.close();
}

t
void Programa<T>::loadProfesional() {


	ifstream file;
	file.open("registrosProfesionales.txt", ios::in);//ios::App

	if (file.fail()) {
		return;
		cout << "El archivo no pudo abrirse" << endl;
		_getch();
		exit(0);

	}
	while (!file.eof())
	{
		//Read 5 lines at a time


		string name;
		string email;
		string number_phone;
		string university;
		string preAge;
		int age;
		std::getline(file, name);
		std::getline(file, email);
		std::getline(file, number_phone);
		std::getline(file, university);
		std::getline(file, preAge);


		if (name != "" && email != "" && number_phone != "" && university != "" && preAge != "") {
			Profesional<T>* auxProfesional;
			auxProfesional = new Profesional<string>(name, email, number_phone, university, preAge);
			agregarProfesional(auxProfesional);

		}



	}
	file.close();
}


