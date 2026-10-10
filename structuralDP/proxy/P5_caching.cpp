#include <iostream>
#include <memory>
using namespace std;
class DataService{
    protected:
    int id;
    public:
    virtual void setId(int id){
        this->id= id;
    }
    virtual void operation()=0;
    virtual ~DataService()=default;
};
class RealDataService: public DataService{
    public:
    void operation() override{
        cout<<"this is an expensive operation"<<endl;
    }
};
class ProxyDataService: public DataService{
    unique_ptr<DataService>service;
    int id;
    public:
    ProxyDataService():service(nullptr){}
    void operation() override{
        if(service==nullptr){
            cin>>id;
            service = make_unique<RealDataService>();
            service->setId(id);
        }
        if(id){
            service->operation();
        }
        cout<<"proxy check completed"<<endl;
    }
};
int main(){
    unique_ptr<DataService>service = make_unique<ProxyDataService>();
    service->operation();
}