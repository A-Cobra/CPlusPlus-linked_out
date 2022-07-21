#pragma once

//ArbolBB.hpp

#include <stdlib.h>

#include <time.h>

#include <iostream>


#include <functional>

using namespace std;



template <class T>

class NodeBST {

public:

	T elemento;

	NodeBST* izq;

	NodeBST* der;

};



template <class T>

class ArbolBB {

	typedef function<int(T, T)> Comp; //Lambda



	NodeBST<T>* raiz;

	void(*procesar)(T); //Puntero a funcion



	Comp comparar; // lambda de criterio de comparación





private:

	bool _buscar(NodeBST<T>* nodo, T e) {

		if (nodo == nullptr) return false;

		else {

			int r = comparar(nodo->elemento, e);

			if (r == 0) return true;

			else if (r < 0) {

				return _buscar(nodo->der, e);

			}

			else {

				return _buscar(nodo->izq, e);

			}

		}

	}

	NodeBST<T>* _obtener(NodeBST<T>* nodo, T e) {

		if (nodo == nullptr) return nullptr;

		else {

			int r = comparar(nodo->elemento, e);

			if (r == 0) return nodo;

			else if (r < 0) {

				return _buscar(nodo->der, e);

			}

			else {

				return _buscar(nodo->izq, e);

			}

		}

	}

	bool _insertar(NodeBST<T>*& nodo, T e/*e es empresa y nodo es la raiz*/) {

		if (nodo == nullptr) {

			nodo = new NodeBST<T>();

			nodo->elemento = e;

			return true;

		}

		else {

			int r = comparar(nodo->elemento/*.getUniqueId()*/, e);

			if (r == 0) return false;

			else if (r < 0) {

				return _insertar(nodo->der, e);

			}

			else {

				return _insertar(nodo->izq, e);

			}

		}

	}

	void _enOrden(NodeBST<T>* nodo) {

		if (nodo == nullptr) return;

		_enOrden(nodo->izq);

		procesar(nodo->elemento);

		_enOrden(nodo->der);

	}



	void _preOrden(NodeBST<T>* nodo) {

		if (nodo == nullptr) return;

		procesar(nodo->elemento);

		_preOrden(nodo->izq);

		_preOrden(nodo->der);

	}



	void _postOrden(NodeBST<T>* nodo) {

		if (nodo == nullptr) return;

		_postOrden(nodo->izq);

		_postOrden(nodo->der);

		procesar(nodo->elemento);

	}

	bool _vacio() {

		return raiz == nullptr;

	}

	int _cantidad(NodeBST<T>* nodo) {

		//La cantidad de nodos del árbol es:

		//	0 si es vacío

		//	1 + la cantidad de nodos por la izquierda + la cantidad de nodos por la derecha



		if (nodo == nullptr)

			return 0;

		else

		{

			int ci, cd;

			ci = _cantidad(nodo->izq);

			cd = _cantidad(nodo->der);

			return 1 + ci + cd;

		}



	}

	int _altura(NodeBST<T>* nodo) {

		//La altura del árbol es:

		//	0 si es vacío

		//	la mayor de las alturas por la izquierda y por la derecha, las cuáles son 0 si son vacías ó 1 + la altura por la izq(o der) en caso contrario



		if (nodo == nullptr)

			return 0;

		else

		{

			int ai, ad;

			ai = 1 + _altura(nodo->izq);

			ad = 1 + _altura(nodo->der);

			return ai > ad ? ai : ad;

		}

	}



	int _minimo(NodeBST<T>* nodo) {

		if (nodo->izq == nullptr) return nodo->elemento;

		else

			return _minimo(nodo->izq);

	}

	int _maximo(NodeBST<T>* nodo) {

		if (nodo->der == nullptr) return nodo->elemento;

		else

			return _maximo(nodo->der);

	}



	bool _eliminar(NodeBST<T>*& nodo, T e) {

		if (nodo == nullptr) return false;

		else

		{

			int r = comparar(nodo->elemento, e);

			if (r < 0) {

				return _eliminar(nodo->der, e);

			}

			else if (r > 0) {

				return _eliminar(nodo->izq, e);

			}

			else { //r==0 es porque encontró el elemento en el árbol

				if (nodo->der == nullptr && nodo->izq == nullptr) { //caso 1

					nodo = nullptr;

					delete nodo;

					return true;

				}

				else if (nodo->izq == nullptr) {//caso 2

					nodo = nodo->der;

					return true;

				}

				else if (nodo->der == nullptr) {//caso 3

					nodo = nodo->izq;

					return true;

				}

				else {//caso 4

					NodeBST<T>* aux = nodo->der; //Se establece buscar el menor elemento por la derecha

					while (aux->izq != nullptr) {

						aux = aux->izq; //Obtiene la hoja menor

					}

					nodo->elemento = aux->elemento;//Se actualiza el elemento en el nodo raiz

					return _eliminar(nodo->der, aux->elemento); //se envía a eliminar el elemento en el árbol por la derecha

				}



			}

		}

	}





public:

	ArbolBB(void(*otroPunteroAFuncion)(T)) {

		this->procesar = otroPunteroAFuncion;

		this->comparar = [](T a, T b)->int {return a - b; };//Lambda TO CHANGE

		raiz = nullptr;

	}

	bool insertar(T e) {

		return _insertar(raiz, e);

	}

	void enOrden() {

		_enOrden(raiz);

	}

	void preOrden() {

		_preOrden(raiz);

	}

	void postOrden() {

		_postOrden(raiz);

	}

	int cantidad() {

		return _cantidad(raiz);

	}

	int altura() {

		return _altura(raiz);

	}

	bool Buscar(T e) {

		return _buscar(raiz, e);

	}

	int Minimo() {

		return _minimo(raiz);

	}

	int Maximo() {

		return _maximo(raiz);

	}

	bool Eliminar(T e) {

		return _eliminar(raiz, e);

	}



};


//Consola.h

void imprimir(int e) {

	cout << " " << e;

}



int main2() {

	//srand(time(0));

	ArbolBB<int>* arbol = new ArbolBB<int>(imprimir);

	/*

	for (int i = 0; i < 30; ++i) {

	arbol->insertar(rand() % 100);

	}*/





	arbol->insertar(10);

	arbol->insertar(4);

	arbol->insertar(15);

	arbol->insertar(2);

	arbol->insertar(5);



	cout << "EnOrden";

	arbol->enOrden();

	cout << endl;



	cout << "PreOrden";

	arbol->preOrden();

	cout << endl;



	cout << "PostOrden";

	arbol->postOrden();

	cout << endl;



	cout << "Altura: " << arbol->altura() << endl;

	cout << "Cantidad: " << arbol->cantidad() << endl;



	cout << "Encontrar 26: " << arbol->Buscar(26) << endl;

	cout << "Encontrar 100: " << arbol->Buscar(100) << endl;







	cout << "Minimo: " << arbol->Minimo() << endl;

	cout << "Maximo: " << arbol->Maximo() << endl;



	arbol->Eliminar(2);


	arbol->Eliminar(4);




	cout << "EnOrden:";

	arbol->enOrden();

	cout << endl;



	cout << "EnPreOrden:";

	arbol->preOrden();

	cout << endl;



	cin.get();



	return 0;

}