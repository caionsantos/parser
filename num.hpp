#include <bits/stdc++.h>
#include "exp.hpp"
using namespace std;

class Num : Expression<long long int>{
    private:
        long long int valor;
    public:
        Num(string exp);
        inline long long int add(Expression e) override;
        inline long long int sub(Expression e) override;
        inline long long int mul(Expression e) override;
        inline long long int div(Expression e) override;
        inline bool maiorque(Expression e) override;
        inline bool igual(Expression e) override;
};