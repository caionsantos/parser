#ifndef NUM_H
#define NUM_H
#include <bits/stdc++.h>
#include "expr.hpp"
using namespace std;

class Num : public Expression{
    public:
        Num(string exp);
        Num(long long int ll);
        // inline long long int add(Expression e) override;
        // inline long long int sub(Expression e) override;
        // inline long long int mul(Expression e) override;
        // inline long long int div(Expression e) override;
        // inline bool maiorque(Expression e) override;
        // inline bool igual(Expression e) override;
};
#endif