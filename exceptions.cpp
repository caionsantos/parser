#include "exceptions.hpp"
using namespace std;

InvalidOperation::InvalidOperation(string erro){
    this->erro = erro;
}

string InvalidOperation::what(){
    return "Operação com argumentos inválidos";
}

DivZero::DivZero(string erro){
    this->erro = erro;
}

string DivZero::what(){
    return "Divisão por zero";
}

Overflow::Overflow(string erro){
    this->erro = erro;
}

string Overflow::what(){
    return "Resultado não cabe em 64 bits";
}