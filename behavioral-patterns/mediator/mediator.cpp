/*
    Mediator

    Description:


*/
#include <iostream>
#include <typeinfo>
using namespace std;

class Component;
class Mediator {
    public:
     virtual void Execute(Component*, string) = 0;
};

class Component {
    protected:
     Mediator* mediator;
     public:
      virtual void Send() = 0;
      void SetMediator(Mediator* _mediator) { this->mediator = _mediator; }
};

class ComponentA : public Component {
   public:
    void Send() { mediator->Execute(this, "CONNECT TO B"); }
};

class ComponentB : public Component {
     public:
      void Send() { mediator->Execute(this, "END"); }
};


class ConcreteMediator : public Mediator {
    private:
     ComponentA* componentA;
     ComponentB* componentB;

    public:
     ConcreteMediator(ComponentA* _componentA, ComponentB* _componentB)
         : componentA(_componentA), componentB(_componentB){
         this->componentA->SetMediator(this);
         this->componentB->SetMediator(this);
         };

     void Execute(Component* sender, string content) {
         if (typeid(*sender) == typeid(ComponentA)) {
             cout << "Mediator: ComponentA is executed. (" << content << ")" << endl;
             this->componentB->Send();
         }
         if (typeid(*sender) == typeid(ComponentB)) {
             cout << "Mediator: ComponentB is executed. (" << content << ")" << endl;
         }
     }
};

int main(void) {
    ComponentA* componentA = new ComponentA;
    ComponentB* componentB = new ComponentB;
    Mediator* mediator = new ConcreteMediator(componentA, componentB);

    componentA->Send();
    componentB->Send();

    return 0;
}