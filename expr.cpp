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

bool Expression::boolear(){
    if(exp == "true"){
        return true;
    } else{
        return false;
    }
}