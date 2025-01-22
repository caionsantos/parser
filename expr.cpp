#include <bits/stdc++.h>
#include "expr.hpp"
using namespace std;

inline bool Expression::igual(Expression e){
    return (stoll(e.get_exp()) == stoll(this->exp));
}

inline bool Expression::maiorque(Expression e){
    return (stoll(this->exp) > stoll(e.get_exp()));
}

inline long long int Expression::add(Expression e){
    return (stoll(this->exp) + stoll(e.get_exp()));
}

inline long long int Expression::sub(Expression e){
    return (stoll(this->exp) - stoll(e.get_exp()));
}

inline long long int Expression::mul(Expression e){
    return (stoll(this->exp) * stoll(e.get_exp()));
}

inline long long int Expression::div(Expression e){
    return (stoll(this->exp)/stoll(e.get_exp()));
}

bool Expression::boolear(){
    if(exp == "true"){
        return true;
    } else{
        return false;
    }
}

inline bool Expression::e(Expression e){
    return(e.boolear() & this->boolear());
}

inline bool Expression::ou(Expression e){
    return(e.boolear() || this->boolear());
}

inline bool Expression::igual(Expression e, bool t){
    return(e.boolear() == this->boolear());
}