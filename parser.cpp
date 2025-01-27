#include "expr.hpp"
#include "exceptions.hpp"
#include "parser.hpp"
#include <iostream>
#include <limits>
using namespace std;

Expression Parser::parse(){
    return parse_or();
}

Parser::Parser(){
    init_token();
}

Parser::~Parser(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //chamado quando o parser é deletado, esse destrutor ignora o resto
    //da expressão no caso de erro
}

void Parser::init_token(){
    cin >> token;
}

void Parser::next_token(){
    if((cin.peek() != '\n') and (cin.peek() != '\0')){ 
        cin >> token;
    }
}

bool Parser::is_mult_safe(Expression e1, Expression e2){
    if((e1.get_exp() == "0") or (e2.get_exp() == "0")){
        return true;
    } else{
        Expression a = e1 * e2;
        if((Expression(a/e1) == e2) and (Expression(a/e2) == e1)){
            return true;
        } else{
            return false;
        }
    }
}

bool Parser::is_add_safe(Expression e1, Expression e2){
    Expression check = e1 + e2;
    if((e1.get_exp()[0] == '-') and (e2.get_exp()[0] == '-')){
        //llongmin + llongmin = 0
        if(check.get_exp()[0] != '-'){
            return false;
        } else{
            return true;
        }
    } else if((e1.get_exp()[0] != '-') and (e2.get_exp()[0] != '-')){
        //llongmax + llongmax = -2
        if(check.get_exp()[0] == '-'){
            return false;
        } else{
            return true;
        }
    } else{
        return true;
    }
}

//o uso de variant, baseado em templates, permite a definição de
//um método único "read" ao invés de múltiplos para bools e ints
//melhorando a legibilidade e eficiência
variant<long long int, bool> Parser::read(string s){
    if(s == "true"){
        return true;
    } else if(s == "false"){
        return false;
    } else{
        try{
            return stoll(s);
        } catch(out_of_range){
            throw Overflow("número não cabe em 64 bits");
        }
    }
}

Expression Parser::parse_or(){
    //variáveis dentro das diversas funções do parser não são
    //alocadas dinamicamente pois elas já são apagadas pela stack
    //conforme as funções vão retornando
    Expression e1 = parse_and();
    if(token == "||"){
        next_token();
        Expression e2 = parse_and();
        if(e1.compativel(e2) and e1.is_bool()){
            return (e1 || e2);
            //compilador converterá o resultado (bool) em Expression
            //implicitamente
        } else{
            throw InvalidOperation("conflito de tipos");
        }
    } else{
        return e1;
    }
}

Expression Parser::parse_and(){
    Expression e1 = parse_eq();
    if(token == "&&"){
        next_token();
        Expression e2 = parse_eq();
        if(e1.compativel(e2) and e1.is_bool()){
            return (e1 && e2);
        } else{
            throw InvalidOperation("conflito de tipos");
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
            return (e1 == e2);
        } else{
            throw InvalidOperation("conflito de tipos");
        }
    } else if(token == "!="){
        next_token();
        Expression e2 = parse_rel();
        if(e1.compativel(e2)){
            return (!(e1 == e2));
        } else{
            throw InvalidOperation("conflito de tipos");
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
            return (e1 > e2);
        } else{
            throw InvalidOperation("conflito de tipos");
        }
    } else if(token == ">="){
        next_token();
        Expression e2 = parse_add();
        if(e1.compativel(e2) and e1.is_num()){
            return ((e1 == e2) or (e1 > e2));
        } else{
            throw InvalidOperation("conflito de tipos");
        }
    } else if(token == "<"){
        next_token();
        Expression e2 = parse_add();
        if(e1.compativel(e2) and e1.is_num()){
            return (!(e1 > e2) and !(e1 == e2));
        } else{
            throw InvalidOperation("conflito de tipos");
        }
    } else if(token == "<="){
        next_token();
        Expression e2 = parse_add();
        if(e1.compativel(e2) and e1.is_num()){
            return (!(e1 > e2));
        } else{
            throw InvalidOperation("conflito de tipos");
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
            if(is_add_safe(e1, e2)){
                return (e1 + e2);
            } else{
                throw Overflow("overflow");
            }
        } else{
            throw InvalidOperation("conflito de tipos");
        }
    } else if(token == "-"){
        next_token();
        Expression e2 = parse_mul();
        if(e1.compativel(e2) and e1.is_num()){
            if(is_add_safe(e1, -e2)){
                return (e1 - e2);
            } else{
                throw Overflow("overflow");
            }
        } else{
            throw InvalidOperation("conflito de tipos");
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
            if(is_mult_safe(e1, e2)){
                return (e1 * e2);
            } else{
                throw Overflow("overflow");
            }
        } else{
            throw InvalidOperation("conflito de tipos");
        }
    } else if(token == "/"){
        next_token();
        Expression e2 = parse_unary();
        if(e1.compativel(e2) and e1.is_num()){
            if(e2.get_exp() != "0"){
                return (e1/e2);
            } else{
                throw DivZero("divisão por zero");
            }
        } else{
            throw InvalidOperation("conflito de tipos");
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
            return (-e1);
        } else{
            throw InvalidOperation("conflito de tipos");
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