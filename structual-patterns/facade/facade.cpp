/*
    Facade

    Description:
    Facade provides an interface to use external library or framework easily.

*/
#include <iostream>
using namespace std;

// Sample Library
class Library {
    private:
     int a;
     int b;
     int result;

    public:
     void SetVals(int _a, int _b) { 
         a = _a;
         b = _b;
     }
     void Mult() { result = a * b; }
     int GetResult() { return result; }
};

// Facade provides easy access from the client to the library.
// Facade has the responsibility for managing the lifecycle, and delegation.
class Facade {
    protected:
     Library* library;

     public:
      Facade(Library* _library = nullptr) {
          this->library = _library ?: new Library();
      }

      int Calc(int a, int b) { 
        library->SetVals(a, b);
        library->Mult();
        return library->GetResult();
    }
};

int main(void) {
    Facade* facade = new Facade();
    cout << facade->Calc(2, 5) << endl;

    return 0;
}