/*
    Name

    Description:


*/
#include <iostream>
using namespace std;

class Handler {
   public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual string Handle(string request) = 0;
};

class BaseHandler : public Handler {
   private:
    Handler* next;

   public:
    BaseHandler() : next(nullptr){};
    Handler* SetNext(Handler* handler) {
        this->next = handler;
        return handler;
    }
    string Handle(string request) {
        if (next != nullptr) {
            return this->next->Handle(request);
        } else {
            return request;
        }
    }
};

class ConcreteHandlerA : public BaseHandler {
   public:
    string Handle(string request) {
        if (request == "") {
            return request;
        } else {
            request += "A";
            return BaseHandler::Handle(request);
        }
    }
};

class ConcreteHandlerB : public BaseHandler {
   public:
    string Handle(string request) {
        if (request == "") {
            return request;
        } else {
            request += "B";
            return BaseHandler::Handle(request);
        }
    }
};

class ConcreteHandlerC : public BaseHandler {
   public:
    string Handle(string request) {
        if (request == "") {
            return request;
        } else {
            request += "C";
            return BaseHandler::Handle(request);
        }
    }
};

int main(void) {
    ConcreteHandlerA* ha = new ConcreteHandlerA;
    ConcreteHandlerB* hb = new ConcreteHandlerB;
    ConcreteHandlerC* hc = new ConcreteHandlerC;

    ha->SetNext(hb)->SetNext(hc);
    cout << ha->Handle("=>") << endl;

    ha->SetNext(hb)->SetNext(nullptr);
    cout << ha->Handle("=>") << endl;


    return 0;
}