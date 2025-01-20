#include <bits/stdc++.h>
#include "num.hpp"
using namespace std;

Num::Num(string exp){
    this->tag = false;
    this->valor = stoll(exp);
}

inline bool Num::igual(Expression e){
    return (e.get_valor() == this->valor);
}

inline bool Num::maiorque(Expression e){
    return (this->valor > e.get_valor());
}

inline long long int Num::add(Expression e){
    return (this->valor + e.get_valor());
}

inline long long int Num::sub(Expression e){
    return (this->valor - e.get_valor());
}

inline long long int Num::mul(Expression e){
    return (this->valor * e.get_valor());
}

inline long long int Num::div(Expression e){
    return (this->valor/e.get_valor());
}