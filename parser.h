#include <bits/stdc++.h>
using namespace std;

class Parser{
    private:
        int token;
        string exp;

        void parse_original();

    public:
        Parser(string expr);

};