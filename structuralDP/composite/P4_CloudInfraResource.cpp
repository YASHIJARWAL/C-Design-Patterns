#include<iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

class InfraItems{
    protected:
    string name;
    public:
    string getName(){
        return this->name;
    }
    virtual void setName(string name)=0;
    virtual double getCost()=0;
    virtual int getResourceCount()=0;
    virtual ~InfraItems()=default;
};

class VM : public InfraItems{
    public:
    void setName(string name) override{
        this->name = name;
    }
    double getCost() override{
        return 8.47;
    }
    int getResourceCount() override{
        return 1;
    }
};

class Database: public InfraItems{
    public:
    void setName(string name) override{
        this->name = name;
    }
    double getCost() override{
        return 64.22;
    }
    int getResourceCount() override{
        return 1;
    }
};

class CloudResource: public InfraItems{
    public:
    void setName(string name) override{
        this->name = name;
    }
    double getCost() override{
        return 322.12;
    }
    int getResourceCount() override{
        return 1;
    }

};

class LoadBalancer : public InfraItems{
    public:
    void setName(string name) override{
        this->name = name;
    }
    double getCost() override{
        return 66.44;
    }
    int getResourceCount() override{
        return 1;
    }
};

class ResourceGroup: public InfraItems{
    private:
    vector<shared_ptr<InfraItems>> components;
    int flag =0 ;
    string name;
    public:
    void setName(string name) override{
        this->name= name;
    }
    void removeEl(shared_ptr<InfraItems>item){
        components.erase(remove(components.begin(),components.end(),item),components.end());
    }
    void add(shared_ptr<InfraItems>item){
        components.push_back(item);
    }
    void searchEl(shared_ptr<InfraItems>item){
        for(shared_ptr<InfraItems>component:components){
            if(component==item){
                cout<<item->getName()<<" found"<<endl;
                flag=1;
            }
        }
        if(flag == 0){
            cout<<"element unavailable"<<endl;
        }

    }
    int getResourceCount() override{
        int resource =0 ;
        for(auto&component: components){
            resource+=component->getResourceCount();
        }
        return resource;
    }
    double getCost() override{
        double cost =0;
        for(auto&component: components){
            cost+=component->getCost();
        }
        return cost;
    }
};

int main(){
    auto vm = make_shared<VM>();
    auto loadBalancer=make_shared<LoadBalancer>();
    auto database = make_shared<Database>();
    auto cloudResource= make_shared<CloudResource>(); 
    auto resourceGroup=make_shared<ResourceGroup>();
    vm->setName("virtual machine");
    loadBalancer->setName("load balancer");
    cloudResource->setName("cloud resource");
    database->setName("database");
    resourceGroup->setName("resource group");
    resourceGroup->add(vm);
    resourceGroup->add(loadBalancer);
    resourceGroup->add(database);
    resourceGroup->add(cloudResource);
    double cost = resourceGroup->getCost();
    cout<<"cost of resource group: $"<< cost<<endl;
    int count=resourceGroup->getResourceCount();
    cout<<"count : "<<count<<endl;
    resourceGroup->searchEl(loadBalancer);
    resourceGroup->removeEl(database);
    double cost1 = resourceGroup->getCost();
    cout<<"cost of resource group: $"<< cost1<<endl;
    int count1=resourceGroup->getResourceCount();
    cout<<"count : "<<count1<<endl;
}
