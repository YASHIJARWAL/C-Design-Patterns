#include <iostream>
#include <memory>
using namespace std;
class Implementation{
    public:
    virtual void implement()=0;
    virtual ~Implementation()=default;
};
class ConcreteImplementationA: public Implementation{
    public:
    void implement() override{
        cout<<"comcrete implementation A"<<endl;
    }
};

class ConcreteImplementationB: public Implementation{
    public:
    void implement() override{
        cout<<"comcrete implementation B"<<endl;
    }
};
class Abstraction{
    protected:
    unique_ptr<Implementation>implementation;
    public:
    Abstraction(unique_ptr<Implementation>implementation):implementation(move(implementation)){}
    virtual void operation(){
        implementation->implement();
    }
    virtual ~Abstraction()=default;
    
};
class RefinedAbstraction: public Abstraction{
    public:
    RefinedAbstraction(unique_ptr<Implementation>implementation):Abstraction(move(implementation)){}
    virtual void operation(){
        cout<<"refined abstraction"<<endl;
        implementation->implement();
    }
};
int main(){
    unique_ptr<Implementation>implementation = make_unique<ConcreteImplementationA>();
    unique_ptr<Abstraction>abstraction = make_unique<RefinedAbstraction>(move(implementation));
    
    abstraction->operation();
}