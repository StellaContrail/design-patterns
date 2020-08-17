/*
    Memento

    Description:
    Memento takes a snapshot of an object without exposing its state.

*/
#include <iostream>
#include <vector>
using namespace std;

class Memento {
   public:
    virtual string GetDate() = 0;
    virtual string GetState() = 0;
};

class ConcreteMemento : public Memento {
   private:
    string state;
    string date;

   public:
    ConcreteMemento(string _state) {
        this->state = _state;
        time_t now = time(0);
        this->date = ctime(&now);
    }
    string GetState() { return this->state; }
    string GetDate() { return this->date; }
};

class Originator {
   private:
    string state;

   public:
    Originator(string _state) : state(_state){};
    void DoSomething() { this->state += "=> EVENT "; }
    Memento* Duplicate() { return new ConcreteMemento(this->state); }
    void Restore(Memento* memento) { this->state = memento->GetState(); }
};

class Caretaker {
   private:
    vector<Memento*> mementos;
    Originator* originator;

   public:
    Caretaker(Originator* _originator) : originator(_originator){};
    // Add to the vector
    void Backup() { this->mementos.push_back(this->originator->Duplicate()); }
    // Remove from the vector
    void Undo() {
        if (!this->mementos.size()) {
            return;
        }
        Memento* memento = this->mementos.back();
        this->mementos.pop_back();
        this->originator->Restore(memento);
    }
    void ShowHistory() {
        for (auto memento : this->mementos) {
            cout << memento->GetDate();
            cout << "STATE: " << memento->GetState() << "\n";
        }
        cout << endl;
    }
};

int main(void) {
    Originator* originator = new Originator("TEST");
    Caretaker* caretaker = new Caretaker(originator);

    caretaker->Backup();
    caretaker->ShowHistory();

    originator->DoSomething();
    caretaker->Backup();

    originator->DoSomething();
    caretaker->Backup();

    caretaker->ShowHistory();

    caretaker->Undo();
    caretaker->Undo();

    caretaker->ShowHistory();

    return 0;
}