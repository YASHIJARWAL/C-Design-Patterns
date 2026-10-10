#include<iostream>
#include <memory>
using namespace std;



class Subject{
    
    public:

    virtual void operation()=0;

    virtual ~Subject()=default;
};



class RealSubject:public Subject{
    public:
    void operation() override{
        cout<<"real subject"<<endl;
    }
};



class Proxy: public Subject{

    unique_ptr<Subject>realSubject;

    public:

    Proxy():realSubject(move(nullptr)){}

    void operation() override{

        if(realSubject==nullptr){
            realSubject=make_unique<RealSubject>();
        }

        realSubject->operation();

        cout<<"proxy completed operation"<<endl;

    }
    
};
int main(){
    unique_ptr<Subject>subject = make_unique<Proxy>();
    subject->operation();

}