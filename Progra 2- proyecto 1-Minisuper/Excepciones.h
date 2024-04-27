#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H
#include <sstream>
#include <exception>
using namespace std;

class excepciones : public exception {
public:
    virtual const char* what() const throw () {
        return "Excepci�n general";
    }

};

class excpHilera : public excepciones {
public:
    virtual const char* what() const throw () {
        return "Excepci�n de digitacion";
    }

};
class ExcepcionCaracterInvalido : public excpHilera {
public:
    const char* what() const throw () {
        return "La entrada contiene caracteres no numericos.";
    }
};



class excpSimbolo : public excpHilera {
public:

    virtual const char* what() const throw () {
        return "La hilera contiene caracteres invalidos";
    }
};


#endif EXCEPCIONES_H

