#include <cstdio>
#include<iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class NetworkDevice{
    public:
    virtual void sendPacket()=0;
    virtual string type()=0;
    virtual ~NetworkDevice()=default;
};
class NetworkGroup: public NetworkDevice{
    string name;
    vector<shared_ptr<NetworkDevice>>devices;
    public:
    NetworkGroup(string name){
        this->name = name;
    }
    string type() override{
        return "Net group";
    }
    void add(shared_ptr<NetworkDevice>device){
        devices.push_back(device);
    }
    void delServerEl(shared_ptr<NetworkDevice>device){
        devices.erase(remove(devices.begin(),devices.end(),device),devices.end());
    }
    void sendPacket() override{
        cout<<"sending package for network group:"<<this->name<<endl;
        for(auto it: devices){
            it->sendPacket();
        }
        cout<<"package sent for network group: "<<this->name<<endl;
    }
};
class Router: public NetworkDevice{
    string name;
    public:
    Router(string name){
        this->name = name;
    }
    string type() override{
        return "router";
    }
    void sendPacket() override{
        cout<<"package sent to router: "<<this->name<<endl;
    }
};
class Server: public NetworkDevice{
    string name;
    vector<shared_ptr<NetworkDevice>>devices;
    public:
    Server(string name){
        this->name = name;
    }
    string type() override{
        return "server";
    }
    void add(shared_ptr<NetworkDevice>device){
        if(device->type()=="Net group"){
            cout<<"sorry can't add this entity"<<endl;
        }
        else{
            devices.push_back(device);
        }
    }
    void delServerEl(shared_ptr<NetworkDevice>device){
        devices.erase(remove(devices.begin(),devices.end(),device),devices.end());
    }
    void sendPacket() override{
        cout<<"sending package for server:"<<this->name<<endl;
        for(auto it: devices){
            it->sendPacket();
        }
        cout<<"package sent for server: "<<this->name<<endl;
    }
};

int main(){
    auto server1 = make_shared<Server>("Belfast Server");
    auto server2 = make_shared<Server>("Delhi Server");
    auto server3 = make_shared<Server>("Bangalore");
    auto NetworkGroup1 = make_shared<NetworkGroup>("India group");
    auto NetworkGroup2 = make_shared<NetworkGroup>("Ireland group");
    auto NetworkGroup3 = make_shared<NetworkGroup>("South India group");
    auto NetworkGroup4 = make_shared<NetworkGroup>("Australia group");
    auto Router1 = make_shared<Router>("BSNL router");
    auto Router2 = make_shared<Router>("Ireland Mobiles router");
    NetworkGroup2->add(server1);
    server1->add(Router2);
    NetworkGroup1->add(NetworkGroup3);
    NetworkGroup1->add(server2);
    server2->add(Router1);
    server2->add(NetworkGroup4);
    NetworkGroup3->add(server3);
    NetworkGroup1->sendPacket();
    NetworkGroup2->sendPacket();
}