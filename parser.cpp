#include <bits/stdc++.h>
#include "expr.hpp"
#include "num.hpp"
#include "log.hpp"
#include "parser.hpp"
#include <stdexcept>
#include <variant>
using namespace std;

// Parser::Parser(string exp){
//     original = exp;
// };

Expression Parser::parse(){
    return parse_or();
}

void Parser::init_token(){
    cin >> token;
}

void Parser::next_token(){
    if((cin.peek() != '\n') & (cin.peek() != '\0')){ 
        cin >> token;
    } else{
        cin.ignore();
    }
}

variant<long long int, bool> Parser::read(string s){
    if(s == "true"){
        return true;
    } else if(s == "false"){
        return false;
    } else{
        if(s[0] == '-'){
            return -(stoll(s));
        } else{
            return stoll(s);
        }
    }
}

Expression Parser::parse_or(){
    Expression e1 = parse_lit();
    if(token == "||"){
        next_token();
        Expression e2 = parse_lit();
        if(e1.compativel(e2)){
            return Log(e1.ou(e2));
        } else{
            throw invalid_argument("error");
        }
    } else{
        return e1;
    }
};

Expression Parser::parse_lit(){
    variant<long long int, bool> n = read(token);
    next_token();
    if(bool *b = get_if<bool>(&n)){
        return Log(*b);
    } else{
        long long int *l = get_if<long long int>(&n);
        return Num(*l);
    }
};