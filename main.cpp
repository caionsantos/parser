#include <bits/stdc++.h>
#include "parser.cpp"
#include "expr.cpp"
#include <stdexcept>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        Parser p = Parser();
        try{
            cout << p.parse().get_exp() << endl;
        } catch (invalid_argument){
            cout << "error" << endl;
        }
    }

    return 0;
}