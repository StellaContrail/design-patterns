/*
    Proxy

    Description:
    Proxy provides an temporary alternative of the real service.
    Proxy receives client requests and send it to the real service at the same time.

    Note:
    Proxy is similar to Facade in that the client access to the library through a class.
    Proxy and Target have same interface, although Facade doesn't.

*/
#include <iostream>
using namespace std;

class Target {
    public:
     virtual void Request() = 0;
};

class ConcreteTarget : public Target {
    public:
     void Request() { cout << "Request accepted by Target" << endl; }
};

class Proxy : public Target {
    private:
     ConcreteTarget* target;

    public:
     Proxy(ConcreteTarget* _target) : target(_target){};
     void Request() {
         cout << "Request accepted by Proxy" << endl;
         target->Request();
     }
};

int main(void) {
    ConcreteTarget* target = new ConcreteTarget();
    Proxy* proxy = new Proxy(target);
    proxy->Request();

    return 0;
}