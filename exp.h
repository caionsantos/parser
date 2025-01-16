#include <bits/stdc++.h>
using namespace std;

class Expression{
    protected:
        virtual bool compativel(Expression e);
    public:
        Expression() = default;
        string exp;
        bool tag;
};

class LogExp : public Expression{
    protected:
        bool inline compativel(Expression e){
            return (this->tag == e.tag);
        };
    public:
        bool valor;
        LogExp(string exp){
            this->exp = exp;
            tag = false;
        }
        bool inline ou(LogExp e);
        bool inline e(LogExp e);
        bool inline igual(LogExp e);
};

class NumExp : public Expression{
    protected:
        bool inline compativel(Expression e){
            return (this->tag == e.tag);
        };
    public:
        long long int valor;
        NumExp(string exp){
            this->exp = exp;
            tag = true;
        }
        bool inline igual(NumExp e);
        bool inline maiorque(NumExp e);
        long long int inline add(NumExp e);
        long long int inline sub(NumExp e);
        long long int inline mul(NumExp e);
        long long int inline div(NumExp e);
};