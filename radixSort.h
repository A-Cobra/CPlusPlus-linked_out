#pragma once
#include "LinkedList.h"
//#define 

//TRIALS
t
struct radixStruct
{
	Node<T>* firstElement;
	Node<T>* pentultimateElement;
	int numberOfElements;

	radixStruct() {
		firstElement = n;
		pentultimateElement = n;
		numberOfElements = 0;
	}
};
//TRIALS





//Quizás le tengamos que poner el siguiente
//template<class u, class v>
t
class RadixSort
{
private:
	//LinkedList<T>* unsortedList;
	LinkedList<Empresa<T>>* unsortedList;
	Node<Empresa<T>>* aux;
	Empresa<T> auxEmpresa;
	int number;
public:
	RadixSort(/*LinkedList<T>* unsortedList*/LinkedList<Empresa<T>>* unsortedList);
	~RadixSort();
	void radixSort();
	int countDigits(long long baseNumber);

};

t
RadixSort<T>::RadixSort(/*LinkedList<T>* unsortedList*/LinkedList<Empresa<T>>* unsortedList)
{
	this->unsortedList = unsortedList;
	aux = this->unsortedList->getHead();
	number = this->unsortedList->length();
	/*for (int i = 0; i < this->unsortedList->length(); i++)
	{
		auxEmpresa = aux->getElement();
		cout << "Rating empresa i " << auxEmpresa.getSortRating() << endl;
		cout << "Numero de digitos" << countDigits(auxEmpresa.getSortRating()) << endl;
		aux = aux->getNext();
	}*/
}

t
RadixSort<T>::~RadixSort()
{
}





//THIS WORKS SO FAR, THE NEXT ARE TRIALS OF RADIX SORT
t
int RadixSort<T>::countDigits(long long baseNumber) {
	return floor(log10(baseNumber)) + 1;
}
	//WORKING SO FAR

