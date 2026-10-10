#include<iostream>
#include <memory>
using namespace std;
class Prototype{
    protected: 
    int data;
    public:
    virtual unique_ptr<Prototype> clone()const = 0;
    virtual void operation(int data)=0;
    virtual ~Prototype()=default;
};
class ConcretePrototype: public Prototype{
    public:
    void operation(int data) override{
        this->data = data;
        cout<<"data: "<<data<<endl;
    }
    unique_ptr<Prototype> clone() const override{
        return make_unique<ConcretePrototype>(*this);
    }
};
int main(){
    unique_ptr<Prototype>original=make_unique<ConcretePrototype>();
    unique_ptr<Prototype>copy=original->clone();
    original->operation(30);
    copy->operation(20);
}