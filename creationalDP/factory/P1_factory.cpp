#include<iostream>
#include <memory>
using namespace std;

class Product{
    public:
    virtual void setName(string name)=0;
    virtual string getName()=0;
};
class ProductA: public Product{
    string name;
    public:
    void setName(string name) override{
        this->name = name;
    }
    string getName()override{
        return name;
    }

};
class ProductB: public Product{
    string name;
    public:
    void setName(string name) override{
        this->name = name;
    }
    string getName() override{
        return  name;
    }

};
class Creator{
    string name;
    public: 
    virtual unique_ptr<Product>listProd()=0;
    void execute(){
        auto prod = listProd();
        cin>>name;
        prod->setName(name);
        cout<<prod->getName()<<endl;
    }
};
class CreatorA: public Creator{
    public:
    unique_ptr<Product> listProd() override{
        return make_unique<ProductA>();
    };
};
class CreatorB: public Creator{
    public:
    unique_ptr<Product> listProd() override{
        return make_unique<ProductB>();
    }
};

int main(){
    unique_ptr<Creator>creatorA = make_unique<CreatorA>();
    unique_ptr<Creator>creatorB = make_unique<CreatorB>();
    creatorA->execute();
    creatorB->execute();
}