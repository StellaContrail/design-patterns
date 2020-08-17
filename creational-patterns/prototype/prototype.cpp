/*
    Prototype

    Description:
    Create a copy of an object from another instance as a prototype.

*/
#include <iostream>
#include <unordered_map>
using namespace std;

enum Type { Type1, Type2 };

class Prototype {
   public:
    Prototype(){};
    ~Prototype(){};
    virtual Prototype* Clone() = 0;
    virtual void Show() = 0;
    virtual void Change(int) = 0;
};

class ConcretePrototype1 : public Prototype {
   public:
    int id;

   public:
    ConcretePrototype1(int _id) : id(_id){};
    ~ConcretePrototype1(){};
    void Show() { cout << id << endl; }
    void Change(int _id) { id = _id; }
    Prototype* Clone() { return new ConcretePrototype1(*this); }
};

int main() {
    // Create Prototypes
    Prototype* prototype1 = new ConcretePrototype1(1);
    Prototype* prototype2 = new ConcretePrototype1(2);
    // Create Copies from the Prototypes
    Prototype* prototype1_copy = prototype1->Clone();
    Prototype* prototype2_copy = prototype2->Clone();

    // Check if copies are successfully made
    cout << "Prototype Copies" << endl;
    prototype1_copy->Show();
    prototype2_copy->Show();

    // Check if the Copy is actually a copy from the prototype.
    prototype1_copy->Change(3);
    cout << "Changed ID of the Copy" << endl;
    prototype1->Show();
    prototype1_copy->Show();

    return 0; 
}