/*
    Adapter

    Description:
    Adapter converts one type of format to another type of format.

*/
#include <iostream>
using namespace std;

class IClient {
    public:
     virtual void Request() = 0;
};

class Service {
    public:
     int val;
     Service(int _val) : val(_val){};
     void Request() { cout << val << " kg" << endl; }
};

class Adapter : public IClient {
    private:
     Service* source;

    public:
     Adapter(Service* _source) : source(_source) {}
     ~Adapter() { source = nullptr; }
     int Convert() { return source->val * 1000; }

     void Request() { cout << Convert() << " g" << endl; }
};


int main(void) {
    Service* source = new Service(5);
    source->Request();

    Adapter* adapter = new Adapter(source);
    adapter->Request();

    delete adapter;
    delete source;

    return 0;
}