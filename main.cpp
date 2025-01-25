#include "parser.cpp"
#include "expr.cpp"
#include <stdexcept>
#include <string>
using namespace std;

int main() {
    
    int t;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++){
        Parser* p = new Parser();
        try{
            cout << p->parse().get_exp() << endl;
        } catch(invalid_argument){
            cout << "error" << endl;
        }
        delete p;
    }

    return 0;
}