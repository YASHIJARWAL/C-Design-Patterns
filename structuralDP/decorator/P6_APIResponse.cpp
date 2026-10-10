#include<iostream>
#include <memory>
using namespace std;
class Component{
    public:
    virtual void shareResponse()=0;
    virtual ~Component()=default;
};
class Response: public Component{
    public:
    void shareResponse() override{
        cout<<"sending the response now"<<endl;
    }
};
class Decorator : public Component{
    protected:
    unique_ptr<Component>components;
    public:
    Decorator(unique_ptr<Component>comp):components(move(comp)){}
    virtual ~Decorator()=default;
};
class Caching: public Decorator{
    public:
    Caching(unique_ptr<Component>component):Decorator(move(component)){}
    void shareResponse() override{
        components->shareResponse();
        cout<<"caching the respone"<<endl;
    }
};
class Encryption: public Decorator{
    public:
    Encryption(unique_ptr<Component>comp): Decorator(move(comp)){}
    void shareResponse() override{
        components->shareResponse();
        cout<<"encrypting the response"<<endl;
    }
};
int main(){
    unique_ptr<Component>createResponse = make_unique<Response>();
    createResponse= make_unique<Caching>(move(createResponse));
    createResponse= make_unique<Encryption>(move(createResponse));
    createResponse->shareResponse();
}