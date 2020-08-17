/*
    Command

    Description:
    Command creates command as object with the defined parameters.

*/
#include <iostream>
using namespace std;

class Command {
    public:
     virtual void Execution() = 0;
};

class SimpleCommand : public Command {
    private:
     string str;

    public:
     SimpleCommand(string _str) : str(_str){};
     void Execution() { cout << "SimpleCommand: " << this->str << endl; }
};

class Receiver {
    private:
     int val;

     public:
      Receiver(int _val) : val(_val){};
      void SetVal(int _val) { this->val = _val; }
      int GetVal() { return val; }
};

class CalcFactorial : public Command {
    private:
     Receiver* receiver;
     int Fac(int n) { return n < 2 ? 1 : n * Fac(n - 1); }

    public:
     CalcFactorial(Receiver* _receiver)
         : receiver(_receiver){};
     void Execution() { this->receiver->SetVal(Fac(this->receiver->GetVal())); }
};

int main(void) {
    Command* command1 = new SimpleCommand("foo");
    Command* command2 = new SimpleCommand("bar");
    command1->Execution();
    command2->Execution();

    Receiver* receiver = new Receiver(3);
    Command* command3 = new CalcFactorial(receiver);
    command3->Execution();
    cout << receiver->GetVal() << endl;

    return 0;
}