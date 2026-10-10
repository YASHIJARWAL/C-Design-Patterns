#include<iostream>
#include <memory>
using namespace std;
class Product{
    public:
    virtual void prodJob()=0;
};
class ProductA:public Product{
    public:
    virtual void prodJobA()=0;
    void prodJob() override{
        cout<<"prodjob working"<<endl;
    }
};
class ProductA1: public ProductA{
    public:
    void prodJobA() override{
        cout<<"prodjob A1 working"<<endl;
        this->prodJob();
    }
};
class ProductA2 : public ProductA{
    public:
    void prodJobA() override{
        cout<<"prodjob A2 working"<<endl;
        this->prodJob();
    }
};
class ProductB:public Product{
    public:
    virtual void prodJobB()=0;
    void prodJob() override{
        cout<<"prodjob working"<<endl;
    }
};
class ProductB1: public ProductB{
    public:
    void prodJobB() override{
        cout<<"prodjob B1 is working"<<endl;
        this->prodJob();
    }
};
class ProductB2: public ProductB{
    public:
    void prodJobB() override{
        cout<<"prodjob B2 is working"<<endl;
        this->prodJob();
    }
};
class Creator{
    public:
    virtual unique_ptr<ProductA>ProdA()=0;
    virtual unique_ptr<ProductB>ProdB()=0;
    void execute(){
        ProdA()->prodJobA();
        ProdB()->prodJobB();
    }
};
class CreatorA: public Creator{
    public:
    unique_ptr<ProductA> ProdA() override{
        return make_unique<ProductA1>();
    }
    unique_ptr<ProductB> ProdB() override{
        return make_unique<ProductB1>();
    }
};
class CreatorB: public Creator{
    public:
    unique_ptr<ProductA> ProdA() override{
        return make_unique<ProductA2>();
    }
    unique_ptr<ProductB> ProdB() override{
        return make_unique<ProductB2>();
    }
};

int main(){
    unique_ptr<CreatorA>createA = make_unique<CreatorA>();
    unique_ptr<CreatorB>createB = make_unique<CreatorB>();
    createA->execute();
    createB->execute();
}