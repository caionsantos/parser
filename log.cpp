#include <bits/stdc++.h>
#include "log.hpp"
using namespace std;

Log::Log(string exp){
    this->tag = true;
    this->exp = exp;
}

Log::Log(bool b){
    this->tag = true;
    if(b){
        this->exp = "true";
    } else{
        this->exp = "false";
    }
}

// bool Log::boolear(){
//     if(exp == "true"){
//         return true;
//     } else{
//         return false;
//     }
// }

// inline bool Log::e(Expression e){
//     return(e.boolear() & this->boolear());
// }

// inline bool Log::ou(Expression e){
//     return(e.boolear() == this->boolear());
// }

// inline bool Log::igual(Expression e){
//     return(e.boolear() == this->boolear());
// }