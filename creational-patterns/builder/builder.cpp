/*
    Builder

    Description:
    Build an object from various small objects

*/
#include <iostream>
#include <vector>
using namespace std;

/*
    Example:
    Builds a product with parts made for Product A.
    The Builder produces parts.
    The Director commands the Builders to build a specific type of Product.
    The Product, which is supposed to be a final result, is not related with each other,
    since they are consist of different parts in principle.
*/

// Product can be consist of any parts a.k.a unrelated products.
class Product {
    public:
    vector<string> parts;
    void Show() {
        for (auto part : parts) {
            cout << part << endl;
        }
        cout << endl;
    }
};

// Builder builds a product with unrelated parts.
class Builder {
    public:
     virtual void ProducePartA() = 0;
     virtual void ProducePartB() = 0;
     virtual void ProducePartC() = 0;
};

// Concrete Builder for the Product A.
class ConcreteBuilderA : public Builder {
    // Builder has the product pointer to work with, but temporary.
    Product* product;
    public:
    // Concrete Builder should be initialized when loaded.
     ConcreteBuilderA() { this->Init(); }
     ~ConcreteBuilderA() { delete product; }
     void Init() { this->product = new Product(); }

     void ProducePartA() { this->product->parts.push_back("ConcreteBuilderA : PartA"); }
     void ProducePartB() { this->product->parts.push_back("ConcreteBuilderA : PartB"); }
     void ProducePartC() { this->product->parts.push_back("ConcreteBuilderA : PartC"); }

    // After building is over, the product pointer should be released from this instance.
     Product* GetProduct() { 
        Product* result = this->product;
        Init();
        return result;
     }
};

// Director defines the order or the list of building process.
// However, since the concept is not violated even when Builder has the building process,
// this Director class is optional.
class Director {
    Builder* builder;
    public:
    void SetBuilder(Builder& _builder) { this->builder = &_builder; }

    void BuildWithOnlyPartA() { builder->ProducePartA(); }
    void BuilderWithAllParts() { 
        builder->ProducePartA();
        builder->ProducePartB();
        builder->ProducePartC();
    }
};

int main(void) {
    Director* director = new Director();

    auto BuildA = [](Director* _director){
        ConcreteBuilderA* builder = new ConcreteBuilderA();
        _director->SetBuilder(*builder);
        _director->BuilderWithAllParts();
        Product* product = builder->GetProduct();
        product->Show();
    };

    BuildA(director);

    return 0;
}