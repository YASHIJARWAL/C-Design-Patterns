#include<iostream>
using namespace std;

struct EmpDetails{
    int ip;
    string role;
    string token;
    int reqCount;
};

class Handler{
    protected:
    Handler* nextHandler;
    public:
    Handler():nextHandler(nullptr){}
    virtual void setNext(Handler *nextHandler)=0;
    virtual void handleRequest(EmpDetails emp)=0;
    virtual ~Handler()=default;
};

class LoggerHandler : public Handler{
    public:
    void setNext(Handler *nextHandler) override{
        this->nextHandler=nextHandler;
    }
    void logUser(EmpDetails emp){
        if(!emp.ip||emp.token.empty()){
            cout<<"Logger failed coming out of middleware"<<endl;
        }
        else{
            cout<<"User Logged with ip: "<<emp.ip<<" and token provided"<<endl;
            if(nextHandler !=nullptr){
                nextHandler->handleRequest(emp);
            }
        }
    }
    void handleRequest(EmpDetails emp) override{
        logUser(emp);
    }
};
class AuthHandler:public Handler{
    public:
    void setNext(Handler *nextHandler) override{
        this->nextHandler = nextHandler;
    }
    void authUser(EmpDetails emp){
        if(!emp.token.empty()){
            cout<<"Authentication successful"<<endl;
            if(nextHandler!=nullptr){
                nextHandler->handleRequest(emp);
            }
        }
        else{
            cout <<"authentication failed coming out of the middleware"<<endl;
        }
    }
    void handleRequest(EmpDetails emp) override{
        authUser(emp);
    }
};
class AuthorizeUser:public Handler{
    public:
    void setNext(Handler *nextHandler) override{
        this->nextHandler = nextHandler;
    }
    void authorizeUser(EmpDetails emp){
        if(!emp.role.empty()){
            cout<<"user is authorized to level of: "<<emp.role<<endl;
            if(nextHandler!=nullptr){
                nextHandler->handleRequest(emp);
            }
        }
        else{
            cout<<"authorization failed coming out of middleware"<<endl;
        }
    }
    void handleRequest(EmpDetails emp) override{
        authorizeUser(emp);
    }
};
class RateLimiter: public Handler{
    public:
    void setNext(Handler *nextHandler) override{
        this->nextHandler = nextHandler;
    }
    void rateLimits(EmpDetails emp){
        if(emp.reqCount!=0){
            cout<<"api counts not zero retries left: "<<emp.reqCount<<endl;
            if(nextHandler!=nullptr){
                nextHandler->handleRequest(emp);
            }
        }
        else{
            cout<<"rate limiter zero coming out of middleware"<<endl;
        }
    }
    void handleRequest(EmpDetails emp) override{
        rateLimits(emp);
    }
};
int main(){
    EmpDetails emp{1008 , "manager","addfjdodwjoefjsovj232ckxc",3};
    LoggerHandler log; 
    AuthHandler auth;
    AuthorizeUser authuser;
    RateLimiter ratelimit;
    log.setNext(&auth);
    auth.setNext(&authuser);
    authuser.setNext(&ratelimit);
    log.handleRequest(emp);
}