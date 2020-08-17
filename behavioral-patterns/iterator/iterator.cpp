/*
    Iterator

    Description:
    Iterator provides a way to transverse the complex data structure.

*/
#include <iostream>
#include <vector>
using namespace std;

class Data {
   private:
    int val;

   public:
    Data(int _val) : val(_val) {}
    void Set(int _val) { val = _val; }
    int Get() { return val; }
};

// Iterator provides easy access to the iteratable collection
template <typename DATA_TYPE, typename CONTAINER_TYPE>
class Iterator {
   public:
    typedef typename vector<DATA_TYPE>::iterator ITR;
    ITR itr;
    CONTAINER_TYPE* container;

    Iterator(CONTAINER_TYPE* _container) { 
        container = _container;
        itr = container->data.begin();
     }
    void First() { itr = container->data.begin(); }
    void Next() { itr++; }
    bool IsDone() { return (itr == container->data.end()); }
    ITR Current() { return itr; }
};

template <class T>
class Container {
    friend class Iterator<T, Container>;

   private:
    vector<int> data;

   public:
    void Add(int item) { data.push_back(item); }
    Iterator<T, Container>* CreateIterator() { return new Iterator<T, Container>(this); }
};


int main(void) {
    Container<int> container;
    for (int i = 0; i < 10; i++) {
        container.Add(i);
    }

    Iterator<int, Container<int>>* itr = container.CreateIterator();
    for (itr->First(); !itr->IsDone(); itr->Next()) {
        cout << *(itr->Current()) << " ";
    }
    cout << endl;

    return 0;
}