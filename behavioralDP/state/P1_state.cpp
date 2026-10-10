#include<iostream>
#include <memory>
using namespace std;
class State{
    public:
    virtual void operation()=0;
    virtual ~State()=default;
};
class State1: public State{
    public:
    void operation() override{
        cout<<"this is state 1"<<endl;
    }
};
class State2: public State{
    public:
    void operation() override{
        cout<<"this is state 2"<<endl;
    }
};
class Context{
    unique_ptr<State>stateChanger;
    public:
    Context(unique_ptr<State>state):stateChanger(move(state)){}
    void setState(unique_ptr<State>state){
        stateChanger=move(state);
    }
    void operate(){
        stateChanger->operation();
    }
};
int main(){
    Context context(make_unique<State1>());
    context.operate();
    context.setState(make_unique<State2>());
    context.operate();
}