#include<iostream>
#include <memory>
using namespace std;
class Target{
    public:
    virtual void request()=0;
    virtual ~Target()=default;
};
class Adaptee{
    public:
    void specialRequest(){
        cout<<"this is a special request"<<endl;
    }
};
class Adapter:public Target{
    unique_ptr<Adaptee>adaptees;
    public:
    Adapter(unique_ptr<Adaptee>adaptees):adaptees(move(adaptees)){}
    void request() override{
        adaptees->specialRequest();

    }
};
class Client{
    public:
    void execute(Target &target){
        target.request();
    }
};
int main(){
    auto adaptees= make_unique<Adaptee>();
    Adapter adapter(move(adaptees));
    Client Client;
    Client.execute(adapter);

}