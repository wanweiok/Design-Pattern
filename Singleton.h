#pragma once

#include "pch.h"

class Singleton
{
public:
	static Singleton* Instance();
protected:
	Singleton(){};
private:
	static Singleton* _instance;
};
