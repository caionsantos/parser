#include <bits/stdc++.h>
#include "log.hpp"
using namespace std;

Log::Log(string exp){
    this->tag = true;
    if(exp == "true"){
        this->valor = true;
    } else{
        this->valor = false;
    }
}

inline bool Log::e(Expression e){
    return(e.get_valor() & this->valor);
}

inline bool Log::ou(Expression e){
    return(e.get_valor() == this->valor);
}

inline bool Log::igual(Expression e){
    return(e.get_valor() == this->valor);
}