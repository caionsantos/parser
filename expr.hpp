#ifndef EXPR_H
#define EXPR_H
#include <bits/stdc++.h>
using namespace std;

class Expression{
    protected:
        bool tag;
        string exp;
    public:
        Expression(bool b);
        Expression(long long int l);
        inline string get_exp();
        inline bool is_bool();
        inline bool is_num();
        inline bool compativel(Expression e);
        inline long long int operator+(Expression e);
        inline long long int operator-(Expression e);
        inline long long int operator*(Expression e);
        inline long long int operator/(Expression e);
        inline bool operator==(Expression e);
        inline bool operator>(Expression e);
        inline bool operator&&(Expression e);
        inline bool operator||(Expression e);
        bool boolear();
};
#endif