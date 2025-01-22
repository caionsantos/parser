#ifndef LOG_H
#define LOG_H
#include <bits/stdc++.h>
#include "expr.hpp"
using namespace std;

class Log : public Expression{
    public:
        Log(string exp);
        Log(bool b);
        bool boolear();
        // inline bool ou(Expression e) override;
        // inline bool e(Expression e) override;
        // inline bool igual(Expression e) override;
};
#endif