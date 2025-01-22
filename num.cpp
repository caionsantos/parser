#include <bits/stdc++.h>
#include "num.hpp"
using namespace std;

Num::Num(string exp){
    this->tag = false;
    this->exp = exp;
}

Num::Num(long long int n){
    this->tag = false;
    this->exp = to_string(n);
}

// inline bool Num::igual(Expression e){
//     return (stoll(e.get_exp()) == stoll(this->exp));
// }

// inline bool Num::maiorque(Expression e){
//     return (stoll(this->exp) > stoll(e.get_exp()));
// }

// inline long long int Num::add(Expression e){
//     return (stoll(this->exp) + stoll(e.get_exp()));
// }

// inline long long int Num::sub(Expression e){
//     return (stoll(this->exp) - stoll(e.get_exp()));
// }

// inline long long int Num::mul(Expression e){
//     return (stoll(this->exp) * stoll(e.get_exp()));
// }

// inline long long int Num::div(Expression e){
//     return (stoll(this->exp)/stoll(e.get_exp()));
// }