t
void RadixSort<T>::radixSort() {
	
	//THIS WAS FOR TESTING ONLY, DOESN'T DO ANYTHING IN THE CODE
	/*cout << "Lista desordenada" << endl;
	printUnsortedList();
	cout << endl << endl << endl << "Lista Ordenada" << endl << endl;
	auxNode = unsortedList->extractFirst();
	radixTable[1].firstElement = auxNode;
	radixTable[1].pentultimateElement = auxNode;
	radixTable[1].numberOfElements = 1;
	refillLinkedList();
	printUnsortedList();*/
	//THIS WAS FOR TESTING ONLY, DOESN'T DO ANYTHING IN THE CODE





	//If the list contains just one element or doesn't exist, we return
	if (number < 2) { return; };

	//Vector para ordenar la lista
	radixStruct<Empresa<T>>* radixTable = new radixStruct<Empresa<T>>[10];
	//radixTable[0].firstElement = unsortedList->getHead();

	int counter = 0;//Contador de veces que se ejecuta el bucle
	////Node<T>* auxNode;//Nodo auxiliar //QUIZÁS SEA NECESARIO QUE SEA INT EN VEZ DE T
	Node<Empresa<T>>* auxNode;//Nodo auxiliar //QUIZÁS SEA NECESARIO QUE SEA INT EN VEZ DE T
	Node<Empresa<T>>* auxNode2;//Nodo auxiliar 2
	int maxDigits = 1;//Contador de mayor cantidad de dígitos
	int remaining;//Will count the last digit of the number
	int auxDigits;//Will help us count the maximum number of digits
	long long preRemaining;//Will help us find the LSD


	//SOME LAMBDAS
	// Lambda that will print the elements of the radixTable
	auto printRadixTable = [&]() {

		for (int i = 0; i < 10; i++)
		{
			cout << "Elements file " << i + 1 << " (" << radixTable[i].numberOfElements << " elements) : " << endl;
			auxNode2 = radixTable[i].firstElement;
			for (int j = 0; j < radixTable[i].numberOfElements; j++)
			{
				cout << "Direccion de memoria: " << auxNode2 << ", Rating" << auxNode2->getElement().getSortRating() << " ";
				auxNode2 = auxNode2->getNext();
			}
			cout << endl;
			cout << "Direccion de memoria de penultimo elemento: " << radixTable[i].pentultimateElement;
			cout << endl;
		}


	};
	//Lambda that will help us clean the array of struct
	auto cleanRadixTable = [&]() {
		for (int i = 0; i < 10; i++)
		{
			radixTable[i].numberOfElements = 0;
			radixTable[i].firstElement = n;
			radixTable[i].pentultimateElement = n;
		}
	};
	//Fill array will helps us know if the array at certian position is occupied
	/*void(*fillRadixTable)()*/
	auto fillRadixTable = [&]() {

		//Si el arreglo en esa posicion está vacio
		if (radixTable[remaining].numberOfElements == 0) {
			radixTable[remaining].firstElement = auxNode;
			radixTable[remaining].pentultimateElement = auxNode;
			radixTable[remaining].numberOfElements++;
		}
		//Si el arreglo cuenta con por lo menos un elemento
		else {
			//radixTable[remaining].pentultimateElement = radixTable[remaining].firstElement;
			radixTable[remaining].pentultimateElement->setNext(auxNode);
			auxNode->setPrevious(radixTable[remaining].pentultimateElement);
			radixTable[remaining].pentultimateElement = auxNode;
			radixTable[remaining].numberOfElements++;

		}


	};
	//To refill the linked list
	/*void(*refillLinkedList)()*/
	auto refillLinkedList = [&]() {
		//We refill the entire Linked List again
		for (int i = 0; i < 10; i++)
		{
			if (radixTable[i].numberOfElements >= 1) {
				//We push the elements to the end of the list
				unsortedList->pushRadix(radixTable[i].firstElement, radixTable[i].pentultimateElement, radixTable[i].numberOfElements);


			}

		}

		//Node<T>* firstElement, Node<T>* pentultimateElement,  int sublistNumber


	};
	//Lambda to print the unsortedList
	auto printUnsortedList = [&]() {

		Node<Empresa<T>>* headCopy = unsortedList->getHead();


		if (headCopy != nullptr) {

			for (int i = 0; i < number; i++)
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



	};

	

	//TESTING ONLY
	//cout << "Lista desordenada" << endl;
	//printUnsortedList();
	//TESTING ONLY




	while (counter < maxDigits)
	{
		//We execute this as many times as the maximum amount of digits

		//The first time we do the same and also count the maximum amount of digits
		if (counter == 0)
		{
			//To know the maximum number of digits
			for (int i = 0; i < number; i++)
			{
				//We get the first node of the LinkedList
				auxNode = unsortedList->extractFirst();
				auxDigits = countDigits(auxNode->getElement().getSortRating());

				//Si auxDigits es mayor que maxDigits
				if (maxDigits < auxDigits) {
					maxDigits = auxDigits;
				}

				//Hallamos la unidad del numero
				remaining = auxNode->getElement().getSortRating() % 10;

				fillRadixTable();


			}

			//FOR TESTING PURPOSES ONLY
			/*System::Console::ForegroundColor = System::ConsoleColor(3);
			printRadixTable();
			System::Console::ForegroundColor = System::ConsoleColor(15);*/
			//FOR TESTING PURPOSES ONLY



			refillLinkedList();



			//FOR TESTING PURPOSES ONLY
			/*System::Console::ForegroundColor = System::ConsoleColor(4);
			cout << endl << endl << endl << "Pasada " << counter + 1 << endl;
			unsortedList->printElements();
			System::Console::ForegroundColor = System::ConsoleColor(15);*/
			//FOR TESTING PURPOSES ONLY



			cleanRadixTable();
			counter++;




			continue;
		}


		//WORKS SO FAR


		//For the following sorting
		//------------------------------------
		for (int i = 0; i < number; i++)
		{

			//We get the first node of the LinkedList
			auxNode = unsortedList->extractFirst();
			if (auxNode->getElement().getSortRating() >= pow(10, counter)) {
				//We get the number divided by 10 to the power of counter
				preRemaining = (long long)(auxNode->getElement().getSortRating() / pow(10, counter));
				//We get the ramainder of the division between that number and 10
				remaining = preRemaining % 10;
			}
			else {
				remaining = 0;
			}
			fillRadixTable();

		}


		//FOR TESTING PURPOSES ONLY
		/*System::Console::ForegroundColor = System::ConsoleColor(3);
		printRadixTable();
		System::Console::ForegroundColor = System::ConsoleColor(15);*/
		//FOR TESTING PURPOSES ONLY



		refillLinkedList();


		//FOR TESTING PURPOSES ONLY
		/*System::Console::ForegroundColor = System::ConsoleColor(4);
		cout << endl << endl << endl << "Pasada " << counter + 1 << endl;
		unsortedList->printElements();
		System::Console::ForegroundColor = System::ConsoleColor(15);*/
		//FOR TESTING PURPOSES ONLY


		cleanRadixTable();
		counter++;






	}



	//TESTING ONLY
	//cout << endl << endl << endl << "Lista Ordenada" << endl << endl;
	//printUnsortedList();
	//TESTING ONLY




	cleanRadixTable();
	aux = n;
	auxNode = n;
	auxNode2 = n;
	radixTable = n;
	delete auxNode, auxNode2, radixTable, aux;




}