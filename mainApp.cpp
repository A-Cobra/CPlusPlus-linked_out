#include<iostream>
#include<conio.h>
//For testing
#include <typeinfo>
//For testing

#include "Menu.h"
#include "Listing.h"
#include "Node.h"
#include "Empresa.h"
#include "LinkedList.h"
using namespace std;
#define C (char)219 //Code for Solid Block
#define S (char)32 //Code for space


int main() {


	Console::SetWindowSize(150, 49);
	Menu<string>* first = new Menu<string>();
	while (first->getOption() != 14) {
		first->show();
		if (first->getOption() == 14) {
			break;
		}
		first->resetOption();
	}
	first->draw();
	Console::SetCursorPosition(70, 37);
	Console::ForegroundColor = ConsoleColor(13);
	cout << "Muchas gracias por usar la aplicacion, esperamos verlo pronto" << endl;
	//cout << string(46, S) << "Presione cualquier tecla para salir del programa" << endl;
	Console::SetCursorPosition(80, 38);
	//cout << "Presione cualquier tecla para salir del programa" << endl;
	//_getch();
	_sleep(800);
	exit(0);


}