#include<iostream>
using namespace std;

class Handler{
    protected:
    Handler* nextHandler;
    public:
    Handler():nextHandler(nullptr){}
    virtual void setNext(Handler *handler)=0;
    virtual void handleRequest(int i)=0;
    virtual ~Handler()=default;
};
class HandlerA: public Handler{
    public:
    void setNext(Handler *handler) override{
        nextHandler=handler;
    }
    void handleRequest(int i) override{
        if(i==0){
            cout<<"the request is being handled by handle A"<<endl;
        }
        else if(nextHandler != nullptr){
            cout<<"request transferred"<<endl;
            nextHandler->handleRequest(i);
        }
    }  
};
class HandlerB: public Handler{
    public:
    void setNext(Handler *handler) override{
        nextHandler=handler;
    }
    void handleRequest(int i) override{
        if(i==1){
            cout<<"the request is being handled by handle B"<<endl;
        }
        else if(nextHandler!=nullptr){
            cout<<"request transferred"<<endl;
            nextHandler->handleRequest(i);
        }
    }
};
class HandlerC: public Handler{
    public:
    void setNext(Handler *handler) override{
        nextHandler=handler;
    }
    void handleRequest(int i) override{
        if(i==2){
            cout<<"the request is being handled by handle C"<<endl;
        }
        else if(nextHandler!=nullptr){
            cout<<"request failed"<<endl;
            
        }
    }
};
int main(){
    HandlerA a;
    HandlerB b;
    HandlerC c;
    a.setNext(&b);
    b.setNext(&c);
    c.setNext(nullptr);
    a.handleRequest(3);
    a.handleRequest(2);
    a.handleRequest(1);
    a.handleRequest(0);

}
