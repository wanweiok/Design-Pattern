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

int main()
{
	Singleton* test1 = Singleton::Instance();
	Singleton* test2 = Singleton::Instance();
	assert(test1 == test2);
	cout << "Hello World!\n"; 
}
