#include<iostream>
#include <string>
using namespace std;
class Colleague;
class Mediator{
    public:
    virtual void send(Colleague * sender , string msg)=0;
    virtual ~Mediator()=default;
};
class Colleague{
    protected:
    Mediator * mediator;
    public:
    Colleague(Mediator*mediator):mediator(mediator){}
    virtual void send(string msg)=0;
    virtual void recieve(string msg)=0;
    virtual ~Colleague()=default;
};
class Colleague1: public Colleague{
    public:
    Colleague1(Mediator*mediator):Colleague(mediator){}
    void send(string msg) override{
        mediator->send(this, msg);
    }
    void recieve(string msg) override{
        cout<<"message recieved for colleague 1: "<<msg<<endl;
    }
};class Colleague2: public Colleague{
    public:
    Colleague2(Mediator*mediator):Colleague(mediator){}
    void send(string msg) override{
        mediator->send(this, msg);
    }
    void recieve(string msg) override{
        cout<<"message recieved for colleague 2: "<<msg<<endl;
    }
};

class Colleague3: public Colleague{
    public:
    Colleague3(Mediator*mediator):Colleague(mediator){}
    void send(string msg) override{
        mediator->send(this, msg);
    }
    void recieve(string msg) override{
        cout<<"message recieved for colleague 3: "<<msg<<endl;
    }
};
class concreteMediator:public Mediator{
    Colleague1 *c1;
    Colleague2 *c2;
    Colleague3 *c3;
    public:
    void setColleague(Colleague1* c1 , Colleague2 *c2,Colleague3*c3){
        this->c1 = c1;
        this->c2 = c2;
        this->c3 = c3;
    }
    void send(Colleague *sender, string msg) override{
        if(sender == c1){
            c2->recieve(msg);
            c3->recieve(msg);
        }
        else if(sender == c2){
            c1->recieve(msg);
            c3->recieve(msg);
        }
        else if(sender == c3){
            c1->recieve(msg);
            c2->recieve(msg);
        }
        
    }
};
int main(){
    concreteMediator mediator;
    Colleague1 c1(&mediator);
    Colleague2 c2(&mediator);
    Colleague3 c3(&mediator);
    mediator.setColleague(&c1,&c2,&c3);
    mediator.send(&c1, "hello c2 and c3");
    mediator.send(&c2, "recieved msg c1 , hello c1 and c3");
    mediator.send(&c3, "hello all");
}