#include<iostream>
#include <memory>
using namespace std;
class Service{
    public:
    virtual void operation()=0;
    virtual ~Service()=default;
};
class RealService: public Service{
    public:
    void operation() override{
        cout<<"providing services"<<endl;
    }
};
class ProxyService: public Service{
    unique_ptr<Service>service;
    public:
    ProxyService():service(move(nullptr)){}
    void operation() override{
        if(service==nullptr){
            service = make_unique<RealService>();
        }
        service->operation();
        cout<<"proxy check is completed"<<endl;

    }
};
int main(){
    unique_ptr<ProxyService>service = make_unique<ProxyService>();
    service->operation();
}