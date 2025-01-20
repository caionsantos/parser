#include <bits/stdc++.h>
using namespace std;

template <typename val>
class Expression{
    private:
        val valor;
    public:
        string exp;
        bool tag;
        virtual inline bool compativel(Expression e){
            return (e.tag == this->tag);
        }
        virtual inline val get_valor(){
            return this->valor;
        }
        virtual inline long long int add(Expression e);
        virtual inline long long int sub(Expression e);
        virtual inline long long int mul(Expression e);
        virtual inline long long int div(Expression e);
        virtual inline bool igual(Expression e);
        virtual inline bool maiorque(Expression e);
        virtual inline bool e(Expression e);
        virtual inline bool ou(Expression e);
};
