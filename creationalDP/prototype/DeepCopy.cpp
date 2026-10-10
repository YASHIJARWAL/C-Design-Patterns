#include<iostream>
#include <memory>
using namespace std;
class Prototype{
    public:
    virtual unique_ptr<Prototype> clone()const = 0;
    virtual void operation()=0;
    virtual ~Prototype()=default;
};
class ConcretePrototype: public Prototype{
    unique_ptr<int>data;
    public:
    ConcretePrototype(unique_ptr<int>val):data(move(val)){}
    void operation() override{
        cout<<"performed operation"<<endl;
        cout<<"data: "<<*data<<endl;
    }
    unique_ptr<Prototype> clone() const override{
        auto copy =make_unique<ConcretePrototype>(make_unique<int>(*data));
        return copy;
    }
};
int main(){
    unique_ptr<Prototype>original = make_unique<ConcretePrototype>(make_unique<int>(30));
    unique_ptr<Prototype>copy = original->clone();
    unique_ptr<Prototype>newCopy = copy->clone();
    copy->operation();
    newCopy->operation();
    original->operation();
}