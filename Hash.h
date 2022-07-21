#include <functional>

//template<class value>
//struct hashData
//{
//	bool found;
//	value pointer;
//	hashData(bool _found,value _pointer) {
//		this->found = _found;
//		this->pointer = _found;
//	
//	}
//};


template<class key, class value>
class HashEntidad {
private:
	key llave;
	value valor;
public:
	HashEntidad(key llave, value valor) {
		this->llave = llave;
		this->valor = valor;
	}
	key getKey() {
		return llave;
	}

	value getValue() {
		return valor;
	}

	void setValue(value nuevovalor) {
		valor = nuevovalor;
	}

};
template <class key, class value>
class Hashtable {
	//struct Entity {
	//	string key;   //nombres
	//	T value;
	//	Entity(string key, T value) {
	//		this->key = key;
	//		this->value = value;
	//	}
	//};
	//function<int(key, int)> f_hash;
	int hashFunc1(string myWord, int number);
	HashEntidad<key, value>** tabla;
	/*Profesional<U>** tabla;*/
	int table_size;
	int numElementos;


	/*function<void(Entity)> show;*/
public:
	/*Hashtable(function<void(T)> show, size_t capacidad) :table_size(capacidad) {
		ht = new Profesional<U>** arrProfesional<Entity>*[capacidad];
		for (int i = 0; i < table_size; i++)
			ht[i] = nullptr;
		this->show = [&show](Entity e)->void {
			show(e.value);
		}
	}*/
	Hashtable(size_t table_size) {
		this->table_size = table_size;
		tabla = new HashEntidad<key, value>*[table_size];
		for (int i = 0; i < table_size; i++) {
			tabla[i] = nullptr;
		}
		numElementos = 0;
		//f_hash = f;
	}
	~Hashtable() {
		for (int i = 0; i < table_size; i++) {
			if (tabla[i] != nullptr)
				delete tabla[i];
		}
		delete[] tabla;  //chau tabla
	}

	void insertar(key llave, value valor) {
		int base, hash, paso;
		//if (numElementos == table_size) return;
		base = hashFunc1(llave, table_size); //key % table_size;
		hash = base;
		paso = 0;
		while (tabla[hash] != nullptr) {
			hash = (base + paso) % table_size;
			paso++;
		}
		tabla[hash] = new HashEntidad<key, value>(llave, valor);
	}

	void mostrar()
	{
		for (int i = 0; i < table_size; i++)
		{
			if (tabla[i] != nullptr)
			{
				cout << "Indice: " << i << "\tKey: " << tabla[i]->getKey() << "\tValue: " << tabla[i]->getValue() << endl;
			}
		}
	}

	void trial() {
	
	
		cout << "Numero de elementos: " << numElementos << endl;
		cout << "Table Size: " << table_size << endl;

	}
	/*void insertar(string key, T value) {
		size_t index = HashFuncion(key);
		if (!ht[index])
			ht[index] = new Profesional<U>**arrProfesional<Entity>(this->show);
		ht[index]->pushBack(Entity(key, value));
	}*/



	value find(key llave) {
		int step = 0;
		int i, base;
		i = base = hashFunc1(llave, table_size);

		cout << "Funciona" << endl;

		while (true)
		{
			if (tabla[i] == nullptr)
			{
				//cout << "No encontrado" << endl;
				return nullptr;
				
			}
			else if (tabla[i]->getKey() == llave) {
				//cout << "Elemento encontrado" << endl;
				return tabla[i]->getValue();
			}
			i = (base + step) % table_size;
			step++;
		}

	
	}

};



template <class key, class value>
int Hashtable<key, value>::hashFunc1(string myWord, int tableSize) {
	int counter = 0;
	for (int i = 0; i < myWord.length(); i++)
	{
		counter += myWord[i];
	}
	return counter % tableSize;
}


