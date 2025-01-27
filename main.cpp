#include "parser.cpp"
#include "expr.cpp"
#include "exceptions.cpp"
#include <string>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        Parser* p = new Parser();
        try{
            cout << p->parse().get_exp() << endl;
        } catch(const Exception& e){
            //tratamento das exceções previstas no código, derivadas de Exception
            cout << "error" << endl;
        } catch(...){
            cout << "erro não previsto" << endl;
        }
        delete p;
        //alocar o parser dinamicamente garante que não haverá vazamento
        //de memória para entradas grandes demais
    }

    return 0;
}