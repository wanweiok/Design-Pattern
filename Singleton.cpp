#include "pch.h"
#include <assert.h> 
#include "Singleton.h"
using namespace std;

Singleton* Singleton::_instance = nullptr;
Singleton::GC Singleton::gc;
Singleton* Singleton::Instance() {
	if (_instance == NULL) {
		_instance = new Singleton();
	}
	return _instance;
}

int Monostate::itsX = 0;

int main()
{
	Singleton* test1 = Singleton::Instance();
	Singleton* test2 = Singleton::Instance();
	assert(test1 == test2);
	
	Monostate* state1 = new Monostate();
	Monostate* state2 = new Monostate();
	state1->setX(10);
	assert(state2->getX() == state1->getX());
	
	cout << "Hello World!\n"; 
}
