/*
    Composite

    Description:
    Composite provides the tree-like structure of objects.
    Execution method transverses all the leaves the tree has, and executes them recursively.

*/
#include <iostream>
#include <list>
using namespace std;

class Component {
   public:
    virtual void Add(Component*){};
    virtual void Remove(Component*){};
    virtual string Execute() = 0;
};

class Branch : public Component {
   protected:
    list<Component*> children;

   public:
    // Add another component to the children
    void Add(Component* component) { this->children.push_back(component); }
    // Remove the component from the children
    void Remove(Component* component) { this->children.remove(component); }
    // Execute all the work the children have.
    string Execute() {
        string result = "";
        for (auto child : children) {
            if (child == children.back()) {
                result += child->Execute();
            } else {
                result += child->Execute() + "+";
            }
        }
        return "Branch(" + result + ")";
    }
};

// Leaf object represents the end of the composition.
class Leaf : public Component {
   public:
    string Execute() { return "Leaf"; }
};

int main(void) {
    // Create tree-like structure
    Component* tree = new Branch();
    Component* branch1 = new Branch();
    Component* branch2 = new Branch();

    // Create leaves
    Component* leaf_1 = new Leaf();
    Component* leaf_2 = new Leaf();
    Component* leaf_3 = new Leaf();

    // Attach the leaves to the branch
    branch1->Add(leaf_1);
    branch1->Add(leaf_2);
    branch2->Add(leaf_3);

    // Attach branches to the tree
    tree->Add(branch1);
    tree->Add(branch2);

    // Execute all the leaves attached to the branch
    cout << branch1->Execute() << endl;
    cout << branch2->Execute() << endl;

    // Execute all the leaves attached to the tree
    cout << tree->Execute() << endl;

    return 0; 
}