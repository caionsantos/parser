#include "expr.hpp"
using namespace std;

Expression::Expression(bool b){
    this->tag = true;
    if(b){
        this->exp = "true";
    } else{
        this->exp = "false";
    }
}

//a sobrecarga do construtor permite saber quando a expressão é 
//de um número ou de um booleano e colocar a tag apropriada
//para checar a compatibilidade nas operações

Expression::Expression(long long int l){
    this->tag = false;
    this->exp = to_string(l);
}

bool Expression::boolear(){
    if(exp == "true"){
        return true;
    } else{
        return false;
    }
}