#include<iostream>
using namespace std;
class SubsystemA{
    public:
    void operation(){
        //code block
    }
};
class SubSystemB{
    public:
    void operation(){
        //code block
    }
};
class SubsystemC{
    public:
    void operation(){
        //code block
    }
};
class FacadeSystem{
    SubsystemA a;
    SubSystemB b;
    SubsystemC c;
    public:
    void operation(){
        a.operation();
        b.operation();
        c.operation();
    }
};
int main(){
    FacadeSystem facade;
    facade.operation();
}