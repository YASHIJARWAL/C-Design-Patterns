#include<iostream>
#include <memory>
using namespace std;
class Component{
    public:
    virtual void operation()=0;
    virtual~Component()=default;
};
class ConcreteComponent: public Component{
    public:
    void operation() override{
        cout<<"performing operation on component"<<endl;
    }
};
class Decorator: public Component{
    protected:
    unique_ptr<Component>component;
    public:
    Decorator(unique_ptr<Component>component): component(move(component)){}
    virtual~Decorator()=default;
};
class Decorator1 : public Decorator{
    public:
    Decorator1(unique_ptr<Component>component):Decorator(move(component)){}
    void operation() override{
        component->operation();
        cout<<"performin operation on dec 1"<<endl;
    }
};
class Decorator2: public Decorator{
    public:
    Decorator2(unique_ptr<Component>component):Decorator(move(component)){}
    void operation() override{
        component->operation();
        cout<<"performin operation on dec 2"<<endl;
    }
};
int main(){
    unique_ptr<Component>comp = make_unique<ConcreteComponent>();
    comp = make_unique<Decorator1>(move(comp));
    comp = make_unique<Decorator2>(move(comp));
    comp->operation();
}