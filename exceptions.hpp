#ifndef EXC_H
#define EXC_H
#include <string>
using namespace std;

class Exception{
    protected:
        string erro;
    public:
        virtual string what()=0;
};

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