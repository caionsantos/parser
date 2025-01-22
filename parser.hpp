#ifndef PARSER_H
#define PARSER_H
#include <bits/stdc++.h>
#include "expr.hpp"
#include "num.hpp"
#include "log.hpp"
using namespace std;

class Parser{
    public:
        Expression parse();
        void init_token();
        Parser() = default;
    private:
        string original;
        string token;
        void next_token();
        variant<long long int, bool> read(string s);
        Expression parse_or();
        Expression parse_and(Expression e1);
        Expression parse_eq(Expression e1);
        Expression parse_rel(Expression e1);
        Expression parse_add(Expression e1);
        Expression parse_mul(Expression e1);
        Expression parse_unary(Expression e1); //lembrar
        Expression parse_Expressionary(Expression e1);
        Expression parse_lit();
};
#endif