#pragma once
#define C (char)219 //Code for Solid Block
#define S (char)32 //Code for space

#include<iostream>
#include "Programa.h"
using namespace std;
using namespace System;


template<typename T>
class Menu
{
public:
	int option;
	int indent;
	int counter;
	Programa<T>* controladora;

private:
	//CPrograma* programa1;
public:
	Menu();
	~Menu();
	void showLogo();
	void show();
	void resetOption();
	void draw();
	int getOption();
};



template<typename T>
Menu<T>::Menu() {
	option = 0;
	indent = 10;
	counter = 0;
	controladora = new Programa<T>();
	

	//Logo2 = Logo;
}

template<typename T>
Menu<T>::~Menu() {

}

template<typename T>
void Menu<T>::showLogo() {
	int Logo[23][74] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};

	if (counter == 0) {
		for (int i = 0; i < 23; i++)
		{
			Console::SetCursorPosition(65, i);
			_sleep(300);
			for (int j = 0; j < 74; j++) {
				if (Logo[i][j] == 1) {
					Console::ForegroundColor = ConsoleColor::Red;
					cout << char(219);
				}
				if (Logo[i][j] == 0) {
					cout << " ";
				}
			}
			cout << endl;
		}
	}

	else {
		for (int i = 0; i < 23; i++)
		{
			Console::SetCursorPosition(65, i);
			for (int j = 0; j < 74; j++) {
				if (Logo[i][j] == 1) {
					Console::ForegroundColor = ConsoleColor::Red;
					cout << char(219);
				}
				if (Logo[i][j] == 0) {
					cout << " ";
				}
			}
			cout << endl;
		}
	}






}

template<typename T>
void Menu<T>::show() {
	draw();
	//Lambda Function that encapsules the option value and can modify it
	auto getOption = [&]() {
		
		while (option < 1 || option > 14) {
			Console::SetCursorPosition(71, 33);//51,33 //For refreshing the textbox
			cout << string(38, S);
			Console::SetCursorPosition(90, 33);//70,33 //For the option
			cin >> option;
		}
		Console::ForegroundColor = ConsoleColor(15);
	};
	getOption();
	system("cls");
	Console::SetCursorPosition(0, 5);
	switch (option) {
	case 1:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Registro de profesional" << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->createProfesional();
		break;
	case 2:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Listado de profesionales" << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->listarProfesional();
		break;
	case 3:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Ordenando lista de profesionales..." << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->ordenarEdades();
		break;

	case 4:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Registro de empresas" << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->createEmpresa();
		break;
	case 5:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Listado de empresas" << endl;
		cout << string(39, '=') << endl << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->listEmpresa();
		break;
	case 6:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Ordenando empresas";
		for (int i = 0; i < 3; i++)
		{
			_sleep(300);
			cout << ".";

		}
		cout << endl;
		//cout << string(39, '=') << endl << endl;
		cout << endl << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->sortBusiness();
		break;
	case 7:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Agregar Publicacciones" << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->createListing();
		break;
	case 8:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Listado de caracteristicas" << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->listarListing();
		break;
	case 9:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Desordenando lista de publicaciones..." << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->DesordenarListing();
		break;
	case 10:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Agregar un Post" << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->createPost();
		break;
	case 11:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Listado de Posts" << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->listPost();
		break;

	case 12:
		//Buscar Profesional
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Busqueda de profesional por nombre" << endl;
		Console::ForegroundColor = ConsoleColor(15);
		controladora->searchProfesional();
		break;

	case 13:
		Console::ForegroundColor = ConsoleColor(3);
		cout << "Ordenar publicaciones por edad min" << endl;
		Console::ForegroundColor = ConsoleColor(15);
		//cout << "Decidio salir del programa" << endl;
		controladora->ordenaredadmin();
		//_getch();
		break;

	case 14:
		//cout << "Decidio salir del programa" << endl;
		controladora->saveFile();
		//_getch();
		break;


	}
	if (option != 14) {
		system("pause");
	}

}

template<typename T>
int Menu<T>::getOption() {
	return option;
}

template<typename T>
void Menu<T>::resetOption() {
	option = 0;
}

