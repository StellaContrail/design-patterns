/*
    Abstract Factory

    Description:
    Abstract Factory is a pattern which returns a factory object first.
    The factory object has factory method inside which returns
    an object of a subclass as abstract type.
    This pattern enables users to alter the factory itself.

*/

#include <iostream>
using namespace std;

class AbstractProductA {
    public:
     virtual void ProductAFunction() = 0;
};

class ConcreteProductA1 : public AbstractProductA {
    public:
     void ProductAFunction() { cout << "ConcreteProductA1" << endl; }
};
class ConcreteProductA2 : public AbstractProductA {
    public:
     void ProductAFunction() { cout << "ConcreteProductA2" << endl; }
};

class AbstractProductB {
    public:
     virtual void ProductBFunction() = 0;
};

class ConcreteProductB1 : public AbstractProductB {
    public:
     void ProductBFunction() { cout << "ConcreteProductB1" << endl; }
};
class ConcreteProductB2 : public AbstractProductB { 
    public:
     void ProductBFunction() { cout << "ConcreteProductB2" << endl; }
};

class AbstractFactory {
    public:
     virtual AbstractProductA* CreateProductA() = 0;
     virtual AbstractProductB* CreateProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
    public:
    AbstractProductA* CreateProductA() { return new ConcreteProductA1(); }
    AbstractProductB* CreateProductB() { return new ConcreteProductB1(); }
};
class ConcreteFactory2 : public AbstractFactory {
    public:
     AbstractProductA* CreateProductA() { return new ConcreteProductA2(); }
     AbstractProductB* CreateProductB() { return new ConcreteProductB2(); }
};

// main
int main(void) {
    AbstractFactory* factory = new ConcreteFactory1();

    // Access through the abstract classes
    auto ShowProducts = [](AbstractFactory& _factory) {
        AbstractProductA* productA = _factory.CreateProductA();
        AbstractProductB* productB = _factory.CreateProductB();
        productA->ProductAFunction();
        productB->ProductBFunction();
    };

    ShowProducts(*factory);

    return 0;
}