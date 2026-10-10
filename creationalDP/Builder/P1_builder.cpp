#include<iostream>
#include <string>
using namespace std;
class Product{
    string partA;
    string partB;
    string partC;
    public:
    void setPartA(string partA){
        this->partA = partA;
    }
    void setPartB(string partB){
        this->partB = partB;
    }
    void setPartC(string partC){
        this->partC=partC;
    }
    void show(){
        cout<<"part A:"<<this->partA<<endl;
        cout<<"part B:"<<this->partB<<endl;
        cout<<"part C:"<<this->partC<<endl;
    }
};
class Builder{
    public:
    virtual void buildPartA()=0;
    virtual void buildPartB()=0;
    virtual void buildPartC()=0;
    virtual Product *prod()=0;
    virtual ~Builder()=default;
};
class ConcreteBuilder:public Builder{
    private:
    Product*product;
    public:
    ConcreteBuilder(){
        product = new Product();
    }
    void buildPartA() override{
        string partA;
        cin>>partA;
        product->setPartA(partA);
    }
    void buildPartB() override{
        string partB;
        cin>>partB;
        product->setPartB(partB);
    }
    void buildPartC() override{
        string partC;
        cin>>partC;
        product->setPartC(partC);
    }
    Product * prod() override{
        return product;
    }
};
class Director{
    public:
    void construct(Builder * builder){
        builder-> buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};
int main(){
    ConcreteBuilder builder;
    Director director;
    director.construct(&builder);
    Product * product = builder.prod();
    product->show();
}