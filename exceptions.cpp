#include "exceptions.hpp"
using namespace std;

InvalidOperation::InvalidOperation(string erro){
    this->erro = erro;
}

string InvalidOperation::what(){
    return this->erro;
}

DivZero::DivZero(string erro){
    this->erro = erro;
}

string DivZero::what(){
    return this->erro;
}

Overflow::Overflow(string erro){
    this->erro = erro;
}

string Overflow::what(){
    return this->erro;
}