template<typename T>
void Menu<T>::draw() {
	system("cls");
	showLogo();
	Console::SetCursorPosition(0, 0);
	cout << endl << endl << endl;
	Console::ForegroundColor = ConsoleColor(4);
	cout << string(15, S) << string(2, C) << string(62, S) << string(2, C);//
	cout << endl;
	cout << string(15, S) << string(2, C) << string(10, S) << string(2, C) << string(14, S) << string(2, C) << string(8, S) << string(2, C) << string(24, S) << string(2, C);//
	cout << endl;
	cout << string(15, S) << string(2, C) << string(26, S) << string(2, C) << string(6, S) << string(2, C) << string(26, S) << string(2, C);//Bien
	cout << endl;
	cout << string(15, S) << string(2, C) << string(10, S) << string(2, C) << string(2, S) << string(2, C) << string(10, S) << string(2, C) << string(4, S) << string(2, C) << string(10, S) << string(2, C)
		<< string(10, S) << string(8, C);
	cout << endl;
	cout << string(15, S) << string(2, C) << string(10, S) << string(2, C) << string(2, S) << string(10, C) << string(2, S) << string(2, C) << string(2, S) << string(2, C) << string(10, S) << string(2, C)
		<< string(2, S) << string(2, C) << string(6, S) << string(2, C) << string(6, S) << string(2, C);//Bien
	cout << endl;
	cout << string(15, S) << string(2, C) << string(10, S) << string(2, C) << string(2, S) << string(2, C) << string(6, S) << string(2, C) << string(2, S) << string(4, C) << string(10, S) << string(2, C)
		<< string(6, S) << string(2, C) << string(2, S) << string(2, C) << string(8, S) << string(2, C);//Bien
	cout << endl;
	cout << string(15, S) << string(2, C) << string(10, S) << string(2, C) << string(2, S) << string(2, C) << string(6, S) << string(2, C) << string(2, S) << string(2, C) << string(2, S) << string(2, C)
		<< string(8, S) << string(8, C) << string(4, S) << string(2, C) << string(8, S) << string(2, C);//Bien
	cout << endl;
	cout << string(15, S) << string(2, C) << string(10, S) << string(2, C) << string(2, S) << string(2, C) << string(6, S) << string(2, C) << string(2, S) << string(2, C) << string(4, S) << string(2, C)
		<< string(6, S) << string(2, C) << string(10, S) << string(2, C) << string(8, S) << string(2, C);//Bien
	cout << endl;
	cout << string(15, S) << string(2, C) << string(10, S) << string(2, C) << string(2, S) << string(2, C) << string(6, S) << string(2, C) << string(2, S) << string(2, C) << string(6, S) << string(2, C)
		<< string(6, S) << string(2, C) << string(4, S) << string(2, C) << string(4, S) << string(2, C) << string(6, S) << string(2, C);//Bien
	cout << endl;
	cout << string(15, S) << string(10, C) << string(2, S) << string(2, C) << string(2, S) << string(2, C) << string(6, S) << string(2, C) << string(2, S) << string(2, C) << string(8, S) << string(2, C)
		<< string(6, S) << string(4, C) << string(8, S) << string(8, C);//Bien
	cout << endl << endl << endl;
	Console::ForegroundColor = ConsoleColor(3);
	cout << string(41, S) << string(14, C);
	cout << endl;//
	cout << string(41, S) << string(2, C) << string(10, S) << string(2, C) << string(12, S) << string(10, C);//Bien
	cout << endl;
	cout << string(41, S) << string(2, C) << string(10, S) << string(2, C) << string(16, S) << string(2, C);//Bien
	cout << endl;
	cout << string(41, S) << string(2, C) << string(10, S) << string(2, C) << string(2, S) << string(2, C) << string(4, S) << string(2, C) << string(6, S) << string(2, C);//Bien
	cout << endl;
	cout << string(41, S) << string(2, C) << string(10, S) << string(2, C) << string(2, S) << string(2, C) << string(4, S) << string(2, C) << string(6, S) << string(2, C);//Bien
	cout << endl;
	cout << string(41, S) << string(2, C) << string(10, S) << string(2, C) << string(2, S) << string(2, C) << string(4, S) << string(2, C) << string(6, S) << string(2, C);//Bien
	cout << endl;
	cout << string(41, S) << string(14, C) << string(2, S) << string(8, C) << string(6, S) << string(2, C);
	cout << endl << endl << endl;
	Console::ForegroundColor = ConsoleColor(5);
	counter += 1;
	cout << string(indent, S) << "Por favor elija una de las siguientes opciones " << endl << endl;
	Console::ForegroundColor = ConsoleColor(15);
	cout << string(indent + 5, S) << "1. Agregar profesional" << endl;
	cout << string(indent + 5, S) << "2. Listar todos los profesionales registrados" << endl;
	cout << string(indent + 5, S) << "3. Ordenar lista de profesionales por edad" << endl;
	cout << string(indent + 5, S) << "4. Agregar empresas" << endl;
	cout << string(indent + 5, S) << "5. Listar todas la empresas registradas" << endl;
	cout << string(indent + 5, S) << "6. Ordenar la lista de empresas registradas" << endl;
	cout << string(indent + 5, S) << "7. Agregar publicaciones" << endl;
	cout << string(indent + 5, S) << "8. Listar publicaciones" << endl;
	cout << string(indent + 5, S) << "9. Desordenar publicaciones" << endl;
	cout << string(indent + 5, S) << "10. Agregar un Post" << endl;
	cout << string(indent + 5, S) << "11. Listar todos los Posts" << endl;
	cout << string(indent + 5, S) << "12. Buscar Profesional por nombre" << endl;
	cout << string(indent + 5, S) << "13. Ordenar publicaciones por edad minima" << endl;
	cout << string(indent + 5, S) << "14. Guardar registros y cerrar la aplicacion" << endl;
	Console::ForegroundColor = ConsoleColor(2);
	Console::SetCursorPosition(70, 32);//50,32
	cout << (char)201 << string(38, (char)205) << (char)187;
	Console::SetCursorPosition(70, 33);//50,33
	cout << (char)186;
	Console::SetCursorPosition(109, 33);//89,33
	cout << (char)186;
	Console::SetCursorPosition(70, 34);//50,34
	cout << (char)200 << string(38, (char)205) << (char)188;
	Console::ForegroundColor = ConsoleColor(3);
	Console::SetCursorPosition(90, 33);//70,32
}