/*
    Decorator

    Description:
    Decorator is also known as Wrapper,
    in a sense it can wrap data or another wrapper which wraps data or etc.
    Decorator, or Wrapper, can decorate the pre-existing behavior at runtime (Decoration of the behavior).

*/
#include <iostream>
using namespace std;

// Component is an interface for both ConcreteComponents and Decorators.
class Component {
    public:
     virtual string Operation() = 0;
};

// ConcreteComponent is the default implementation of the operation.
class ConcreteComponent : public Component {
    public:
     string Operation() { return "ConcreteComponent"; }
};

class Decorator : public Component {
    protected:
     Component* component;

     public:
      Decorator(Component* _component) : component(_component){};

      string Operation() { return this->component->Operation(); }
};

class ConcreteDecoratorA : public Decorator {
    public:
     ConcreteDecoratorA(Component* _component) : Decorator(_component){};
     string Operation() { return "ConcreteDecoratorA(" + Decorator::Operation() + ")"; }
};

class ConcreteDecoratorB : public Decorator {
    public:
     ConcreteDecoratorB(Component* _component) : Decorator(_component){};
     string Operation() { return "ConcreteDecoratorB(" + Decorator::Operation() + ")"; }
};

int main(void) {
    // Default behavior to be decorated
    Component* default_behavior = new ConcreteComponent();
    cout << default_behavior->Operation() << endl;

    // Decorations on the default behavior
    Component* decoratorA_default = new ConcreteDecoratorA(default_behavior);
    Component* decoratorB_default = new ConcreteDecoratorB(default_behavior);
    cout << decoratorA_default->Operation() << endl;
    cout << decoratorB_default->Operation() << endl;

    // Decoration on the decoration which wraps the default behavior
    Component* decoratorB_decorated_default = new ConcreteDecoratorB(decoratorA_default);
    cout << decoratorB_decorated_default->Operation() << endl;

    delete decoratorB_decorated_default;
    delete decoratorB_default;
    delete decoratorA_default;
    delete default_behavior;

    return 0;
}