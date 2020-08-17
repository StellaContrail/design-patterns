/*
    Singleton (Thread-Safe)

    Description:
    Singleton class cannot be instantiated more than once.
    It always exist as the only one.

*/
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class Singleton {
   protected:
    string value;
    // Singleton class has a Singleton object itself.
    static Singleton* _singleton;
    // Use mutex to lock for mutual exclusion processing
    static mutex _mutex;
    // Constructor should be private.
    Singleton(string _value) : value(_value) {}

   public:
    // Singleton class cannot be cloned.
    Singleton(Singleton&) = delete;
    // Singleton class cannot be assigned.
    void operator=(const Singleton&) = delete;

    // Singleton instance is always created throught this method.
    static Singleton* Create(string value) {
        {
            lock_guard<mutex> lock(_mutex);
            if (_singleton == nullptr) {
                _singleton = new Singleton(value);
            }
        }
        return _singleton;
    }

    void Show() { cout << value << endl; }
};
Singleton* Singleton::_singleton{nullptr};
mutex Singleton::_mutex;

void Thread(string str) {
    this_thread::sleep_for(chrono::milliseconds(10));
    Singleton* singleton = Singleton::Create(str);
    singleton->Show();
}

int main(void) {
    thread t1(Thread, "Hello");
    thread t2(Thread, "World");
    t1.join();
    t2.join();

    return 0;
}