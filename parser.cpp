#include <bits/stdc++.h>
#include "expr.hpp"
#include "parser.hpp"
using namespace std;

Expression Parser::parse(){
    return parse_or();
}

Parser::Parser(){
    init_token();
}

void Parser::init_token(){
    cin >> token;
}

void Parser::next_token(){
    if((cin.peek() != '\n') and (cin.peek() != '\0')){ 
        cin >> token;
    }
}

variant<long long int, bool> Parser::read(string s){
    if(s == "true"){
        return true;
    } else if(s == "false"){
        return false;
    } else{
        return stoll(s);
    }
}

Expression Parser::parse_or(){
    Expression e1 = parse_and();
    if(token == "||"){
        next_token();
        Expression e2 = parse_and();
        if(e1.compativel(e2) and e1.is_bool()){
            return Expression(e1 || e2);
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else{
        return e1;
    }
};

Expression Parser::parse_and(){
    Expression e1 = parse_eq();
    if(token == "&&"){
        next_token();
        Expression e2 = parse_eq();
        if(e1.compativel(e2) and e1.is_bool()){
            return Expression(e1 && e2);
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else{
        return e1;
    }
}

Expression Parser::parse_eq(){
    Expression e1 = parse_rel();
    if(token == "=="){
        next_token();
        Expression e2 = parse_rel();
        if(e1.compativel(e2)){
            return Expression(e1 == e2);
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else if(token == "!="){
        next_token();
        Expression e2 = parse_rel();
        if(e1.compativel(e2)){
            return Expression(!(e1 == e2));
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else{
        return e1;
    }
}

Expression Parser::parse_rel(){
    Expression e1 = parse_add();
    if(token == ">"){
        next_token();
        Expression e2 = parse_add();
        if(e1.compativel(e2) and e1.is_num()){
            return Expression(e1 > e2);
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else if(token == ">="){
        next_token();
        Expression e2 = parse_add();
        if(e1.compativel(e2) and e1.is_num()){
            return Expression((e1 == e2) or (e1 > e2));
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else if(token == "<"){
        next_token();
        Expression e2 = parse_add();
        if(e1.compativel(e2) and e1.is_num()){
            return Expression(!(e1 > e2));
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else if(token == "<="){
        next_token();
        Expression e2 = parse_add();
        if(e1.compativel(e2) and e1.is_num()){
            return Expression((e1 == e2) or !(e1 > e2));
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else{
        return e1;
    }
}

Expression Parser::parse_add(){
    Expression e1 = parse_mul();
    if(token == "+"){
        next_token();
        Expression e2 = parse_mul();
        if(e1.compativel(e2) and e1.is_num()){
            return Expression(e1 + e2);
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else if(token == "-"){
        next_token();
        Expression e2 = parse_mul();
        if(e1.compativel(e2) and e1.is_num()){
            return Expression(e1 - e2);
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else{
        return e1;
    }
}

Expression Parser::parse_mul(){
    Expression e1 = parse_unary();
    if(token == "*"){
        next_token();
        Expression e2 = parse_unary();
        if(e1.compativel(e2) and e1.is_num()){
            return Expression(e1 * e2);
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else if(token == "/"){
        next_token();
        Expression e2 = parse_unary();
        if(e1.compativel(e2) and e1.is_num()){
            if(e2.get_exp() != "0"){
                return Expression(e1/e2);
            } else{
                throw invalid_argument("divisão por zero");
            }
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else{
        return e1;
    }
}

Expression Parser::parse_unary(){
    if(token == "-"){
        next_token();
        Expression e1 = parse_primary();
        if(e1.is_num()){
            return Expression(-e1);
        } else{
            throw invalid_argument("conflito de tipos");
        }
    } else{
        Expression e1 = parse_primary();
        return e1;
    }
}

Expression Parser::parse_primary(){
    if(token == "("){
        next_token();
        Expression e1 = parse_or();
        next_token();
        return e1;
    } else{
        Expression e1 = parse_lit();
        return e1;
    }
}

Expression Parser::parse_lit(){
    variant<long long int, bool> n = read(token);
    next_token();
    if(bool *b = get_if<bool>(&n)){
        return Expression(*b);
    } else{
        long long int *l = get_if<long long int>(&n);
        return Expression(*l);
    }
};