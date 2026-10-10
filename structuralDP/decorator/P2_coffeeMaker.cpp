#include<iostream>
#include <memory>
using namespace std;
class BaseComponent{
    protected:
    string name;
    public:
    virtual void setName(string name){
        this->name= name;
    }
    virtual void add()=0;
    virtual ~BaseComponent()=default;
};
class Coffee: public BaseComponent{
    void add() override{
        cout<<"adding freshly cultivated coffee beans to your: "<<this->name<<endl;
    }
};
class Compliments: public BaseComponent{
    protected:
    unique_ptr<BaseComponent>component;
    public:
    Compliments(unique_ptr<BaseComponent>component):component(std::move(component)){}
    void setName(string name)override{
        this->name = name;
        component->setName(name);
    }
    virtual ~Compliments()=default;

};
class Milk : public Compliments{
    public:
    Milk(unique_ptr<BaseComponent>component):Compliments(std::move(component)){}
    void add() override{
        component->add();
        cout<<"added fresh low fat Milk to your: "<<this->name<<endl;
    }
};
class Water: public Compliments{
    public:
    Water(unique_ptr<BaseComponent>component):Compliments(std::move(component)){}
    void add() override{
        component->add();
        cout<<"adding water to your: "<<this->name<<endl;
    }
};
class WhipCream: public Compliments{
    public:
    WhipCream(unique_ptr<BaseComponent>component):Compliments(std::move(component)){}
    void add() override{
        component->add();
        cout<<"adding whip cream to your: "<<this->name<<endl;
    }
};

int main(){
    unique_ptr<BaseComponent>latte = make_unique<Coffee>();
    latte = make_unique<Milk>(std::move(latte));
    latte = make_unique<Water>(std::move(latte));
    latte->setName("latte");
    latte->add();
    unique_ptr<BaseComponent>frappe = make_unique<Coffee>();
    frappe = make_unique<Milk>(std::move(frappe));
    frappe = make_unique<Water>(std::move(frappe));
    frappe = make_unique<WhipCream>(std::move(frappe));
    frappe->setName("frappe");
    frappe->add();

}