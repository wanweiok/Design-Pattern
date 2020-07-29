#pragma once

#include "pch.h"
#include <iostream>

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
