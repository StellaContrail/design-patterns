/*
    Template Method

    Description:
    Template Method defines a skelton which later can be assigned by subclasses.
    Template Method can be used when the portion of the code is different
   amongst different operations.

*/
#include <iostream>
using namespace std;

class AbstractClass {
   protected:
    // Common operation
    void Operation1() { cout << "Operation1" << endl; }
    // Unique operation
    virtual void Operation2() = 0;
    // Common operation
    void Operation3() { cout << "Operation2" << endl; }

   public:
    void TemplateMethod() {
        Operation1();
        Operation2();
        Operation3();
    }
};

class ConcreteClassA : public AbstractClass {
   protected:
    void Operation2() {
        cout << "Operation2 replaced by ConcreteClassA" << endl;
    }
};

class ConcreteClassB : public AbstractClass {
   protected:
    void Operation2() {
        cout << "Operation2 replaced by ConcreteClassB" << endl;
    }
};

int main(void) {
    ConcreteClassA* concreteClassA = new ConcreteClassA();
    ConcreteClassB* concreteClassB = new ConcreteClassB();

    AbstractClass* abstractClass = concreteClassA;
    abstractClass->TemplateMethod();

    cout << "\n";

    abstractClass = concreteClassB;
    abstractClass->TemplateMethod();

    delete abstractClass;
    delete concreteClassB;
    delete concreteClassA;
    return 0;
}