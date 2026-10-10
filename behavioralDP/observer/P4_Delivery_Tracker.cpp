#include <algorithm>
#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Observer{
    public:
    virtual void update(string status)=0;
};
class DeliveryHO{
    private:
    vector<Observer*>obs;
    public: 
    void subscribe(Observer*observer){
        obs.push_back(observer);
    }
    void unsubscribe(Observer*observer){
        obs.erase(remove(obs.begin(), obs.end(), observer),obs.end());
    }
    void notify(Observer*customer,string status){
        for(Observer*observer:obs){
            observer->update(status);
        }
    }
};
class Customer: public Observer{
    private:
    string name;
    public:
    void setName(string name){
        this->name = name;
    }
    void update(string status) override{
        cout<<"Hi "<<this->name<<" The status is changed to: "<<status<<endl;
    }

};
int main(){
    Customer Yash;
    Customer Shaurya;
    DeliveryHO Amazon;
    Yash.setName("Yash");
    Shaurya.setName("Shaurya");
    Amazon.subscribe(&Yash);
    Amazon.notify(&Yash, "SHIPPED");
    Amazon.subscribe(&Shaurya);
    Amazon.notify(&Shaurya, "CONFIRMED");
}