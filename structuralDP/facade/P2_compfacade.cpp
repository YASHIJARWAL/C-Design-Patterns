#include<iostream>
using namespace std;
class Disc{
    public:
    void start(){
        cout<<"loading disc"<<endl;
    }
};
class Memory{
    public:
    void start(){
        cout<<"loading memory"<<endl;
    }
};
class CPU{
    public:
    void start(){
        cout<<"booting the system"<<endl;
    }
};
class CompFacade{
    CPU c;
    Memory m; 
    Disc d;
    public:
    void startSystem(){
        c.start();
        m.start();
        d.start();
    }
};
int main(){
    CompFacade comp;
    comp.startSystem();
}