/*
    Bridge

    Description:
    Bridge pattern consists of two parts, Abstraction and Implementation.
    The Abstraction is just a container of the Implementation.
    The Implementation takes care of the all actual work process, 
    while the Abstraction handles only the appearance or control of the application.

*/
#include <iostream>
using namespace std;

// Implementation Interface
class Implementation {
    public:
     virtual void method() = 0;
};

// Concrete Implementations are all primitive operations.
class ConcreteImplementation1 : public Implementation {
    public:
     void method() { cout << "ConcreteImplementation1" << endl; }
};

class ConcreteImplementation2 : public Implementation {
    public:
     void method() { cout << "ConcreteImplementation2" << endl; }
};

// Abstraction has a reference to an instance of the implementation, 
// and delegates all the work to the implementation instance.
class Abstraction {
   public:
    Implementation* implementation;
    Abstraction(Implementation* _implementation)
        : implementation(_implementation){};
    void feature() { cout << "Abstraction" << endl; }
};

class ExtendedAbstraction : public Abstraction {
    public:
     ExtendedAbstraction(Implementation* implementation)
         : Abstraction(implementation){};
     void extend_feature() { cout << "ExtendedAbstraction" << endl; }
};

int main(void) {
    Implementation* implementation1 = new ConcreteImplementation1();
    Implementation* implementation2 = new ConcreteImplementation2();

    Abstraction* control = new Abstraction(implementation1);
    ExtendedAbstraction* ex_control = new ExtendedAbstraction(implementation1);
    control->feature();
    control->implementation->method();

    cout << "\n";

    // Abstraction can have different implementation
    control = new Abstraction(implementation2);
    control->feature();
    control->implementation->method();

    cout << "\n";

    // Abstraction can be extended
    ex_control = new ExtendedAbstraction(implementation1);
    ex_control->feature();
    ex_control->extend_feature();
    ex_control->implementation->method();

    return 0;
}