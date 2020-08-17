/*
    State

    Description:
    State enables clients to alter the behavior inside an object depending on its state.

*/
#include <iostream>
using namespace std;

class Context;
class State {
    protected:
     Context* context;

     public:
      void SetContext(Context* _context) {
        context = _context;
      }
      virtual void Execution() = 0;
};

class Context {
    private:
     State* state;

     public:
      Context(State* _state) : state(_state) { TransitionTo(state); }
      void TransitionTo(State* _state) {
          state = _state;
          state->SetContext(this);
      }
      void Request() { state->Execution(); }
};

class ConcreteStateA : public State {
    public:
     void Execution();
};

class ConcreteStateB : public State {
    public:
     void Execution() { cout << "ConcreteStateB : Execution" << endl; }
};

void ConcreteStateA::Execution() {
    cout << "ConcreteStateA : Execution" << endl;
    this->context->TransitionTo(new ConcreteStateB);
}

int main(void) {
    Context* context = new Context(new ConcreteStateA);

    // Same method, Different Outcome
    context->Request();
    context->Request();

    return 0;
}