#include <bits/stdc++.h>
//#include "parser.h"
#include "num.cpp"
#include "log.cpp"
#include "parser.cpp"
#include "expr.cpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        Parser p = Parser();
        p.init_token();
        cout << p.parse().get_exp() << endl;
    }

    return 0;
}