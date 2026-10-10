#include<iostream>
#include <memory>
using namespace std;
class Middleware{
    public:
    virtual void operation()=0;
    virtual ~Middleware()= default;
};
class Logging: public Middleware{
    public:
    void operation() override{
        cout<<"Logger enabled for middleware"<<endl;
    }
};
class MiddlewareElements: public Middleware{
    protected:
    unique_ptr<Middleware>elements;
    public:
    MiddlewareElements(unique_ptr<Middleware>elements):elements(move(elements)){}
    virtual ~MiddlewareElements() = default;
};
class Authentication: public MiddlewareElements{
    public:
    Authentication(unique_ptr<Middleware>elements):MiddlewareElements(move(elements)){}
    void operation() override{
        elements->operation();
        cout<<"added authenticator for middleware"<<endl;
    } 
};
class Authorization: public MiddlewareElements{
    public:
    Authorization(unique_ptr<Middleware>elements):MiddlewareElements(move(elements)){}
    void operation() override{
        elements->operation();
        cout<<"added authorization for middleware"<<endl;
    }
};
class RateLimiter : public MiddlewareElements{
    public:
    RateLimiter(unique_ptr<Middleware>elements):MiddlewareElements(move(elements)){}
    void operation() override{
        elements->operation();
        cout<<"added rate limiter for middleware"<<endl;
    }
};
int main(){
    unique_ptr<Middleware>performOperations = make_unique<Logging>();
    performOperations= make_unique<Authentication>(move(performOperations));
    performOperations= make_unique<Authorization>(move(performOperations));
    performOperations = make_unique<RateLimiter>(move(performOperations));
    performOperations->operation();
}