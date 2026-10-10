#include<iostream>
using namespace std;

class Template{
    public: 
    virtual void step1()=0;
    virtual void step2()=0;
    virtual void step3()=0;
    virtual void step4()=0;
    void templateMethod(){
        step1();
        step2();
        step3();
        step4();
    }
};
class ConcreteTemplate:public Template{
    void step1() override{
        cout<<"perform step 1"<<endl;
    }
    void step2() override{
        cout<<"perform step 2"<<endl;
    }
    void step3() override{
        cout<<"perform step 3"<<endl;
    }
    void step4() override{
        cout<<"perform step 4"<<endl;
    }
};

int main(){
    ConcreteTemplate template1;
    template1.templateMethod();
}