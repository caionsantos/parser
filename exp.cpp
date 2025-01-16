#include <bits/stdc++.h>
#include "exp.h"
using namespace std;

bool inline LogExp::e(LogExp e){
    return (this->valor and e.valor);
}

bool inline LogExp::ou(LogExp e){
    return (this->valor or e.valor);
}

bool inline LogExp::igual(LogExp e){
    return (this->valor == e.valor);
}

bool inline NumExp::igual(NumExp e){
    return (this->valor == e.valor);
}

bool inline NumExp::maiorque(NumExp e){
    return (this->valor > e.valor);
}

long long int inline NumExp::add(NumExp e){
    return (this->valor + e.valor);
}

long long int inline NumExp::sub(NumExp e){
    return (this->valor - e.valor);
}

long long int inline NumExp::mul(NumExp e){
    return (this->valor * e.valor);
}

long long int inline NumExp::div(NumExp e){
    return (this->valor / e.valor);
}