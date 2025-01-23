#include <bits/stdc++.h>
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

Expression::Expression(long long int l){
    this->tag = false;
    this->exp = to_string(l);
}

inline string Expression::get_exp(){
    return exp;
}

inline bool Expression::is_bool(){
    return tag;
}

inline bool Expression::is_num(){
    return !tag;
}

inline bool Expression::compativel(Expression e){
    return (e.tag == this->tag);
}

inline bool Expression::operator==(Expression e){
    return (e.exp == this->exp);
}

inline bool Expression::operator>(Expression e){
    return (stoll(this->exp) > stoll(e.get_exp()));
}

inline long long int Expression::operator+(Expression e){
    return (stoll(this->exp) + stoll(e.get_exp()));
}

inline long long int Expression::operator-(Expression e){
    return (stoll(this->exp) - stoll(e.get_exp()));
}

inline long long int Expression::operator*(Expression e){
    return (stoll(this->exp) * stoll(e.get_exp()));
}

inline long long int Expression::operator/(Expression e){
    return (stoll(this->exp)/stoll(e.get_exp()));
}

bool Expression::boolear(){
    if(exp == "true"){
        return true;
    } else{
        return false;
    }
}

inline bool Expression::operator&&(Expression e){
    return (e.boolear() && this->boolear());
}

inline bool Expression::operator||(Expression e){
    return (e.boolear() || this->boolear());
}