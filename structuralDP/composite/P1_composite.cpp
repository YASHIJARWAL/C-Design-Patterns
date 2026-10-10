#include <cstdio>
#include<iostream>
#include <memory>
#include <algorithm>
#include <vector>
using namespace std;
class Component{
    public:
    virtual void operation()=0;
    virtual ~Component()=default;
};
class Leaf: public Component{
    public:
    void operation() override{
        cout<<"this is a leaf branch"<<endl;
    }
};
class Composite: public Component{
    vector<shared_ptr<Component>>children;
    public:
    void operation() override{
        for (auto &c: children){
            c->operation();
        }
    }
    void add(shared_ptr<Component>c){
        children.push_back(c);
    }
    void deleteEl(shared_ptr<Component>component){
        children.erase(remove(children.begin(),children.end(),component),children.end());
    }
};
int main(){
    auto folder=make_shared<Composite>();
    auto file1 = make_shared<Leaf>();
    auto file2=make_shared<Leaf>();
    auto file3 = make_shared<Leaf>();
    auto folder2=make_shared<Composite>();
    folder2->add(file3);
    folder->add(file1);
    folder->add(file2);
    folder->add(folder2);
    folder->operation();
}