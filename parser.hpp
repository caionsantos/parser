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
    private:
        string token;
        void next_token();
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