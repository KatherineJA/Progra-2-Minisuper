#ifndef EMPAQUE_H
#define EMPAQUE_H
#include <iostream>
using namespace std;

class Empaque
{
private: 
	bool tripa; 
public:
	Empaque(bool); 
	Empaque(); 
	~Empaque(); 
	bool esDeTripa(bool tripa); 
};

#endif EMPAQUE_H