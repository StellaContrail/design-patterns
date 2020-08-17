/*
    Factory Method

    Description:
    Provide a "Factory" class to implement the factory method.
    The factory method returns an object of a subclass as abstract type,
    which enables user to alter the object type easily.

*/

#include <iostream>
using namespace std;

class Product {
    public:
     Product(){};
     ~Product(){};
     virtual void Show() = 0;
};

class Product1 : public Product {
    public:
     void Show() { cout << "Product1" << endl; }
};
class Product2 : public Product {
    public:
     void Show() { cout << "Product2" << endl; }
};


// The Creator class declares the factory method that is supposed to return an object of a Product class.
class Creator {
   public:
    Creator(){};
    ~Creator(){};
    // The factory method
    virtual Product* CreateProduct() = 0;
};

class ConcreteCreator1 : public Creator {
    public:
     Product* CreateProduct() { return new Product1(); }
};
class ConcreteCreator2 : public Creator {
    public:
     Product* CreateProduct() { return new Product2(); }
};

int main() {
    Creator* creator = new ConcreteCreator1();
    Product* product = creator->CreateProduct();
    // Access through the abstract Factory and Product class
    product->Show();

    creator = new ConcreteCreator2();
    product = creator->CreateProduct();
    product->Show();

    return 0;
}