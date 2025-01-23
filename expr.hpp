#ifndef EXPR_H
#define EXPR_H
#include <bits/stdc++.h>
using namespace std;

class Expression{
    protected:
        bool tag;
        string exp;
    public:
        inline string get_exp(){
            return exp;
        }
        inline bool get_tag(){
            return tag;
        }
        inline bool compativel(Expression e){
            return (e.tag == this->tag);
        }
        inline long long int add(Expression e);
        inline long long int sub(Expression e);
        inline long long int mul(Expression e);
        inline long long int div(Expression e);
        inline bool igual(Expression e);
        inline bool maiorque(Expression e);
        inline bool e(Expression e);
        inline bool ou(Expression e);
        bool boolear();
};
#endif