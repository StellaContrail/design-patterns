/*
    Strategy

    Description:
    Strategy pattern enables clients to alter the behavior of an object.

    Note:
    The difference between Strategy and State is independency of each
   State/Strategy.

*/
#include <iostream>
using namespace std;

class Strategy {
   public:
    virtual string Execution() = 0;
};

class Context {
   private:
    Strategy* strategy;

   public:
    Context(Strategy* _strategy) : strategy(_strategy){};
    void SetStrategy(Strategy* _strategy) {
        delete strategy;
        strategy = _strategy;
    }
    void Request() { cout << strategy->Execution() << endl; }
};

class ConcreteStrategyA : public Strategy {
   public:
    string Execution() { return "StrategyA "; }
};

class ConcreteStrategyB : public Strategy {
   public:
    string Execution() { return "StrategyB "; }
};

int main(void) {
    Context* context = new Context(new ConcreteStrategyA);
    context->Request();

    context = new Context(new ConcreteStrategyB);
    context->Request();

    delete context;
    return 0;
}