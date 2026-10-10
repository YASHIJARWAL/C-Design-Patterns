#include<iostream>
using namespace std;
class Computer{
    int ram;
    string processor;
    int storage;
    bool graphicCard;
    public:
    void setProcessor(string pro){
        this->processor = pro;
    }
    void setGC(bool gc){
        this->graphicCard=gc;
    }
    void setRam(int space){
        this->ram = space;
    }
    void setStorage(int store){
        this->storage = store;
    }
    void show(){
        cout<<"space: "<<this->storage<<endl;
        cout<<"ram: "<<this->ram<<endl;
        cout<<"GC: "<<this->graphicCard<<endl;
        cout<<"processor: "<<this->processor<<endl;
    }
};
class Builder{
    public:
    virtual void BuildRam()=0;
    virtual void BuildProc()=0;
    virtual void BuildGC()=0;
    virtual void BuildStore()=0;
    virtual Computer* returnProd()=0;
};
class CompBuilder:public Builder{
    Computer *computer;
    public:
    CompBuilder(){
        this->computer = new Computer();
    }
    void BuildGC() override{
        computer->setGC(true);
    }
    void BuildProc() override{
        computer->setProcessor("intel");
    }
    void BuildStore() override{
        computer->setStorage(256);
    }
    void BuildRam() override{
        computer->setRam(64);
    }
    Computer* returnProd() override{
        return computer;
    }
};
class StudyLaptopBuilder: public Builder{
    Computer * computer;
    public: 
    StudyLaptopBuilder(){
        this->computer = new Computer();
    }
    void BuildGC() override{
        computer->setGC(false);
    }
    void BuildRam() override{
        computer->setRam(16);
    }
    void BuildProc() override{
        computer->setProcessor("AMD");
    }
    void BuildStore() override{
        computer->setStorage(256);
    }
    Computer * returnProd() override{
        return this->computer;
    }
};
class Director{
    public:
    void construct(Builder *builder){
        builder->BuildProc();
        builder->BuildRam();
        builder->BuildStore();
        builder->BuildGC();
    }
};
int main(){
    Director director;
    CompBuilder  builder;
    StudyLaptopBuilder studyLaptopBuilder;
    director.construct(&builder);
    director.construct(&studyLaptopBuilder);
    Computer * comp = builder.returnProd();
    Computer *studyComp= studyLaptopBuilder.returnProd();
    comp->show();
    studyComp->show();
    

}