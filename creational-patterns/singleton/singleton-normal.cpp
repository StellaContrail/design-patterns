/*
    Singleton
    
    Description:
    Singleton class cannot be instantiated more than once.
    It always exist as the only one.
    
    Note:
    This implementation of Singleton is not thread-safe.
    You can create two Singletons at the same time with using different threads.

*/
#include <iostream>
using namespace std;

class Singleton {
    protected:
     string value;
     // Singleton class has a Singleton object itself.
     static Singleton* _singleton;
     // Constructor should be private.
     Singleton(string _value) : value(_value) { }

    public:
     // Singleton class cannot be cloned.
     Singleton(Singleton&) = delete;
     // Singleton class cannot be assigned.
     void operator=(const Singleton&) = delete;

     // Singleton instance is always created throught this method.
     static Singleton* Create(string value) {
         if (_singleton == nullptr) {
             _singleton = new Singleton(value);
         }
         return _singleton;
      }

      void Show() { cout << value << endl; }
};
Singleton* Singleton::_singleton{nullptr};

int main(void) {
    // Create an instance as Singleton.
    Singleton* singleton = Singleton::Create("Hello");
    singleton->Show();
    // Instances cannot be created more than once.
    Singleton* singleton2 = Singleton::Create("World");
    singleton2->Show();

    return 0;
    }