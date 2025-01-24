#ifndef EXPR_H
#define EXPR_H
#include <bits/stdc++.h>
using namespace std;

class Expression{
    private:
        string exp;
    protected:
        bool tag;
    public:
        Expression(bool b);
        Expression(long long int l);
        inline string get_exp(){
            return this->exp;
        };
        inline bool is_bool(){
            return tag;
        };
        inline bool is_num(){
            return !(tag);
        };
        inline bool compativel(Expression e){
            return (e.tag == this->tag);
        };
        inline long long int operator+(Expression e){
            return (stoll(this->exp) + stoll(e.get_exp()));
        };
        inline long long int operator-(Expression e){
            return (stoll(this->exp) - stoll(e.get_exp()));
        };
        inline long long int operator-(){
            return (0 - stoll(this->exp));
        };
        inline long long int operator*(Expression e){
            return (stoll(this->exp) * stoll(e.get_exp()));
        };
        inline long long int operator/(Expression e){
            return (stoll(this->exp)/stoll(e.get_exp()));
        };
        inline bool operator==(Expression e){
            return (e.exp == this->exp);
        };
        inline bool operator>(Expression e){
            return (stoll(this->exp) > stoll(e.get_exp()));
        };
        inline bool operator&&(Expression e){
            return (e.boolear() && this->boolear());
        };
        inline bool operator||(Expression e){
            return (e.boolear() || this->boolear());
        };
        bool boolear();
};
#endif