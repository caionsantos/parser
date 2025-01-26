#ifndef PARSER_H
#define PARSER_H
#include "expr.hpp"
#include <string>
#include <variant>
using namespace std;

class Parser{
    public:
        Expression parse();
        void init_token();
        Parser();
        ~Parser();
    private:
        string token;
        void next_token();
        bool is_mult_safe(Expression e1, Expression e2);
        bool is_add_safe(Expression e1, Expression e2);
        variant<long long int, bool> read(string s);
        Expression parse_or();
        Expression parse_and();
        Expression parse_eq();
        Expression parse_rel();
        Expression parse_add();
        Expression parse_mul();
        Expression parse_unary();
        Expression parse_primary();
        Expression parse_lit();
};
#endif