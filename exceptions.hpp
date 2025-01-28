#ifndef EXC_H
#define EXC_H
#include <string>
using namespace std;

class Exception{
    protected:
        string erro;
    public:
        virtual string what()=0;
        inline string get_erro(){
            return this->erro;
        }
};

//a classe virtual Exception serve como base para as exceções
//que representam problemas específicos, permitindo tratamento
//generalizado na main, além de criar uma base que todas as classes
//de erro devem seguir.

class InvalidOperation : virtual public Exception{
    public:
        InvalidOperation(string erro);
        string what() override;
};

class DivZero : virtual public Exception{
    public:
        DivZero(string erro);
        string what() override;
};

class Overflow : virtual public Exception{
    public:
        Overflow(string erro);
        string what() override;
};

#endif