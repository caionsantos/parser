#include <bits/stdc++.h>
#include "exp.hpp"
using namespace std;

class Log : Expression<bool>{
    private:
        bool valor;
    public:
        Log(string exp);
        inline bool ou(Expression e) override;
        inline bool e(Expression e) override;
        inline bool igual(Expression e) override;
};