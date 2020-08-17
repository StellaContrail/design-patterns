/*
    Visitor

    Description:
    Visiter can add new features to pre-existing code without changing the actual code.

*/
#include <iostream>
using namespace std;

class ConcreteAcceptorA;
class ConcreteAcceptorB;

// Visitor visits components to invoke their operations
class Visitor {
    public:
     virtual void Visit(ConcreteAcceptorA*) = 0;
     virtual void Visit(ConcreteAcceptorB*) = 0;
};

// Component accepts a visitor
class Acceptor {
    public:
     virtual void Accept(Visitor*) = 0;
};

class ConcreteAcceptorA : public Acceptor {
    public:
     void Accept(Visitor* visitor) { visitor->Visit(this); }
     string Show() { return "ConcreteAcceptorA"; }
};

class ConcreteAcceptorB : public Acceptor {
    public:
     void Accept(Visitor* visitor) { visitor->Visit(this); }
     string Show() { return "ConcreteAcceptorB"; }
};

class ConcreteVisitor1 : public Visitor {
    public:
     void Visit(ConcreteAcceptorA* component) {
         cout << "ConcreteVisitor1 visited " << component->Show() << endl;
     }
     void Visit(ConcreteAcceptorB* component) {
         cout << "ConcreteVisitor1 visited " << component->Show() << endl;
     }
};

class ConcreteVisitor2 : public Visitor {
    public:
     void Visit(ConcreteAcceptorA* component) {
         cout << "ConcreteVisitor2 visited " << component->Show() << endl;
     }
     void Visit(ConcreteAcceptorB* component) {
         cout << "ConcreteVisitor2 visited " << component->Show() << endl;
     }
};

int main(void) {
    ConcreteVisitor1* visitor1 = new ConcreteVisitor1;
    ConcreteVisitor2* visitor2 = new ConcreteVisitor2;
    ConcreteAcceptorA* acceptorA = new ConcreteAcceptorA;
    ConcreteAcceptorB* acceptorB = new ConcreteAcceptorB;

    // AcceptorA's behavior is extended by Visitor1/2
    acceptorA->Accept(visitor1);
    acceptorA->Accept(visitor2);

    cout << "\n";

    // AcceptorB's behavior is extended by Visitor1/2
    acceptorB->Accept(visitor1);
    acceptorB->Accept(visitor2);

    delete acceptorB;
    delete acceptorA;
    delete visitor2;
    delete visitor1;
    return 0;
}