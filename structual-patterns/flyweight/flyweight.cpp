/*
    Flyweight

    Description:
    The Flyweight pattern provides a way to minimize memory size.
    The Flyweight class take care of the common characteristics of objects to
   save memory.

*/
#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;

class Flyweight {
   private:
    string name;

   public:
    Flyweight(string _name) : name(_name){};
    string GetVal() { return this->name; }
};

class FlyweightFactory {
   private:
    unordered_map<string, Flyweight> flyweights;

   public:
    Flyweight GetFlyweight(string name) {
        if (flyweights.find(name) == flyweights.end()) {
            flyweights.insert(pair<string, Flyweight>(name, Flyweight(name)));
        }
        return flyweights.at(name);
    }
    void ListFlyweights() {
        for (auto flyweight : flyweights) {
            cout << flyweight.second.GetVal() << endl;
        }
    }
};

int main(void) {
    FlyweightFactory* factory = new FlyweightFactory();
    factory->GetFlyweight("Jack");
    factory->GetFlyweight("Mike");
    factory->GetFlyweight("Kate");
    factory->GetFlyweight("Jack");
    factory->ListFlyweights();

    return 0;
}