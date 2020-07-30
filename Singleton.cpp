#include <string>
#include <iostream>
#include <assert.h>

using namespace std;
class Singleton
{
public:
	static Singleton* Instance();
protected:
	Singleton() {};
private:
	static Singleton* _instance;
	
	class GC
	{
	public:
		GC() {
			cout << "GC construction" << endl;
		}
		~GC() {
			cout << "GC destruction" << endl;
			if (_instance != NULL)
			{
				delete _instance;
				_instance = NULL;
				cout << "Singleton destruction" << endl;
				system("pause");
			}
		}
	};

	static GC gc;
};

class Monostate {
public: 
	Monostate() {};
	void setX(int x) {
		itsX = x;
	}
	int getX() {
		return itsX;
	}

private:
	static int itsX;
};


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
