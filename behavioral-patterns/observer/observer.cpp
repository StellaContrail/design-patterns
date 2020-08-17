/*
    Observer

    Description:
    Observer notifies objects about any events happen.

*/
#include <iostream>
#include <list>
using namespace std;

class IObserver {
    public:
     virtual void Update(string) = 0;
};

class ISubject {
    public:
     virtual void Attach(IObserver*) = 0;
     virtual void Detach(IObserver*) = 0;
     virtual void Notify() = 0;
};

class Subject : public ISubject {
    private:
     list<IObserver*> observers;
     string message;

    public:
     void Attach(IObserver* observer) { observers.push_back(observer); }
     void Detach(IObserver* observer) { observers.remove(observer); }
     void Notify() {
         cout << "Subject sent new messages to all the observers." << endl;
         for (auto observer : observers) {
             observer->Update(message);
         }
     }
     void CreateMessage(string _message) { 
         this->message = _message;
         Notify();
     }
     int HowManyObservers() { return observers.size(); }
};

class Observer : public IObserver {
    private:
     string new_message;
     Subject& subject;

    public:
     Observer(Subject& _subject) : subject(_subject){
         this->subject.Attach(this);
     };
     void Update(string _new_message) {
         new_message = _new_message;
         cout << "[New message for " << this << " ] " << new_message << endl;
     }
     void RemoveMeFromTheList() { subject.Detach(this); }
};

int main(void) {
    Subject* subject = new Subject;
    Observer* observer1 = new Observer(*subject);
    Observer* observer2 = new Observer(*subject);
    Observer* observer3 = new Observer(*subject);

    subject->CreateMessage("Hello, World!");

    subject->Detach(observer3);
    subject->CreateMessage("hogehoge");

    return 0;
}